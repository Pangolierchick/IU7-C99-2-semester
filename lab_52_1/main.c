#include <stdio.h>

#include "funcs.h"
#include "error.h"

int main(int argc, char **argv)
{
    int res = parse_args(argc, argv);
    if (res)
    {
        PRINT_ERR(res);
        return res;
    }

    return SUCCESS;
}
