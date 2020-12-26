#include <stdio.h>

int main(void)
{
    float r1, r2, r3, r;
    
    printf("Input resistor's values (r1 r2 r3): ");
    scanf("%f %f %f", &r1, &r2, &r3);
    
    r = 1 / (1 / r1 + 1 / r2 + 1 / r3);
    
    printf("Total resistance is %.5f\n", r);
    
    return 0;
}
