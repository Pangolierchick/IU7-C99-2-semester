#include <stdlib.h>
#include <stdio.h>

int is_simmetric(int *row, int clm);

#define BAD_INPUT_VALUES 2
#define NO_SIMM_ROWS 3

#define MAX_ROW 10
#define MAX_COLUMN 10

#define OK 0
#define NOT_OK 1
#define TRUE 1
#define FALSE 0
#define SUCCESS 0

#define CINT const int



void print_array(int *array, CINT size)
{
    for (int *i = array; i < array + size; i++)
        printf("%d ", *i);

    printf("\n");
}

int create_array_task(int matrix[][MAX_COLUMN], int *const arr, CINT row, CINT clm)
{
    for (int i = 0; i < row; i++)
        if (is_simmetric(matrix[i], clm))
            arr[i] = 1;

    return SUCCESS;
}


void print_matrix(int matrix[][MAX_COLUMN], CINT row, CINT clm)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < clm; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int is_simmetric(int *row, CINT clm)
{
    int start = 0;
    int end = clm - 1;

    for (int i = 0; i < clm / 2; i++)
    {
        if (row[start] != row[end])
            return FALSE; 
        start++;
        end--;
    }
    return TRUE;
}

int input_matrix(int matrix[][MAX_COLUMN], int *row, int *clm)
{
    printf("Input row and column of matrix: ");

    if (scanf("%d %d", row, clm) != 2)
        return BAD_INPUT_VALUES;
    
    if (0 >= *clm || *clm > MAX_COLUMN)
        return BAD_INPUT_VALUES;
    
    if (0 >= *row || *row > MAX_COLUMN)
        return BAD_INPUT_VALUES;

    for (int i = 0; i < *row; i++)
    {
        for (int j = 0; j < *clm; j++)
        {
            printf("Input elem: ");
            if (scanf("%d", &matrix[i][j]) != 1)
                return BAD_INPUT_VALUES;
        }
        printf("\n");
    }
    return OK;
}


int main(void)
{
    int matrix[MAX_ROW][MAX_COLUMN];
    int row_array[MAX_ROW] = { 0 };
    int column;
    int row;

    if (input_matrix(matrix, &row, &column))
    {
        printf("Bad input values\n");
        return BAD_INPUT_VALUES;
    }

    create_array_task(matrix, row_array, row, column);
    print_array(row_array, row);
    return EXIT_SUCCESS;
}