#include <stdio.h>
#include "funcs.h"
#include "error.h"

int main(void)  
{
    int min_dist = 0;

    int status = process(stdin, &min_dist);
    
    if (status < 0)
    {
        // PRINT_ERROR(status);
        return FIND_LOCAL_MAX_FAILED;
    }

    printf("%d\n", min_dist);

    return SUCCESS;
}
