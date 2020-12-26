#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <stdbool.h>
#include "error.h"
#include "funcs.h"

/*
static void print_help(void)
{
    puts("Help message. Made by Kirill");
    puts("\tp PATH – print out file at PATH.");
    puts("\tc NUMBERS PATH - create file at PATH with NUMBERS random integers");
    puts("\ts PATH - sort file at PATH.");
}
*/


static int get_file_len(FILE *f, int *dst)
{
    if (fseek(f, 0L, SEEK_END))
        return FAILED;

    *dst = ftell(f);

    if (*dst < 0)
        return FAILED;

    return fseek(f, 0L, SEEK_SET);
}

static int check_file_len(FILE *f)
{
    int len;
    
    get_file_len(f, &len);
    
    return ((len % sizeof(int)) == 0);
}

static int safe_atoi(const char *str, int *dst)
{
    if (dst == NULL || str == NULL)
        return FAILED;

    char *end;
    *dst = (int) strtol(str, &end, 10);

    if (*end != '\0')
        return FAILED;

    return SUCCESS;
}

static int get_number_by_pos(long pos, FILE *file, int *dst)
{
    long offset = pos * sizeof(int);

    if (fseek(file, offset, SEEK_SET))
        return SEEK_FAILED;

    if (fread(dst, sizeof(int), 1, file) != 1)
        return FAILED;

    if (ferror(file))
        return SEEK_FAILED;

    return SUCCESS;
}

static int put_number_by_pos(long pos, FILE *file, const int src)
{
    long offset = pos * sizeof(int);
    
    if (fseek(file, offset, SEEK_SET))
        return SEEK_FAILED;

    if (fwrite(&src, sizeof(int), 1, file) != 1)
        return FAILED;

    return SUCCESS;
}

static void fileqsort(FILE *f, int first, int last)
{
    if (first < last)
    {
        int left = first;
        int right = last;

        int left_val;
        int right_val;

        get_number_by_pos(left, f, &left_val);
        get_number_by_pos(right, f, &right_val);

        int middle;
        
        get_number_by_pos((left + right) / 2, f, &middle);
        
        do
        {
            get_number_by_pos(left, f, &left_val);
            while (left_val < middle)
                get_number_by_pos(++left, f, &left_val);

            get_number_by_pos(right, f, &right_val);
            while (right_val > middle)
                get_number_by_pos(--right, f, &right_val);


            if (left <= right)
            {
                get_number_by_pos(left, f, &left_val);
                get_number_by_pos(right, f, &right_val);

                
                put_number_by_pos(left, f, right_val);
                put_number_by_pos(right, f, left_val);

                left++;
                right--;
            }
        } while (left <= right);
        fileqsort(f, first, right);
        fileqsort(f, left, last);
    }
}

int sort_file(const char *fp)
{
    FILE *file = fopen(fp, "r+b");

    if (file == NULL)
        return FILE_SORT_FAILED;
    
    if (!check_file_len(file))
        return FILE_SORT_FAILED;

    int len;

    if (get_file_len(file, &len))
        return FILE_SORT_FAILED;

    if (len <= 0)
        return FILE_SORT_FAILED;

    len /= sizeof(int);

    fileqsort(file, 0, len - 1);

    if (fclose(file))
        return FILE_SORT_FAILED;

    return SORT_FILE_PROCESSED;
}

int frndncreate(const int numbers, const char *fp)
{
    srand(time(NULL));

    FILE *file = fopen(fp, "wb");
    
    if (file == NULL)
        return FILE_CREATION_FAILED;


    for (int i = 0; i < numbers; i++)
    {
        int rand_num = rand() % NUMBER_TOP_LIMIT;
        
        // printf("%d ", rand_num);
        
        if (put_number_by_pos(i, file, rand_num) == SEEK_FAILED)
            return FILE_CREATION_FAILED;
    }
    
    // printf("\n");

    if (fclose(file))
        return FILE_CREATION_FAILED;

    return CREATE_AND_FILL_PROCESSED;
}

int print_file(const char *pt)
{
    FILE *file = fopen(pt, "rb");

    if (file == NULL)
        return FILE_PRINT_FAILED;

    if (!check_file_len(file))
        return FILE_PRINT_FAILED;

    int flen;

    if (get_file_len(file, &flen))
        return FILE_PRINT_FAILED;

    if (flen <= 0)
        return FILE_PRINT_FAILED;

    flen /= sizeof(int);

    // printf("File len: %d\n", flen);

    for (int i = 0; i < flen; i++)
    {
        int temp;
        get_number_by_pos(i, file, &temp);
        printf("%d ", temp);
    }

    printf("\n");

    if (fclose(file) == EOF)
        return FILE_PRINT_FAILED;

    return PRINT_FILE_PROCESSED;
}

int is_sorted(const char *f)
{
    FILE *file = fopen(f, "rb");

    int len;

    get_file_len(file, &len);
    len /= sizeof(int);

    int left;
    int right;
    
    for (int i = 1; i < len; i++)
    {
        get_number_by_pos(i - 1, file, &left);
        get_number_by_pos(i, file, &right);
        assert(left <= right);
    }
    
    fclose(file);

    return SUCCESS;
}

int parse_argv(int argc, char *argv[])
{
    int result = UNKNOWN_OP;

    if (strcmp(argv[1], CREATE_FILE) == 0)
    {
        if (argc != 4)
            return result;

        int num_count;
        
        if (safe_atoi(argv[2], &num_count))
            return result;

        if (num_count <= 0)
            return result;

        result = frndncreate(num_count, argv[3]);
    }
    else if (argc != 3)
    {
        return result;
    }
    else if (strcmp(argv[1], PRINT_NUMBERS) == 0)
    {
        result = print_file(argv[2]);
    }
    else if (strcmp(argv[1], SORT_FILE) == 0)
    {
        result = sort_file(argv[2]);
    }

    return result;
}
