/*
Using int as standtart type for this task.
Sorting in ascending order with qsort algorithm.
*/


#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include "error.h"


int main(int argc, char *argv[])
{   
    int res = parse_argv(argc, argv);

    if (res < 0)
    {
        // PRINT_ERROR(res);
        return FAILED;
    }
    
    return SUCCESS;
}
