#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define INT_OVERFLOW -1
#define ARRAY_SIZE 21
#define MAX_SIZE 10
#define BAD_INPUT 1
#define FALSE 0
#define TRUE 1
#define SUCCESS 0

int input_arr(int *const arr, const int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        printf("input elem of array: ");
        if (scanf("%d", arr + j) != 1)
            return BAD_INPUT;
        j += 2;
    }
    return SUCCESS;
}

void print_array(int const *const arr, const int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[j] % 3)
            printf("%d ", arr[j]);
        else 
            printf("%d %d ", arr[j], arr[j + 1]);
        j += 2;
    }    
    printf("\n");
}

int task_fibonacci(int *last_fib, int *curr_fib)
{
    if (*last_fib > INT_MAX - *curr_fib)
        return INT_OVERFLOW;

    int temp = *last_fib;
    
    *last_fib += *curr_fib;
    *curr_fib = temp;

    return SUCCESS;
}

int array_filling(int *const arr, const int n)
{
    int last_fib = 0;
    int curr_fib = 0;
    int first = TRUE;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[j] % 3 == 0)
        {
            if (task_fibonacci(&last_fib, &curr_fib) == INT_OVERFLOW)
                return INT_OVERFLOW;
            arr[j + 1] = last_fib;
        }

        if (first)
        {
            curr_fib++;
            first = FALSE;
        } 
        j += 2;
    }
    return SUCCESS;
}   

int main(void)
{
    int n;
    int arr[ARRAY_SIZE] = { 0 };

    printf("Input array size: ");
    if (scanf("%d", &n) != 1)
    {
        printf("Bad input values\n");    
        return BAD_INPUT;
    }
    

    if (n <= 0 || n > MAX_SIZE)
    {
        printf("Array size must be in (zero; ten] interval\n");
        return BAD_INPUT;
    }

    if (input_arr(arr, n))
    {
        printf("Bad input values\n");
        return BAD_INPUT;
    }

    if (array_filling(arr, n) == INT_OVERFLOW)
    {
        printf("Int overflow detected\n");
        return INT_OVERFLOW;
    }    

    print_array(arr, n);

    return EXIT_SUCCESS;
}