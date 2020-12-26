#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE 10
#define TRUE 1
#define FALSE 0
#define BAD_INPUT_VALUES 3
#define SUCCESS 0
#define ALL_NEGATIVE_ERR 2

int input_array(int *arr_begin_p, int const *const arr_end_p)
{
    unsigned char is_all_negative = TRUE;
    while (arr_begin_p < arr_end_p)
    {
        printf("input elem: ");
        if (scanf("%d", arr_begin_p) != 1)
            return BAD_INPUT_VALUES;
        
        if (*arr_begin_p)
            is_all_negative = FALSE;
        arr_begin_p++;
    }
    printf("\n");

    if (is_all_negative)
        return ALL_NEGATIVE_ERR;
    
    return SUCCESS;
}

int task_sum(int *arr_begin_p, int *arr_end_p)
{
    int sum = 0;
    int last_product = *arr_begin_p;

    while (arr_begin_p < arr_end_p)
    {
        if (*arr_begin_p < 0)
        {
            sum += last_product;
            break;
        }
        
        sum += last_product;
        arr_begin_p++;
        last_product *= *arr_begin_p;
    }

    return sum;
}

int main(void)
{
    int n = 0;
    int arr[ARRAY_SIZE] = { 0 };
    int sum = 0;
    printf("input array size: ");
    if (scanf("%d", &n) != 1)
        return BAD_INPUT_VALUES;

    if (n < 1 || n > ARRAY_SIZE)
        return BAD_INPUT_VALUES;

    if (input_array(arr, arr + n))
        return BAD_INPUT_VALUES;

    sum = task_sum(arr, arr + n);
    printf("task sum is: %d\n", sum);
    return EXIT_SUCCESS;
}
