#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include <string.h>
#include <stdlib.h>

#define MAX_STR_SIZE 257
#define MAX_WORDS_COUNT 128
#define MAX_WORD_SIZE 17

#define ZERO_LEN_EXC 1
#define TOOLONGWORDEXC 2
#define ONE_WORD_EXC 3
#define MAX_STR_SIZE_EXC 4
#define INPUT_FAILED_EXC 5

#define SPLIT_ERROR                    10

#define ZERO_LEN_AFTER_TRANSFORM        5
#define ZERO_LEN                        0
#define ONE_WORD                        1
#define TOO_LONG_WORD_EXC              -2
#define INPUT_FAILED                    3
#define TOO_LONG_STR                    7

#define STR_ZERO_LEN_ERROR    "No words have been given"
#define STR_INPUT_FAILED      "Input string failed."
#define STR_TOO_LONG_STRING   "Too long string (max size: 256)"
#define STR_TOO_LONG_WORD     "Too long word given (max size: 16)"
#define STR_WORDS_DELETED     "All words were deleted"

#define SUCCESS 0

#define INPUT_STR(str) fgets(str, MAX_STR_SIZE + 1, stdin)

char *mystrerror(int error_num);
void my_perror(const char *err, const int errnum);

int mystrlcpy(char *dst, const char *src, size_t size);
int split(char (*dst)[MAX_WORD_SIZE], const char *src);
int strsetch(const char *str, char *dst);
int strform(char (*src)[MAX_WORD_SIZE], char *dst, const int words);
#endif // __MYSTRING_H__
