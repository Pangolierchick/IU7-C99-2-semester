#include <stdio.h>
#include <math.h>


int main(void)
{
    float x1, y1, x2, y2, x3, y3;
    float side1, side2, side3;
    float perimeter;

    printf("Input coordinates of triangle's apexes: ");
    scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3);

    side1 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    side2 = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    side3 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    perimeter = side1 + side2 + side3;

    printf("Perimeter of triangle is %.5f\n", perimeter);
    return 0;
}
