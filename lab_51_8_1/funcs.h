#ifndef __FUNCS_H__
#define __FUNCS_H__

#include <stdio.h>

#define STR_NO_LOCAL_MAX "Less than two maxes found."
#define STR_NULL_POINTER "Invalid pointer given. Exiting"

#define MIN(A, B) A < B ? A : B
#define SWAP(A, B) {int temp = *A; *A = *B; *B = temp;}

int process(FILE *f, int *min_dist);

#endif // __FUNCS_H__
