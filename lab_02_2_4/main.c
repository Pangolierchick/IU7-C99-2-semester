#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10
#define BAD_INPUT_VALUES 2
#define SUCCESS 0

int input_array(int *arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("input elem: ");
        if (scanf("%d", (arr + i)) != 1)
            return BAD_INPUT_VALUES;
    }
    return SUCCESS;
}

void print_arr(int const arr[], const int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selection_sort(int arr[], const int n)
{   
    int tmp = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
            {
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
}


int main(void)
{
    int arr[ARRAY_SIZE] = { 0 };
    int n = 0;

    printf("Input array size: ");
    if (scanf("%d", &n) != 1)
    {
        printf("Bad input values\n");
        return BAD_INPUT_VALUES;
    }

    if (n <= 0 || n > ARRAY_SIZE)
    {
        printf("Array size must be in (zero; ten] interval\n");
        return BAD_INPUT_VALUES;
    }

    if (input_array(arr, n))
    {
        printf("Bad input values\n");
        return BAD_INPUT_VALUES;
    }

    selection_sort(arr, n);
    print_arr(arr, n);

    return EXIT_SUCCESS;
}
