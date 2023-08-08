#ifndef LMF_SM_H
#define LMF_SM_H

#include "event.h"

#ifdef __cplusplus
extern "C" {
#endif

// TODO Need implementation on type "lmf_event_t" in "event.h"
void lmf_state_initial(ogs_fsm_t *s, lmf_event_t *e);
void lmf_state_final(ogs_fsm_t *s, lmf_event_t *e);
void lmf_state_operational(ogs_fsm_t *s, lmf_event_t *e);

// ! Not sure I need to implement them all.
// ! can't find them in any other files.
/*
void lmf_nf_fsm_init(ogs_sbi_nf_instance_t *nf_instance);
void lmf_nf_fsm_fini(ogs_sbi_nf_instance_t *nf_instance);

void lmf_nf_state_initial(ogs_fsm_t *s, lmf_event_t *e);
void lmf_nf_state_final(ogs_fsm_t *s, lmf_event_t *e);
void lmf_nf_state_will_register(ogs_fsm_t *s, lmf_event_t *e);
void lmf_nf_state_registered(ogs_fsm_t *s, lmf_event_t *e);
void lmf_nf_state_de_registered(ogs_fsm_t *s, lmf_event_t *e);
void lmf_nf_state_exception(ogs_fsm_t *s, lmf_event_t *e);
*/

// TODO Need implementation on function "lmf_event_get_name()" in "event.c".
#define lmf_sm_debug(__pe) \
    ogs_debug("%s(): %s", __func__, lmf_event_get_name(__pe))

#ifdef __cplusplus
}
#endif

#endif /* LMF_SM_H */
