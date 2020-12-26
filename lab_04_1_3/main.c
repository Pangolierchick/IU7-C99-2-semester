#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystring.h"

#define FAILED 1

#define ZERO_LEN 0
#define ONE_WORD 1


int main(void)
{
    char str[MAX_STR_SIZE + 1];
    char table[MAX_WORDS_COUNT][MAX_WORD_SIZE];
    
    if (INPUT_STR(str) == NULL)
    {
        my_perror(mystrerror(INPUT_FAILED), INPUT_FAILED);
        return INPUT_FAILED_EXC;
    }

    if (strlen(str) > MAX_STR_SIZE - 1)
    {
        my_perror(mystrerror(TOO_LONG_STR), TOO_LONG_STR);
        return MAX_STR_SIZE_EXC;
    }

    int words = split(table, str);
    
    if (words <= 1)
    {
        my_perror(mystrerror(words), words);
        return SPLIT_ERROR;
    }

    char task_str[MAX_STR_SIZE] = { 0 };


    int words_len = strform(table, task_str, words);

    if (words_len == 0)
    {
        my_perror(mystrerror(ZERO_LEN_AFTER_TRANSFORM), ZERO_LEN_AFTER_TRANSFORM);
        return ZERO_LEN_EXC;
    }

    printf("Result: %s\n", task_str);
    return SUCCESS;
}
