#include "error.h"
#include <stdio.h>

char *mystrerr(int errnum)
{
    switch (errnum)
    {
        case BAD_INPUT:
            return STR_BAD_FILE;
        case NULL_POINTER_EXC:
            return STR_NULL_POINTER;
        case EMPTY_FILE:
            return STR_EMPTY_FILE;
        case INVALID_PATH:
            return STR_INVALID_PATH;
        case FILE_READING_FAILED:
            return STR_FILE_READING_FAILED;
        case BAD_ARGS:
            return STR_BAD_ARGS;
        case TOO_MANY_ARGV:
            return STR_TOO_MANY_ARGV_GIVEN;
    }

    return "No such proccess";
}

void myperror(const char *err, const int errnum)
{
    fprintf(stderr, "%s. Error: %d\n", err, errnum);
}
