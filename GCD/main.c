#include <stdio.h>
#include <stdlib.h>
int getGCD(int X, int Y)
{
    if(X<Y)     // so that first num is always greater than second
    {
        int temp = X;
        X=Y;
        Y=temp;
    }
    if(X%Y==0)
        return Y;
    else
        return getGCD(Y,X%Y);

}
int main()
{
    printf("\n*****GCD Solver*****");
    int A, B;
    printf("\nEnter A:");
    scanf("%d",&A);
    printf("\nEnter B:");
    scanf("%d",&B);
    int res = getGCD(A,B);
    printf("\n%d",res);
    return 0;
}
