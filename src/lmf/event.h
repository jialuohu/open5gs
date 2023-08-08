
#ifndef LMF_EVENT_H
#define LMF_EVENT_H

#include "ogs-proto.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct lmf_event_s {
    // ! Only one member?
    ogs_event_t h;
} lmf_event_t;

OGS_STATIC_ASSERT(OGS_EVENT_SIZE >= sizeof(lmf_event_t));

lmf_event_t *lmf_event_new(int id);

const char *lmf_event_get_name(lmf_event_t *e);

#ifdef __cplusplus
}
#endif

#endif /* LMF_EVENT_H */
