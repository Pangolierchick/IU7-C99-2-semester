#include "error.h"
#include <stdio.h>

char *mystrerr(int errnum)
{
    switch (errnum)
    {
        case NO_LOCAL_MAX:
            return STR_NO_LOCAL_MAX;
        case NULL_POINTER_EXC:
            return STR_NULL_POINTER;
        case FILE_ERROR:
            return STR_FILE_ERROR;
        case SEEK_FAILED:
            return STR_SEEK_FAILED;
    }

    return "No such proccess";
}

void myperror(const char *err, const int errnum)
{
    fprintf(stderr, "%s. Error: %d\n", err, errnum);
}
