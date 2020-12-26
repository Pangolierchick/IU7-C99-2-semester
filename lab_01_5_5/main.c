#include <stdio.h>
#include <math.h>

//printing number by digits
#define EXIT_OK 0
#define EXIT_NOT_OK 1
#define NEGATIVE_NUM_ERROR -1

int print_dec(int dec)
{
    if (dec <= 0)
        return NEGATIVE_NUM_ERROR;
    
    int len = floor(log10(dec)) + 1; //Caclulating length of given number
    int digit;
    
    while (--len >= 0)
    {
        digit = (dec / (int)pow(10, len)) % 10;
        printf("%d", digit);
    }
    
    printf("\n");
    return EXIT_OK;
}

int main(void)
{
    int number;
    printf("Input number: ");

    if (scanf("%d", &number) != 1) 
        return EXIT_NOT_OK;

    if (print_dec(number) == NEGATIVE_NUM_ERROR)
        return EXIT_NOT_OK;
    
    return EXIT_OK;
}