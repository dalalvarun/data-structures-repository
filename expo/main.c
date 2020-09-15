#include <stdio.h>
#include <stdlib.h>

int getExpo(int A, int B)
{
    if(B==0)
        return 1;
    else
        return A*getExpo(A,B-1);
}
int main()
{
    int X, Y;
    printf("\nEnter X:");
    scanf("%d",&X);
    printf("\nEnter Y:");
    scanf("%d",&Y);
    int res = getExpo(X,Y);
    printf("\nThe result is : %d", res);
    return 0;
}
