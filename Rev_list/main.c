#include <stdio.h>
#include <stdlib.h>

int stack[10];
int top=-1;
int push(int);
int display();

int main()
{
   printf("\nEnter the number of elements (max 10):");
   int n;
   scanf("%d",&n);
   printf("\nEnter the elements of the list:");
   while(n--)
   {
       int temp;
       scanf("%d",&temp);
       top = push(temp);
   }
   printf("\nThe reversed list is: ");
   display();
}

int push(int val)
{
    top++;
    stack[top] = val;
    return top;
}
int display()
{
    for(int i=top;i>=0;i--)
    {
        printf("%d  ",stack[i]);
    }
}
