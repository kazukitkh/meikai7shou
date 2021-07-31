#include <stdio.h>
int main(void)
{
    int i;
    int a=1;
    for (i=1; i<=15; i++)
    a*=2;

    printf("%d", a);
    return 0;
}