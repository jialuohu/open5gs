#include "sbi-path.h"

static lmf_context_t self;

int __lmf_log_domain;

static int context_initialized = 0;

void lmf_context_init(void)
{
    ogs_assert(context_initialized == 0);

    /* Initialize LMF context */
    memset(&self, 0, sizeof(lmf_context_t));

    ogs_log_install_domain(&__lmf_log_domain, "lmf", ogs_core()->log.level);

    context_initialized = 1;
}

void lmf_context_final(void)
{
    ogs_assert(context_initialized == 1);

    context_initialized = 0;
}

lmf_context_t *lmf_self(void)
{
    return &self;
}

static int lmf_context_prepare(void)
{
    return OGS_OK;
}

static int lmf_context_validation(void)
{
    return OGS_OK;
}

// TODO Check if it is necessary to be modified
int lmf_context_parse_config(void)
{
    int rv;
    yaml_document_t *document = NULL;
    ogs_yaml_iter_t root_iter;

    document = ogs_app()->document;
    ogs_assert(document);

    rv = lmf_context_prepare();
    if (rv != OGS_OK) return rv;

    ogs_yaml_iter_init(&root_iter, document);
    while (ogs_yaml_iter_next(&root_iter)) {
        const char *root_key = ogs_yaml_iter_key(&root_iter);
        ogs_assert(root_key);
        if (!strcmp(root_key, "lmf")) {
            ogs_yaml_iter_t lmf_iter;
            ogs_yaml_iter_recurse(&root_iter, &lmf_iter);
            while (ogs_yaml_iter_next(&lmf_iter)) {
                const char *lmf_key = ogs_yaml_iter_key(&lmf_iter);
                ogs_assert(lmf_key);
                if (!strcmp(lmf_key, "sbi")) {
                    /* handle config in sbi library */
                } else if (!strcmp(lmf_key, "service_name")) {
                    /* handle config in sbi library */
                } else if (!strcmp(lmf_key, "discovery")) {
                    /* handle config in sbi library */
                } else
                    ogs_warn("unknown key `%s`", lmf_key);
            }
        }
    }

    rv = lmf_context_validation();
    if (rv != OGS_OK) return rv;

    return OGS_OK;
}
