#ifndef __ERROR_H__
#define __ERROR_H__

#include <stdio.h>
#include "funcs.h"

#define STR_INVALID_PATH                "Invalid path to file given."
#if TESTS
#define STR_SUPER_SECRET_SUCCESSED      "Super secret command successed."
#endif
#define STR_UNKNOWN_CMD                 "Unknown command given."
#define STR_EMPTY_FILE                  "Empty file given."

#define UNKNOWN_CMD                       53
#define EMPTY_FILE                        3
#define INVALID_PATH                      2
#define FAILED                            1
#if TESTS
#define SUPER_SECRET_SUCCESSED          100
#endif

#if TESTS
#define PRINT_ERR(errnum) fprintf(stderr, "%s\n", mystrerror(errnum))
#else
#define PRINT_ERR(errnum) 
#endif

char *mystrerror(int errnum);

#endif //__ERROR_H__