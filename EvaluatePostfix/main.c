#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include<string.h>
#define MAX 40
struct stack
{
    int data;
    struct stack *next;
};

struct stack *top = NULL;
struct stack *push(struct stack *, int);
struct stack *pop(struct stack *);
int peek(struct stack *);
int main()
{
    printf("Enter a postfix expression:");
    char input[MAX];
    gets(input);

    for(int i=0;i<MAX;i++)
    {
        if(input[i]=='\0')
            break;

        if(isdigit(input[i]))
        {
            int j = i+1;
            int X =0;
            while(isdigit(input[i]))
            {
                X = X*10 + (int)(input[i]-'0');
                i++;
            }
            i--;
            top = push(top,X);
        }
        if(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/')
        {
            int B = peek(top);
            top = pop(top);
            int A = peek(top);
            top = pop(top);
            int C;
            if(input[i]=='+')
                C = A+B;
            else if(input[i]=='-')
                C = A-B;
            else if(input[i]=='*')
                C = A*B;
            else if(input[i]=='/')
                C = A/B;
            top = push(top,C);
        }
    }
    printf("\nThe evaluation is: %d",peek(top));
    return 0;
}

struct stack *push(struct stack *top, int x)
{
    struct stack *ptr = (struct stack *) malloc(sizeof(struct stack));
    ptr->data = x;
    if(top==NULL)
    {
        top = ptr;
        ptr->next = NULL;
    }
    else
    {
        ptr->next = top;
        top = ptr;
    }
    return top;
}

struct stack *pop(struct stack *top)
{
    if(top==NULL)
    {
        return top;
    }
    else if(top->next == NULL)
    {
        struct stack *ptr = top;
        free(ptr);
        top = NULL;
        return top;
    }
    else
    {
        struct stack *ptr = top;
        top = top->next;
        free(ptr);
        return top;
    }
}
int peek(struct stack *top)
{
    if(top==NULL)
        return -1;
    return top->data;
}
