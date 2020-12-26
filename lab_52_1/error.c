#include "error.h"
#include "funcs.h"

char *mystrerror(int errnum)
{
    switch (errnum)
    {
        case INVALID_PATH:
            return STR_INVALID_PATH;
        #if TESTS
        case SUPER_SECRET_SUCCESSED:
            return STR_SUPER_SECRET_SUCCESSED;
        #endif
        case UNKNOWN_CMD:
            return STR_UNKNOWN_CMD;
        case EMPTY_FILE:
            return STR_EMPTY_FILE;
    }

    return "No such process";
}