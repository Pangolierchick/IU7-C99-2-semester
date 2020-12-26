#ifndef __MY_STRING_H__
#define __MY_STRING_H__

#include <string.h>
#include <stdbool.h>

#define MIN(A, B) A < B ? A : B

#define PRINT(str, len) {for (int i = 0; i < len; i++)\
                        {                               \
                            printf("%s", str[i]);      \
                            if (i < len - 1)           \
                                printf(" ");            \
                        }                               \
                        printf("\n");}

#define MAX_STR_SIZE    257
#define MAX_WORDS_COUNT 128
#define MAX_WORD_SIZE    17

#define ZERO_LEN            0
#define SPLIT_ERROR         6
#define ZERO_LEN_EXC_CODE   1
#define TOO_LONG_WORD_EXC   -2
#define INPUT_FAILED        3
#define TOO_LONG_STR        7
#define MAX_STR_SIZE_EXC    4

#define STR_ZERO_LEN_ERROR    "No words have been given"
#define STR_INPUT_FAILED      "Input string failed."
#define STR_TOO_LONG_STRING   "Too long string (max size: 256)"
#define STR_TOO_LONG_WORD     "Too long word given (max size: 16)"


#define INPUT_STR(str) fgets(str, MAX_STR_SIZE + 1, stdin)

#define SUCCESS 0

int strsplit(const char *str, char (*src)[MAX_WORD_SIZE]);
bool findchar(const char *str, const char ch, const size_t glen);
void replace(char *str, const size_t glen);

char *mystrerror(int error_num);
void my_perror(const char *err, const int errnum);

int mystrncmp(const char *s1, const char *s2, size_t size);
bool strfind(char (*src)[MAX_WORD_SIZE], const char *key, const int len);
int mystrlcpy(char *dst, const char *src, size_t size);
size_t mystrnlen(const char *str, const size_t size);

#endif // __MY_STRING_H__
