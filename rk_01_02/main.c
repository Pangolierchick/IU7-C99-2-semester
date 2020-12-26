#include <stdio.h>

#define SUCCESS 0

#define BAD_INPUT_VALUES      1
#define NEGATIVE_VAL_EXC      2

#define NEGATIVE_VALUE_FOUND -1
#define OUT_OF_RANGE_EXC     -2
#define NOT_INT_GIVEN        -3

#define MATRIX_SIZE 10

int matrix_sum(int matrix[][MATRIX_SIZE])
{
    int sum = 0;
    for (int i = 0; i < MATRIX_SIZE; i++)
        for (int j = 0; j < MATRIX_SIZE; j++)
            sum += matrix[i][j];

    return sum;
}

void print_arr(const int *arr, const int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void print_matrix(int matrix[][MATRIX_SIZE], const int size)
{
    for (int i = 0; i < size; i++)
        print_arr(matrix[i], size);
}


void input_arr_by_digits(int num, int *arr)
{
    int i = 0;
    
    while (num)
    {
        arr[i] = num % 10;
        num /= 10;
        i++;
    }
}

int input_matrix(int B[][MATRIX_SIZE])
{
    int temp;
    int i = 0;

    int rc = scanf("%d", &temp);

    while (rc != EOF && i <= MATRIX_SIZE)
    {
        if (rc == 0)
            return NOT_INT_GIVEN;

        if (temp < 0)
            return NEGATIVE_VALUE_FOUND;

        input_arr_by_digits(temp, B[i]);
        i++;

        rc = scanf("%d", &temp);
    }



    if (i > MATRIX_SIZE)
        return OUT_OF_RANGE_EXC;

    return i;
}

int main(void)
{
    int B[MATRIX_SIZE][MATRIX_SIZE] = { 0 };

    int size = input_matrix(B);

    switch (size)
    {
        case OUT_OF_RANGE_EXC:
            perror("Too many numbers given");
            return BAD_INPUT_VALUES;
        
        case NEGATIVE_VALUE_FOUND:
            perror("Negative value found");
            return NEGATIVE_VAL_EXC;
        
        case NOT_INT_GIVEN:
            perror("Input only int number");
            return BAD_INPUT_VALUES;
    }


    printf("MATRIX SUM: %d\n", matrix_sum(B));

    return SUCCESS;
}