#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX];
int topA = -1, topB = MAX;
int pushA(int);
int pushB(int);
int popA(int);
int popB(int);
int displayA(int);
int displayB(int);
int main()
{
    int option;
    do
    {
        printf("\n*****MAIN MENU*****");
        printf("\n 1.PUSH IN STACK A");
        printf("\n 2.PUSH IN STACK B");
        printf("\n 3.POP FROM STACK A");
        printf("\n 4.POP FROM STACK B");
        printf("\n 5.DISPLAY STACK A");
        printf("\n 6.DISPLAY STACK B");
        printf("\nEnter your choice:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                topA = pushA(topA);
                break;
            case 2:
                topB = pushB(topB);
                break;
            case 3:
                topA = popA(topA);
                break;
            case 4:
                topB = popB(topB);
                break;
            case 5:
                topA = displayA(topA);
                break;
            case 6:
                topB = displayB(topB);
                break;
        }
    }while(option!=7);
    return 0;
}

int pushA(int top)
{
    if(top==topB-1)
    {
        printf("\nOverflow!!!");
        return top;
    }
    else
    {
        printf("\nEnter the element to push:");
        int el;
        scanf("%d",&el);
        stack[top+1] = el;
        top+=1;
        printf("\nElement %d pushed!!!",el);
        return top;
    }

}

int pushB(int top)
{
    if(top == topA+1)
    {
        printf("\nOverflow!!!");
        return top;
    }
    else
    {
        printf("\nEnter the element to be pushed:");
        int el;
        scanf("%d",&el);
        stack[top-1] = el;
        top-=1;
        printf("\nElement %d pushed!!!",el);
        return top;
    }
}

int popA(int top)
{
    if(top == -1)
    {
        printf("\nUnderflow!!!");
        return top;
    }
    else
    {
        top-=1;
        printf("\nElement popped from stack A");
        return top;
    }
}

int popB(int top)
{
    if(top == MAX)
       {
           printf("\nUnderflow!!!");
           return top;
       }
       else
        {
            top+=1;
            printf("\nElement popped from stack B");
            return top;
        }
}
int displayA(int top)
{
    if(top==-1)
    {
        printf("\nStack A is empty");
        return top;
    }
    else
    {
        printf("\nThe stack A is as follows:");
        for(int i=topA;i>=0;i--)
        {
            printf("\n%d",stack[i]);
        }
        return top;
    }
}


int displayB(int top)
{
    if(top==MAX)
    {
        printf("\nStack B is empty");
        return top;
    }
    else
    {
        printf("\nThe stack B is as follows:");
        for(int i=top;i<=MAX-1;i++)
        {
            printf("\n%d",stack[i]);
        }
        return top;
    }
}
