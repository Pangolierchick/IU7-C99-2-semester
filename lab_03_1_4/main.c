#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define BAD_INPUT_VALUES 2
#define NOT_SINGLE_MIN_EXC 3
#define NOT_SQUARE_MATRIX 4

#define MAX_ROW 10
#define MAX_COLUMN 5

#define SUCCESS 0
#define TRUE 1
#define FALSE 0

#define CINT const int

#define MAX(A, B) A > B ? A : B
#define SWAP(A, B) int tmp = A; A = B; B = tmp

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_elem_task(int matrix[][MAX_COLUMN], CINT row)
{
    int start = 0;
    int end = row;
    for (int i = 0; i < row / 2; i++)
    {
        for (int j = start; j < end; j++)
        {
            SWAP(matrix[i][j], matrix[row - i - 1][j]);
        }

        start++;
        end--;
    }
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
    
    if (*row != *clm)
        return NOT_SQUARE_MATRIX;


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

    swap_elem_task(matrix, row);
    print_matrix(matrix, row, column);
    

    return EXIT_SUCCESS;
}