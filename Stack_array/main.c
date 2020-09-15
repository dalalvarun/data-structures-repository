#include<stdio.h>
#include<malloc.h>
#define MAX 10
int stack[MAX], top=-1;
int push (int);
int pop(int);
int peek(int);
int display(int);
int main()
{
    int option;
    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n\nEnter your choice:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                top = push(top);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                top = peek(top);
                break;
            case 4:
                top = display(top);
                break;
        }
    }
    while(option!=5);
    return 0;
}

int push(int top)
{
    if(top==MAX-1)
    {
        printf("\nOverflow!!!");
        return top;
    }
    else
    {
        top++;
        printf("\nEnter the element to be pushed:");
        int el;
        scanf("%d",&el);
        stack[top] = el;
        printf("\nElement pushed!!!");
        return top;
    }
}

int pop(int top)
{
    if(top==-1)
    {
        printf("\nUnderflow!!!");
        return top;
    }
    else
    {
        top--;
        printf("\nElement popped!!!");
        return top;
    }
}

int peek(int top)
{
    if(top==-1)
        printf("\nThe stack is empty!!!");
    else
        printf("Peek: %d",stack[top]);
    return top;
}
int display(int top)
{
    if(top==-1)
        printf("\nThe stack is empty!!!");
    else
    {
        printf("\nThe stack is as follows:");
        for(int i=top;i>=0;i--)
        {
            printf("-->%d ",stack[i]);
        }
    }
    return top;
}
