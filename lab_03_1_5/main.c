#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define ARR_IND_OUT_OF_RANGE 1
#define BAD_INPUT_VALUES 2
#define NOT_SINGLE_MIN_EXC 3
#define NO_TEN_DIGITS_NUMS_EXC 4

#define MAX_ROW 10
#define MAX_COLUMN 10
#define SHIFT_VAL 3

#define TRUE 1
#define FALSE 0
#define CINT const int

#define SUCCESS 0
#define FAILURE 1

#define SWAP(A, B) int tmp = A; A = B; B = tmp

void print_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int digit_sum(int num)
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

int array_shift(int *arr, CINT size, CINT shift)
{
    if (shift < 0)
        return FAILURE;

    for (int i = 0; i < shift; i++)
        for (int j = 1; j < size; j++)
        {
            SWAP(arr[j], arr[j - 1]);
        }
    
    return SUCCESS;
}

int insertion_task(int matrix[][MAX_COLUMN], CINT row, CINT clm, CINT *const arr, CINT size)
{
    if (size <= 0)
        return SUCCESS;

    int curr_arr_ind = 0;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < clm; j++)
        {
            if (curr_arr_ind > size)
                return ARR_IND_OUT_OF_RANGE;

            if (digit_sum(matrix[i][j]) > 10)
                matrix[i][j] = arr[curr_arr_ind++];
        }

    return SUCCESS;
}


int digits_arr_fill(int matrix[][MAX_COLUMN], CINT row, CINT clm, int *arr, int *arr_size)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < clm; j++)
            if (digit_sum(matrix[i][j]) > 10)
                arr[(*arr_size)++] = matrix[i][j];

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
    int task_arr[MAX_COLUMN * MAX_ROW];
    int column;
    int row;

    if (input_matrix(matrix, &row, &column))
    {
        printf("input only integer values\n");
        return BAD_INPUT_VALUES;
    }

    int arr_size = 0;

    digits_arr_fill(matrix, row, column, task_arr, &arr_size);
    array_shift(task_arr, arr_size, SHIFT_VAL);
    insertion_task(matrix, row, column, task_arr, arr_size);

    print_matrix(matrix, row, column);

    return EXIT_SUCCESS;
}