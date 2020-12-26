#include <stdio.h>
#include <string.h>
#include "mystring.h"

char *mystrerror(int error_num)
{
    switch (error_num)
    {
        case ONE_WORD:
        case ZERO_LEN:
            return STR_ZERO_LEN_ERROR;
        case TOO_LONG_WORD_EXC: 
            return STR_TOO_LONG_WORD;
        case INPUT_FAILED:
            return STR_INPUT_FAILED;
        case TOO_LONG_STR:
            return STR_TOO_LONG_STRING;
        case ZERO_LEN_AFTER_TRANSFORM:
            return STR_WORDS_DELETED;
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

int split(char (*dst)[MAX_WORD_SIZE], const char *src)
{
    char s[MAX_STR_SIZE];

    mystrlcpy(s, src, MAX_STR_SIZE);
    
    char (*d)[MAX_WORD_SIZE] = dst;

    const char *sep = ".,:;!?-\n ";

    int words = 0;
    char *lexem = strtok(s, sep);
        
    while (lexem != NULL)
    {
        if (strlen(lexem) > MAX_WORD_SIZE - 1)
            return TOO_LONG_WORD_EXC;
    
        mystrlcpy(d[words], lexem, MAX_WORD_SIZE);

        words++;
        lexem = strtok(NULL, sep);
    }
    
    return words;
}

int strsetch(const char *str, char *dst)
{
    const char *pstr = str;
    char *pdst = dst;

    unsigned char table[256] = { 0 };

    while (*pstr)
    {
        if (table[(unsigned char) *pstr] == 0)
        {
            table[(unsigned char) *pstr] = 1;
            *pdst = *pstr;
            pdst++;
        }
        pstr++;
    }
    *pdst = '\0';

    return (pdst - dst - 1);
}

int strform(char (*src)[MAX_WORD_SIZE], char *dst, const int words)
{
    char (*psrc)[MAX_WORD_SIZE] = src;
    char *pdst = dst;

    const char *last_word = psrc[words - 1];
    char uniqch[MAX_WORD_SIZE];
    int real_words = 0;

    for (int i = words - 2; i >= 0; i--)
    {
        if (strncmp(last_word, psrc[i], MAX_WORD_SIZE) != 0)
        {
            strsetch(psrc[i], uniqch);
            strcat(pdst, uniqch);
            strcat(pdst, i == 0 ? "" : " ");
            real_words++;
        }
    }
    return real_words;
}
