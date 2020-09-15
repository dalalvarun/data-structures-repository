#include <stdio.h>
#include <stdlib.h>
struct call_stack
{
    char bracket;
    struct call_stack *next;
};
struct call_stack *top = NULL;
struct call_stack *push(char x);
struct call_stack *pop();
char peek();
int main()
{
    printf("\nEnter an expression:");
    char exp[20];
    gets(exp);
    for(int i=0; i<14;i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i] == '{')
        {
            push(exp[i]);
            continue;
        }
        else if(exp[i]==')' || exp[i]==']' || exp[i] == '}')
        {
            if((peek()=='(' && exp[i]==')') || (peek()=='[' && exp[i]==']') || (peek()=='{' && exp[i]=='}'))
                top = pop();
            else
            {
                printf("\nInvalid Expression!!!");
                return 0;

            }
        }
    }
    if(peek()=='$')
        printf("\nValid Expression!!!");
    else
        printf("\nInvalid Expression!!!");
    return 0;
}
struct call_stack *push(char ip)
{
    struct call_stack *new_el = (struct call_stack *) malloc (sizeof(struct call_stack));
    new_el->bracket = ip;
    if(top==NULL)
    {
        top = new_el;
        new_el->next = NULL;
    }
    else
    {
        new_el->next = top;
        top = new_el;
    }
    return top;

}

struct call_stack *pop()
{
    struct call_stack *ptr = top;
    top = top->next;
    free(ptr);
    return top;

}

char peek()
{
    if(top==NULL)
        return '$';
    return top->bracket;
}
