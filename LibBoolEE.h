#include "shared_export_def.h"

extern "C" {
    struct LibBoolEEVal {
        char * name;
        bool value;
    };

    // The C interface to LibBoolEE
    bool LibBoolEEResolve(const char * source, const LibBoolEEVal * const vals, const int len);
}
