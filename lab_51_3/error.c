#include "error.h"
#include <stdio.h>

char *mystrerr(int errnum)
{
    switch (errnum)
    {
        case ERROR_FOUND:
            return STR_ERROR_FOUND;
        case UNKNOWN_OP:
            return STR_UNKNOWN_OP;
        case FILE_CREATION_FAILED:
            return STR_FILE_CREATION_FAILED;
        case FILE_PRINT_FAILED:
            return STR_FILE_PRINT_FAILED;
        case FILE_SORT_FAILED:
            return STR_FILE_SORT_FAILED;
    }

    return "No such proccess";
}

void myperror(const char *err, const int errnum)
{
    fprintf(stderr, "%s. Error: %d\n", err, errnum);
}
