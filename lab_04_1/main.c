#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "my_strcspn.h"

#define SUCCESS 0

int main(void)
{
    size_t test1;
    size_t test2;
    int result = 1;

    test1 = strcspn("aaabbb", "rbbb");
    test2 = my_strcspn("aaabrb", "bbb");
    result &= test1 == test2;

    printf("STRCSPN: %10zu\n", test1);
    printf("MY STRCSPN: %7zu\n\n", test2);

    test1 = strcspn("bbb", "b");
    test2 = my_strcspn("bbb", "b");
    result &= test1 == test2;

    printf("STRCSPN: %10zu\n", test1);
    printf("MY STRCSPN: %7zu\n\n", test2);

    test1 = strcspn("1234567890", "78");
    test2 = my_strcspn("1234567890", "78");
    result &= test1 == test2;

    printf("STRCSPN: %10zu\n", test1);
    printf("MY STRCSPN: %7zu\n\n", test2);

    test1 = strcspn("Kirill", "lliriK");
    test2 = my_strcspn("Kirill", "lliriK");
    result &= test1 == test2;

    printf("STRCSPN: %10zu\n", test1);
    printf("MY STRCSPN: %7zu\n\n", test2);
    
    test1 = strcspn(" ", ",,.s");
    test2 = my_strcspn(" ", ",,.s");
    result &= test1 == test2;

    printf("STRCSPN: %10zu\n", test1);
    printf("MY STRCSPN: %7zu\n\n", test2);
    
    test1 = strcspn("aaa", "bbba");
    test2 = my_strcspn("a", "bbcda");
    result &= test1 == test2;

    printf("STRCSPN: %10zu\n", test1);
    printf("MY STRCSPN: %7zu\n\n", test2);

    printf("RESULT: %d\n", result);
    

    return SUCCESS;
}
