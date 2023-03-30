#include<stdio.h>

int main()
{
    int n;
    int arr[1000];
printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the array ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
         printf("Enter the element arr[%d] : %d\n",i,arr[i]);
    }
    
    return 0;
}