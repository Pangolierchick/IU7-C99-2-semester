#ifndef __ERROR_H__
#define __ERROR_H__

#define STR_NO_LOCAL_MAX  "Less than two maxes found."
#define STR_NULL_POINTER  "Invalid pointer given. Exiting"
#define STR_SEEK_FAILED   "Seek failed."
#define STR_FILE_ERROR    "An file error occurred"

#define FILE_ERROR                  -4
#define SEEK_FAILED                 -3
#define NULL_POINTER_EXC            -2
#define NO_LOCAL_MAX                -1
#define SUCCESS                      0
#define FIND_LOCAL_MAX_FAILED        1

#define PRINT_ERROR(errnum) myperror(mystrerr(errnum), errnum);

char *mystrerr(int errnum);
void myperror(const char *err, const int errnum);

#endif // __ERROR_H__
