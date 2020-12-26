#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define YES 1
#define NO 0

const double precize = 1e-3;

int is_intersec(double ax, double ay, double bx, double by,
double cx, double cy, double dx, double dy)
{
    double der = (bx - ax) * (dy - cy) - (by - ay) * (dx - cx);
    if (fabs(der) <= precize)
        return NO;
    double rght = (ay - cy) * (dx - cx) - (ax - cx) * (dy - cy);
    double lft = (ay - cy) * (bx - ax) - (ax - cx) * (by - ay);
    
    rght /= der;
    lft /= der;


    //printf("%lf %lf\n", rght, lft);

    if ((rght >= 0) && (rght <= 1) && (lft <= 1) && (lft >= 0))
        return YES;
    else
        return NO;
}

int main(void)
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    
    printf("Input coordinates: ");
    
    if (scanf("%lf %lf %lf %lf %lf %lf %lf %lf", 
    &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4) != 8)
        return 1;
    /*
    1 - пересекаются
    0 - не пересекаются
    */
    if ((fabs(x1 - x2) <= precize && fabs(y1 - y2) <= precize) || (fabs(x3 - x4) <= precize && fabs(y3 - y4) <= precize))
        return EXIT_FAILURE;
    /*
    else if (((fabs(x1 - x3) <= precize) && (fabs(y1 - y3) <= precize)) || ((fabs(x1 - x4) <= precize) && (fabs(y1 - y4) <= precize)) ||
        ((fabs(x2 - x3) <= precize) && (fabs(y2 - y3) <= precize)) || ((fabs(x2 - x4) <= precize) && (fabs(y2 - y4) <= precize)))
        printf("0\n");
    */
    else if ((fabs(x1 - x3) <= precize) && (fabs(y1 - y3) <= precize))
        printf("0\n");
    else if ((fabs(x1 - x4) <= precize) && (fabs(y1 - y4) <= precize))
        printf("0\n");
    else if ((fabs(x2 - x3) <= precize) && (fabs(y2 - y3) <= precize))
        printf("0\n");
    else if ((fabs(x2 - x4) <= precize) && (fabs(y2 - y4) <= precize))
        printf("0\n");
    else if (is_intersec(x1, y1, x2, y2, x3, y3, x4, y4))
        printf("1");
    else
        printf("0\n");
    return EXIT_SUCCESS;
}


