#include<stdio.h>
#include<stdlib.h>

int EuclidGCD(int m, int n)
{
    int r;
    int opcount=0;

    while(n!=0)
    {
        opcount++;
        r=m%n;
        m=n;
        n=r;
    }

    printf("Operation Count = %d\n",opcount);
    return m;
}

int main()
{
    int m ,n;
    printf("Enter 2 numbers : ");
    scanf("%d",&m);
    scanf("%d",&n);

    printf("GCD of 2 numbers is : %d\n", EuclidGCD(m,n));

    return 0;
}