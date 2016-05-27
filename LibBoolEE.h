#include "shared_export_def.h"

extern "C" {
    struct SHARED_EXPORT LibBoolEEVal {
        char * name;
        bool value;
    };

    // The C interface to LibBoolEE
    bool SHARED_EXPORT LibBoolEEResolve(const char * source, const LibBoolEEVal * const vals, const int len);
}
