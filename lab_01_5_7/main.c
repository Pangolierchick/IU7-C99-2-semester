#include <stdio.h>
#include <math.h> 
#include <stdlib.h>

#define BAD_INPUT_VALUES 0

double function(double x)
{
    return (1.0 / sqrt(1.0 - x * x));
}

double sum_of_row(double x, double eps)
{
    double curr_elem = 1;
    double sum = 1;
    unsigned int i = 2;

    if (fabs(x) >= 1)
        return BAD_INPUT_VALUES;
    
    if (eps <= 0 || eps > 1)
        return BAD_INPUT_VALUES;

    do
    {
        curr_elem *= ((x * x * (i - 1)) / i);
        i += 2;
        sum += curr_elem;
    } while (fabs(curr_elem) > eps);

    return sum;
}

int main(void)
{
    double x;
    double eps;
    double total_sum;
    
    printf("Input x (abs(x) < 1) and eps: ");
    
    if (scanf("%lf %lf", &x, &eps) != 2)
        return EXIT_FAILURE;
    
    total_sum = sum_of_row(x, eps);

    if (fabs(total_sum) <= BAD_INPUT_VALUES)
        return EXIT_FAILURE;

    double real_val = function(x);

    printf("s(x) = %.6f\n", total_sum);
    printf("f(x) = %.6f\n", real_val);
    printf("abs mistake = %.6f\n", fabs(real_val - total_sum));
    printf("relative mistake = %.6f\n", 
    fabs((real_val - total_sum) / real_val));
    
    return EXIT_SUCCESS;
}