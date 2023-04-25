#include <stdio.h>

int main()
{
    const int i = 2;
    const int* ptr1 = &i;
    int* ptr2 = (int*)ptr1;
    *ptr2 = 3;

    printf("i = %d\n", i);
    printf("i = ptr2 = %d", *ptr2);

    return 0;
}
