#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SUCCESS 0
#define BAD_INPUT_VALUES 2
#define NOT_SINGLE_MIN_EXC 3
#define ONE_ROW_COLUMN_EXC 4
#define DELETED_MATRIX 5

#define MAX_ROW 10
#define MAX_COLUMN 10

#define TRUE 1
#define FALSE 0

#define CINT const int

int sum_digit(int num)
{
    int sum = 0;
    
    num = abs(num);

    while (num)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int matrix_delete_task(int matrix[][MAX_COLUMN], CINT row, CINT clm, CINT del_row, CINT del_clm)
{
    if (row == 1 || clm == 1)
        return DELETED_MATRIX;

    for (int i = 0; i < row; i++)
    {
        if (i == del_row)
            continue;
 
        for (int j = 0; j < clm; j++)
        {
            if (j == del_clm) 
                continue;

            printf("%d ", matrix[i][j]);   
        }
        printf("\n");
    }
    return SUCCESS;
}

int min_digit_elem(int matrix[][MAX_COLUMN], CINT row, CINT clm, int *del_row, int *del_clm)
{
    int min_elem = matrix[0][0];
    int is_single_min = TRUE;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < clm; j++)
        {
            if (i == 0 && j == 0)
                continue;

            if (sum_digit(matrix[i][j]) < sum_digit(min_elem))
            {
                min_elem = matrix[i][j];
                *del_row = i;
                *del_clm = j;
                is_single_min = TRUE;
            }
            else if (sum_digit(matrix[i][j]) == sum_digit(min_elem))
                is_single_min = FALSE;
        }
    }

    return is_single_min ? SUCCESS : NOT_SINGLE_MIN_EXC;    
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

int input_matrix(int matrix[][MAX_COLUMN], int *row, int *clm)
{
    printf("Input row and column: ");

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
    return SUCCESS;
}

int main(void)
{
    int matrix[MAX_ROW][MAX_COLUMN];
    int column;
    int row;

    if (input_matrix(matrix, &row, &column))
    {
        printf("Bad input values\n");
        return BAD_INPUT_VALUES;
    }

    int del_row = 0;
    int del_clm = 0;

    if (min_digit_elem(matrix, row, column, &del_row, &del_clm))
    {
        printf("Not single min elem error\n");
        return NOT_SINGLE_MIN_EXC;
    }

    if (matrix_delete_task(matrix, row, column, del_row, del_clm))
        return DELETED_MATRIX;

    return SUCCESS;
}
