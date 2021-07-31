#include <stdio.h>
#define NUMBER 15

int bit_count(unsigned s)
{
    int i;
    int bit=0;
    for (i=NUMBER; i>=1; i--)
    {
        if (s & 1U)
        {
            bit++;
            s>>=1;
        }
        
    }
    return bit;
}

void print_bit(unsigned x)
{
    int i;
    int t=bit_count(~0U);
    for (i=t-1 ; i>=0; i--){
        putchar( (x>>i) & 1U ? '1' : '0');
    }
    
}

int print_int(unsigned int s)
{
    int i;
    int sum=0;
    
    for (i=1; i<=bit_count(~0U); i++){
        int j=i;
        int t=1;
        if(s & 1U){
            while(--j){
                t*=2;

            }
            sum += t;
        }
        
        
        s>>=1;
        

    }
    return sum;
}


int main(void)
{
    unsigned x;
    int a,b;
    printf("input none-negative number x: \n"); scanf("%u", &x);
    int y = bit_count(x);
    printf("\nthe number of bit of x is: %d\n", y);
    do{
        printf("\nplease type the number from 1 to %d, which makes x decrease\n", y);
        scanf("%u", &a);
        if (a<=0||a>y)
        puts("\nplease type the correct number.\n\a");

    }while(a<=0||a>y);

    do{
        printf("\nplease type the number from 1 to %d, which makes x increase\n", y);
        scanf("%u", &b);
        if (b<=0||b>y)
        puts("\nplease type the correct number.\a");

    }while(b<=0||b>y);
    
    printf("x in bit is :\n"); print_bit(x);
    printf("\nx>>%d       :\n", a); print_bit(x>>a);
    printf("\nx<<%d       :\n", b); print_bit(x<<b);
    printf("\nx in integer:  %d\n", x); 
    printf("\nx>>a in integer: %d\n", print_int(x>>a));

    return 0;
    
}