#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_string.h"



int myqsortstrcmp(const void *s1, const void *s2)
{
    const char *arg1 = s1;
    const char *arg2 = s2;
    return (strcmp(arg1, arg2));
}

int main(void)
{
    char str[MAX_STR_SIZE + 1];
    
    if (INPUT_STR(str) == NULL)
    {
        my_perror(mystrerror(INPUT_FAILED), INPUT_FAILED);
        return INPUT_FAILED;
    }

    if (mystrnlen(str, MAX_STR_SIZE) > MAX_STR_SIZE - 1)
    {
        my_perror(mystrerror(TOO_LONG_STR), TOO_LONG_STR);
        return MAX_STR_SIZE_EXC;
    }

    char words_array[MAX_WORDS_COUNT][MAX_WORD_SIZE];

    int words = strsplit(str, words_array);
    
    if (words <= 0)
    {
        my_perror(mystrerror(words), words);
        return SPLIT_ERROR;
    }

    qsort(words_array, words, MAX_WORD_SIZE, myqsortstrcmp);

    printf("Result:");
    
    PRINT(words_array, words);
    
    return SUCCESS;
}

