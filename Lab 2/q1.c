#include<stdio.h>
#include<stdlib.h>

int CheckGCD(int m, int n)
{
    int t,rem,opcount=0;
    if(m>n)
        t=n;
    else
        t=m;

    while((m%t)!=0 || (n%t)!=0)
    {
        opcount++;

        if((m%t)==0)
        {
            if((n%t)==0)
                return t;

            else
                t--;
        }

        else
            t--;
    }

    printf("Operational Count is : %d\n",opcount+1);
    return t;
}

int main()
{
    int m ,n;
    printf("Enter 2 numbers to find GCD: ");
    scanf("%d",&m);
    scanf("%d",&n);

    printf("The value of GCD is : %d",CheckGCD(m,n));

    return 0;
}