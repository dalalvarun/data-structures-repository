#include <stdio.h>
#include <stdlib.h>

void move(int x, char source, char dest, char spare);
int main()
{
    printf("\nEnter the number of rings:");
    int n;
    scanf("%d",&n);
    move(n,'A','C','B');
    return 0;
}

void move(int x, char source, char dest, char spare)
{
    if(x==1)
        printf("\nMove from %c to %c.",source,dest);
    else
    {
        move(x-1,source,spare,dest);
        move(1,source,dest,spare);
        move(x-1,spare,dest,source);

    }
}
