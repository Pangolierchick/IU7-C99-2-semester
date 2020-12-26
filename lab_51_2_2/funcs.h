#ifndef __FUNCS_H__
#define __FUNCS_H__

#include <stdio.h>
#include "error.h"

#define SUCCESS 0

#define PATH_LEN 100

int file_average(FILE *f, double *avg, int *count);
int file_dispersion(FILE *f, const double avg, double *disp, const int n);
int parse_args(int argc, char *argv[], char *fpath);

#endif // __FUNCS_H__
