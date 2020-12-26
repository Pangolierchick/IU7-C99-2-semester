#ifndef __FUNCS_H__
#define __FUNCS_H__

#include <stdio.h>
#include "error.h"

#define NUMBER_TOP_LIMIT   123124

#define FAILED                  1

#define BAD_ARGS_GIVEN          1
#define SEEK_FAILED             3

#define CREATE_FILE            "c"
#define PRINT_NUMBERS          "p"
#define SORT_FILE              "s"

#define SWAP(A, B) {int tmp = *A; *A = *B; *B = tmp;}

#define CREATE_AND_FILL_PROCESSED  1
#define PRINT_FILE_PROCESSED       2
#define SORT_FILE_PROCESSED        3


int parse_argv(int argc, char *argv[]);
int sort_file(const char *fp);
int frndncreate(const int numbers, const char *fp);
int print_file(const char *pt);
int is_sorted(const char *f);

#endif // __FUNCS_H__
