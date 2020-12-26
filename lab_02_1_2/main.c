#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE 10
#define INDEX_OUT_OF_RANGE -2
#define NO_PRIME_NUM_ERR -1
#define BAD_INPUT 4
#define FALSE 0
#define TRUE 1

void print_array(const int *const arr, const int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int input_arr(int *const arr, const int n)
{
    for (int i = 0; i < n; i++)
    {
        int tmp;
        printf("input elem of array: ");
        if (scanf("%d", &tmp) != 1)
            return EXIT_FAILURE;
        arr[i] = tmp;
    }
    return EXIT_SUCCESS;
}

int is_prime(int num)
{   
    if (num <= 1)
        return FALSE;

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return FALSE;
    }
    return TRUE;
}

int create_new_arr(int *arr, int *new_arr, const int arr_size, const int new_arr_size)
{
    int is_found = FALSE;
    int count_prime_number = 0;
    for (int i = 0; i < arr_size; i++)
    {
        if (is_prime(arr[i]))
        {
            count_prime_number++;
            is_found = TRUE;
            if (i > new_arr_size)
                return INDEX_OUT_OF_RANGE;
            *new_arr = arr[i];
            new_arr++;
        }
    }

    if (!is_found)
        return NO_PRIME_NUM_ERR;
    
    return count_prime_number;
}

int main(void)
{
    unsigned int n;
    int arr[ARRAY_SIZE] = { 0 };
    int new_arr[ARRAY_SIZE] = { 0 };
    
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
    
    int prime_array_size = create_new_arr(arr, new_arr, n, ARRAY_SIZE);

    if (prime_array_size < 0)
        return EXIT_FAILURE;

    print_array(new_arr, prime_array_size);
    
    return EXIT_SUCCESS;
}

