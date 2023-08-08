// ! Added two declaration functions in "ogs-app.h"
#include "ogs-app.h"

int app_initialize(const char *const argv[])
{

    int rv;
    // ? How does c compiler knows where is the function?
    // ! Noticed that in the file "ogs-app.h", it has other NF init declarations.
    rv = lmf_initialize();
    if (rv != OGS_OK) {
        ogs_error("Failed to initialize LMF");
        return rv;
    }
    ogs_info("LMF initialize...done");

    return OGS_OK;
}

void app_terminate(void)
{
    lmf_terminate();
    ogs_info("lmf terminate...done");
}