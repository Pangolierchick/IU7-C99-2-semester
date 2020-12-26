#include <stdio.h>

#define SEC_IN_MIN 60
#define MIN_IN_HOUR 60

int main(void)
{
    unsigned int s; 
    unsigned int h = 0;
    unsigned int m = 0;
    
    printf("Input time in seconds: ");
    scanf("%u", &s);
    
    if (s > 59)
    {
        m = (s - s % SEC_IN_MIN) / SEC_IN_MIN;
        s %= SEC_IN_MIN;
        h = m / MIN_IN_HOUR;
        m %= MIN_IN_HOUR;
    }
    printf("%u %u %u\n", h, m, s);
    return 0;
}
