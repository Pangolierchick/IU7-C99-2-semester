#include <stdio.h>
#include "my_strcspn.h"

#define TRUE 1
#define FALSE 0 

int findchar(const char *str, const char ch)
{
    int rc = FALSE;

    while (!(rc = *str == ch) && *str++);

    return rc;
}

size_t my_strcspn(const char *str, const char *reject)
{
    size_t i = 0;

    while (str[i] != '\0')
    {
        if (findchar(reject, str[i]))
            break;
        i++;
    }

    return i;
}
