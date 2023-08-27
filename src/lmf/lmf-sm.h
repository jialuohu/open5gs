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

#define lmf_sm_debug(__pe) \
    ogs_debug("%s(): %s", __func__, lmf_event_get_name(__pe))

#ifdef __cplusplus
}
#endif

#endif /* LMF_SM_H */
