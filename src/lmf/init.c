/**
 * This file might contain functions related to initializing the Location Management Function.
 * It includes setup routines, memory allocation, and other tasks required to start the LMF.
*/
#include "sbi-path.h"

static ogs_thread_t *thread;
static void lmf_main(void *data);
static int initialized = 0;

int lmf_initialize(void)
{
    int rv;

    ogs_sbi_context_init(OpenAPI_nf_type_LMF);
    lmf_context_init();

    rv = ogs_sbi_context_parse_config("lmf", "nrf", "scp");
    if (rv != OGS_OK) return rv;

    rv = lmf_context_parse_config();
    if (rv != OGS_OK) return rv;

    rv = ogs_log_config_domain(
            ogs_app()->logger.domain, ogs_app()->logger.level);
    if (rv != OGS_OK) return rv;

    rv = lmf_sbi_open();
    if (rv != OGS_OK) return rv;

    thread = ogs_thread_create(lmf_main, NULL);
    if (!thread) return OGS_ERROR;

    initialized = 1;

    return OGS_OK;
}

static ogs_timer_t *t_termination_holding = NULL;

static void event_termination(void)
{
    ogs_sbi_nf_instance_t *nf_instance = NULL;

    /* Sending NF Instance De-registeration to NRF */
    ogs_list_for_each(&ogs_sbi_self()->nf_instance_list, nf_instance)
        ogs_sbi_nf_fsm_fini(nf_instance);

    /* Starting holding timer */
    t_termination_holding = ogs_timer_add(ogs_app()->timer_mgr, NULL, NULL);
    ogs_assert(t_termination_holding);
#define TERMINATION_HOLDING_TIME ogs_time_from_msec(300)
    ogs_timer_start(t_termination_holding, TERMINATION_HOLDING_TIME);

    /* Sending termination event to the queue */
    ogs_queue_term(ogs_app()->queue);
    ogs_pollset_notify(ogs_app()->pollset);
}

void lmf_terminate(void)
{
    if (!initialized) return;

    /* Daemon terminating */
    event_termination();
    ogs_thread_destroy(thread);
    ogs_timer_delete(t_termination_holding);

    lmf_sbi_close();

    lmf_context_final();
    ogs_sbi_context_final();
}

static void lmf_main(void *data)
{
    ogs_fsm_t lmf_sm;
    int rv;

    ogs_fsm_init(&lmf_sm, lmf_state_initial, lmf_state_final, 0);

    for ( ;; ) {
        ogs_pollset_poll(ogs_app()->pollset,
                ogs_timer_mgr_next(ogs_app()->timer_mgr));

        /*
         * After ogs_pollset_poll(), ogs_timer_mgr_expire() must be called.
         *
         * The reason is why ogs_timer_mgr_next() can get the corrent value
         * when ogs_timer_stop() is called internally in ogs_timer_mgr_expire().
         *
         * You should not use event-queue before ogs_timer_mgr_expire().
         * In this case, ogs_timer_mgr_expire() does not work
         * because 'if rv == OGS_DONE' statement is exiting and
         * not calling ogs_timer_mgr_expire().
         */
        ogs_timer_mgr_expire(ogs_app()->timer_mgr);

        for ( ;; ) {
            lmf_event_t *e = NULL;

            rv = ogs_queue_trypop(ogs_app()->queue, (void**)&e);
            ogs_assert(rv != OGS_ERROR);

            if (rv == OGS_DONE)
                goto done;

            if (rv == OGS_RETRY)
                break;

            ogs_assert(e);
            ogs_fsm_dispatch(&lmf_sm, e);
            ogs_event_free(e);
        }
    }
done:

    ogs_fsm_fini(&lmf_sm, 0);
}
