#include <stdio.h>
#include <math.h>
#include <string.h>
#include "funcs.h"
#include "error.h"

int file_average(FILE *f, double *avg, int *const count)
{
    if (f == NULL || avg == NULL || count == NULL)
        return NULL_POINTER_EXC;

    *avg = 0;
    *count = 0;
    
    if (fseek(f, 0L, SEEK_SET))
        return FILE_READING_FAILED;

    double curr_num;
    int rc;

    while ((rc = fscanf(f, "%lf", &curr_num)) == 1)
    {
        *avg += curr_num;
        (*count)++;
    }

    if (rc != EOF)
        return BAD_INPUT;

    if (*count == 0)
        return EMPTY_FILE;

    *avg /= *count;

    return fseek(f, 0L, SEEK_SET);
}

int file_dispersion(FILE *f, const double avg, double *disp, const int n)
{
    if (f == NULL || disp == NULL)
        return NULL_POINTER_EXC;

    if (n <= 1)
        return FILE_READING_FAILED;

    *disp = 0;
    if (fseek(f, 0L, SEEK_SET))
        return FILE_READING_FAILED;

    double curr_num;


    while (fscanf(f, "%lf", &curr_num) != EOF)
        *disp += pow(curr_num - avg, 2);

    *disp /= (double) n;


    return fseek(f, 0L, SEEK_SET);
}


int parse_args(int argc, char *argv[], char *fpath)
{
    if (argv == NULL || fpath == NULL)
        return NULL_POINTER_EXC;

    if (argc != 2)
        return TOO_MANY_ARGV;


    strncpy(fpath, argv[1], PATH_LEN);

    return SUCCESS;
}
