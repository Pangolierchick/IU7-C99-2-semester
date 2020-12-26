#ifndef __ERROR_H__
#define __ERROR_H__

#define STR_EMPTY_FILE              "Given file is empty"
#define STR_NULL_POINTER            "Invalid pointer given. Exiting"
#define STR_INVALID_PATH            "Invalid path to file"
#define STR_BAD_FILE                "Given file contains bad symbols"
#define STR_FILE_READING_FAILED     "File reading failed. Exiting"
#define STR_BAD_ARGS                "Invalid argv given. Exiting"
#define STR_TOO_MANY_ARGV_GIVEN     "Too many argv given"

#define SUCCESS                  0
#define NULL_POINTER_EXC         1
#define BAD_INPUT                2
#define EMPTY_FILE               3
#define INVALID_PATH             4
#define FILE_READING_FAILED      5
#define BAD_ARGS                 6
#define TOO_MANY_ARGV            7


#define PRINT_ERROR(errnum) myperror(mystrerr(errnum), errnum)

char *mystrerr(int errnum);
void myperror(const char *err, const int errnum);

#endif // __ERROR_H__
