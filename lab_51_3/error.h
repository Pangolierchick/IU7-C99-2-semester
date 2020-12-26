#ifndef __ERROR_H__
#define __ERROR_H__

#define STR_UNKNOWN_OP  "Unknown command given. Exiting"
#define STR_ERROR_FOUND "An error occured. Exiting"
#define STR_FILE_CREATION_FAILED "File creation failed. Exiting"
#define STR_FILE_PRINT_FAILED "File print failed"
#define STR_FILE_SORT_FAILED "Sort file failed"


#define SUCCESS                  0
#define ERROR_FOUND             -1
#define UNKNOWN_OP              -2
#define FILE_CREATION_FAILED    -3
#define FILE_PRINT_FAILED       -4
#define FILE_SORT_FAILED        -5


#define PRINT_ERROR(errnum) myperror(mystrerr(errnum), errnum)

char *mystrerr(int errnum);
void myperror(const char *err, const int errnum);


#endif // __ERROR_H__
