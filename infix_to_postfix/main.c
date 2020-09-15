#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define MAX 350

struct stack
{
    char data;
    struct stack *next;
};
struct stack *top = NULL;
struct stack *push(struct stack *,char);
struct stack *pop(struct stack *);
char peek(struct stack *);
int getPriority(char);
int main()
{
    char input[MAX];
    printf("\nEnter infix expression:");
    gets(input);
    printf("\nThe postfix expression is: \n");
    for(int i=0;i<MAX;i++)
    {
        if(input[i]=='\0')
            break;
        if(isdigit(input[i])|| isalpha(input[i]))
        {
            printf("%c ",input[i]);
        }
        if(input[i]=='(')
            top = push(top,input[i]);
        if(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/' || input[i]=='%'|| input[i]=='^')
        {
            if(peek(top)!='$')
            {
                if(peek(top)=='(')
                {
                    top = push(top,input[i]);
                }
                else if(getPriority(input[i])>getPriority(peek(top)))
                {
                    top = push(top,input[i]);
                }
                else if(getPriority(input[i])<=getPriority(peek(top)))
                {
                    while(1)
                    {
                        char temp = peek(top);
                        if(getPriority(temp)< getPriority(input[i]) || temp=='('|| peek(top)=='$')
                        {
                            top = push(top,input[i]);
                            break;
                        }
                        else
                        {
                            printf("%c ",temp);
                            top = pop(top);
                        }
                    }


                }
            }
            else
            {
                top = push(top,input[i]);
            }
        }
        if(input[i]==')')
        {

            while(peek(top)!='(')
            {
                char temp = peek(top);
                printf("%c ",temp);
                top = pop(top);
            }
            top = pop(top);
        }

    }
    while(top)
    {
        char temp = peek(top);
        printf("%c ",temp);
        top = pop(top);
    }
    return 0;


}

struct stack *push(struct stack *top, char val)
{
    struct stack *ptr = (struct stack *) malloc(sizeof(struct stack));
    ptr->data = val;
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
        return NULL;
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

char peek(struct stack *top)
{
    if(top==NULL)
        return '$';
    return top->data;
}

int getPriority(char x)
{
    if(x=='^')
        return 4;
    else if(x=='*' || x=='/')
        return 3;
    else if(x=='%')
        return 2;
    else if(x=='+'|| x=='-')
        return 1;
    else if(x=='(')
        return 0;
    else
        return -1;
}
