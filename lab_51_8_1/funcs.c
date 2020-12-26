#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include "funcs.h"
#include "error.h"


#define SWAP_MIN(a, b) { if (*a > *b) \
                            SWAP(a, b);\
                        }

int process(FILE *f, int *min_dist)
{
    *min_dist = INT_MAX;

    int local_max1 = -1;
    int local_max2 = -1;

    if (f == NULL || min_dist == NULL)
        return NULL_POINTER_EXC;

    if (ferror(f))
        return FILE_ERROR;

    if (fseek(f, 0L, SEEK_SET))
        return SEEK_FAILED;

    int curr_ind = 0;

    int last;
    int curr = -1;

    if (fscanf(f, "%d", &last) != 1)
        return NO_LOCAL_MAX;

    bool is_last_less_curr = false;

    while (fscanf(f, "%d", &curr) == 1)
    {
        if (is_last_less_curr && last > curr)
        {
            local_max1 = curr_ind;
            SWAP_MIN(&local_max1, &local_max2);
        }

        is_last_less_curr = last < curr;

        if (local_max1 != -1 && local_max2 != -1)
            *min_dist = MIN(abs(*min_dist), local_max2 - local_max1);

        last = curr;
        curr_ind++;
    }

    //printf("Local max 1: %d \t local max 2: %d\n", local_max1, local_max2);

    return (local_max1 == -1 || local_max2 == -1) ? NO_LOCAL_MAX : SUCCESS;
}
