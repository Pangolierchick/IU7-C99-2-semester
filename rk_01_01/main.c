#include <stdio.h>
#include <limits.h>
#include <stdint.h>

#define SUCCESS 0
#define BAD_INPUT_VALUES 1
#define NOT_FOUND 2

#define MAX_ARRAY_SIZE 1000

void print_arr(const unsigned int *arr, const int size)
{
    for (int i = 0; i < size; i++)
        printf("%u ", arr[i]);
    printf("\n");
}

uint64_t array_sum(const unsigned int *arr, const int size)
{
    uint64_t sum = 0;

    for (int i = 0; i < size; i++)
        sum += arr[i];
    
    return sum;
}

int input_arr(unsigned int *arr, int *size)
{
    while (scanf("%u", (arr + *size)) == 1 && *size < MAX_ARRAY_SIZE)
        (*size)++;
    
    return SUCCESS;
}


int magic_task(const unsigned int *arr, const int size)
{
    uint64_t all_sum = array_sum(arr, size) / 2;

    uint64_t curr_sum = arr[0];

    int m = -1;

    for (int i = 0; i + 1 < size; i++)
    {
        if (curr_sum <= all_sum && curr_sum + arr[i + 1] > all_sum)
        {
            m = i;
            break;
        }

        curr_sum += arr[i];
    }

    return m;
}


int main(void)
{
    unsigned int arr[MAX_ARRAY_SIZE];
    int arr_size = 0;

    if (input_arr(arr, &arr_size))
    {
        perror("Invalid input");
        return BAD_INPUT_VALUES;
    }
    
    int m = magic_task(arr, arr_size);

    if (m == -1)
    {
        perror("Number hasnt been found");
        return NOT_FOUND;
    }

    printf("MAGIC NUMBER: %d\n", m);

    return SUCCESS;
}
