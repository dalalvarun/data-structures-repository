#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#define MAX 50
struct stack
{
    int data;
    struct stack *next;
};
struct stack *top = NULL;
struct stack *push(struct stack *,int);
struct stack *pop(struct stack *);
int peek(struct stack *);
int main()
{
    printf("\nEnter the prefix expression:");
    char input[MAX]="";
    gets(input);
    for(int i=0;i<MAX;i++)
    {
        if(input[i]=='\0')
            break;
        if(isdigit(input[i]))
        {
            int j=i+1;
            int k=0;
            char temp[MAX] = "";
            temp[k] = input[i];
            k++;
            while(isdigit(input[j]))
            {
                temp[k] = input[j];
                k++;
                i++;
                j++;
            }
            int X = atoi(temp);
            top = push(top,X);
        }
        if(input[i]=='+' || input[i]=='-' || input[i]=='/' || input[i]=='*' || input[i]=='%')
        {
            int x = peek(top);
            top = pop(top);
            int y = peek(top);
            top = pop(top);
            switch(input[i])
            {

                case '+':
                    top = push(top,y+x);
                    break;
                case '-':
                    top = push(top,y-x);
                    break;
                case '*':
                    top = push(top,y*x);
                    break;
                case '/':
                    top = push(top,y/x);
                    break;
                case '%':
                    top = push(top, y%x);
                    break;
            }
        }

    }
    int res = peek(top);
    printf("\n%d",res);
    return 0;


}



struct stack *push(struct stack *top, int val)
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

int peek(struct stack *top)
{
    if(top==NULL)
        return 0;
    return top->data;
}
