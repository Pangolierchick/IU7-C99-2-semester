#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define BAD_INPUT_VALUES 2
#define NOT_SINGLE_MIN_EXC 3

#define MAX_ROW 10
#define MAX_COLUMN 10

#define SUCCESS 0
#define TRUE 1
#define FALSE 0
#define CINT const int

#define MAX(A, B) A > B ? A : B
#define SWAP(A, B) int tmp = A; A = B; B = tmp

void array_swap(int *a, int *b, int size)
{
    for (int i = 0; i < size; i++)
    {
        SWAP(a[i], b[i]);
    }
}

int array_max(CINT array[], CINT size)
{
    int max = array[0];
    for (int i = 1; i < size; i++)
        max = MAX(max, array[i]);
    return max;
}

void sort_task(int matrix[][MAX_COLUMN], CINT row, CINT clm)
{
    for (int i = 0; i < row; i++)
    {
        int is_sorted = TRUE;
        for (int j = 1; j < row; j++)
        {
            if (array_max(matrix[j - 1], clm) < array_max(matrix[j], clm))
            {
                array_swap(matrix[j - 1], matrix[j], clm);
                is_sorted = FALSE;
            }
        }
        if (is_sorted)
            return;
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
    printf("Input row and elem: ");

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

    sort_task(matrix, row, column);
    print_matrix(matrix, row, column);

    return EXIT_SUCCESS;
}