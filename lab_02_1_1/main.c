#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10
#define BAD_INPUT -1
#define NO_ODD_NUM -2
#define FALSE 0
#define TRUE 1
#define SUCCESS 0

int input_arr(int *arr, const int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("input elem of array: ");
        if (scanf("%d", arr + i) != 1)
            return BAD_INPUT;
    }
    return SUCCESS;
}

int product_of_arr(int const *const arr, const int n, int *product)
{
    int is_find = FALSE;

    if (*product != 1)
        return BAD_INPUT;

    for (int i = 0; i < n; i++)
        if (arr[i] % 2)
        {
            *product *= arr[i];
            is_find = TRUE;
        }
    if (!is_find)
        return NO_ODD_NUM;
    return SUCCESS;
}

int main(void)
{
    unsigned int n;
    int arr[ARRAY_SIZE] = { 0 };
    
    printf("Input array size: ");
    if (scanf("%ud", &n) != 1)
    {
        printf("Bad input values\n");    
        return BAD_INPUT;
    }

    if (n <= 0 || n > ARRAY_SIZE)
    {
        printf("Array size must be in (zero; ten] interval\n");
        return BAD_INPUT;
    }
    if (input_arr(arr, n))
        return BAD_INPUT;
    
    int product = 1;
    int product_err = product_of_arr(arr, n, &product);

    if (product_err == NO_ODD_NUM)
        return NO_ODD_NUM;
    else if (product_err == BAD_INPUT)
        return BAD_INPUT;
    

    printf("Total product = %d\n", product);
    
    return EXIT_SUCCESS;
}

