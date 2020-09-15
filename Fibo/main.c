#include <stdio.h>
#include <stdlib.h>

int getFibo(int x)
{
    if(x==0)
        return 0;
    else if(x==1)
        return 1;
    else
        return getFibo(x-1) + getFibo(x-2);
}
int main()
{
    printf("\nEnter N:");
    int n;
    scanf("%d",&n);
    printf("\nThe series is as follows: ");
    for(int i=0;i<n;i++)
    {
        printf("%d  ",getFibo(i));
    }
    return 0;
}
