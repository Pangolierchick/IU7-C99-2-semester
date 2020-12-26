#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "my_string.h"

char *mystrerror(int error_num)
{
    switch (error_num)
    {
        case ZERO_LEN:
            return STR_INPUT_FAILED;
        case TOO_LONG_WORD_EXC: 
            return STR_TOO_LONG_WORD;
        case INPUT_FAILED:
            return STR_INPUT_FAILED;
        case TOO_LONG_STR:
            return STR_TOO_LONG_STRING;
    }

    return "No such process";
}

void my_perror(const char *err, const int errnum)
{
    fprintf(stderr, "%s. Error: %d\n", err, errnum);
}

int mystrlcpy(char *dst, const char *src, const size_t size)
{
    size_t i = size;
    char *d = dst;
    const char *s = src; 

    while (i--)
    {
        if ((*d = *s) == 0)
            break;
        s++;
        d++;
    }

    if (i == 0)
    {
        if (size != 0)
            *d = 0;

        while (*s++);
    }

    return (s - src - 1);
}


size_t mystrnlen(const char *str, const size_t size)
{
    size_t len = 0;
    while (*str++ && len < size)
        len++;

    return len;
}


bool strfind(char (*src)[MAX_WORD_SIZE], const char *key, const int len)
{
    for (int i = 0; i < len; i++)
        if (!mystrncmp(src[i], key, MAX_WORD_SIZE))
            return true;
    return false;
}


bool findchar(const char *str, const char ch, const size_t glen)
{
    size_t len = MIN(strlen(str), glen);

    for (size_t i = 0; i < len; i++)
        if (str[i] == ch)
            return true;

    return false;
}


void replacech(char *str, const size_t glen)
{
    const char punct_symb[] = { '.', ',', ':', ';', '?', '!', '-', ' ', '\n', '\0' };

    char *str_p = str;
    size_t len = MIN(mystrnlen(str_p, MAX_STR_SIZE), glen);

    for (size_t i = 0; i < len; i++)
        if (findchar(punct_symb, str_p[i], 10))
            str_p[i] = 0;
}


int strsplit(const char *str, char (*src)[MAX_WORD_SIZE])
{
    char str_p[MAX_STR_SIZE];

    mystrlcpy(str_p, str, MAX_STR_SIZE);
    int len = mystrnlen(str, MAX_STR_SIZE);

    int i = 0;
    int j = 0;
    replacech(str_p, len);

    while (i < len)
    {
        int word_len = 0;

        while (str_p[i + word_len] && (i + word_len < len))
            word_len++;

        if ((word_len < MAX_WORD_SIZE && word_len > 0) && strfind(src, str_p + i, j) == 0)
        {   
            mystrlcpy(src[j], str_p + i, word_len + 1);
            j++;
        }
        else if (word_len >= MAX_WORD_SIZE)
            return TOO_LONG_WORD_EXC;

        i += word_len + 1;
    }

    return j;
}

int mystrncmp(const char *s1, const char *s2, size_t size)
{
    const unsigned char *p1 = (const unsigned char *) s1;
    const unsigned char *p2 = (const unsigned char *) s2;

    unsigned char c1 = *p1;
    unsigned char c2 = *p2;

    while (size--)
    {
        c1 = *p1++;
        c2 = *p2++;

        if (c1 != c2)
            return c1 - c2;
        
        if (c1 == '\0')
            return 0;
    }

    return 0;
}


