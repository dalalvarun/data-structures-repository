#include <stdio.h>
#include <stdlib.h>
#define MAX 12

int Queue[MAX];
int front1 = -1, rear1 = -1;
int front2 = MAX, rear2 = MAX;

void enqueue_A()
{
    if(rear1+1 == rear2)
    {
        printf("\nOverflow!!!");
        return;
    }
    else
    {
        printf("\nEnter the element you want to enter:");
        int el;
        scanf("%i",&el);
        if(front1==-1 && rear1==-1)
        {
            front1++;
            rear1++;
            Queue[rear1] = el;
        }
        else
        {
            rear1++;
            Queue[rear1] = el;
        }
    }
}
void enqueue_B()
{
    if(rear2-1 == rear1)
    {
        printf("\nOverflow!!!");
        return;
    }
    else
    {
        printf("\nEnter the element to be inserted:");
        int el;
        scanf("%i",&el);
        if(front2==MAX && rear2 == MAX)
        {
            front2--;
            rear2--;
            Queue[rear2] =el;
        }
        else
        {
            rear2--;
            Queue[rear2] = el;
        }
    }
}
void dequeue_A()
{
    if(rear1==-1 && front1==-1)
    {

        printf("\nUndeflow!!!");
        return;
    }
    else if(rear1==front1)
    {
        rear1=-1;
        front1=-1;
    }
    else
    {
        front1++;
    }
    printf("\nElement dequeued successfully!!!");
}

void dequeue_B()
{
    if(rear2==MAX && front2==MAX)
    {
        printf("\nUnderflow!!!");
        return;
    }
    else if(rear2==front2)
    {
        rear2=MAX;
        front2=MAX;
    }
    else
    {
        rear2++;
    }
    printf("\nElement Dequeued successfully!!!");
}

void display_A()
{
    if(front1 ==-1 && rear1==-1)
    {
        printf("\nThe Queue is empty!!!");
        return;
    }
    else
    {
        printf("\nThe Queue is as follows:\n");
        for(int i=front1; i<=rear1;i++)
        {
            printf("%i ",Queue[i]);
        }
    }
}

void display_B()
{
    if(rear2 ==MAX && front2==MAX)
    {
        printf("\nThe Queue is empty!!!");
        return;
    }
    else
    {
        printf("\nThe Queue is as follows:\n");
        for(int i=front2;i>=rear2;i--)
        {
            printf("%i ",Queue[i]);
        }
    }
}
int main()
{
    int decision;
    do
    {
        printf("\n********MAIN MENU********");
        printf("\n 1.Enqueue in Queue A");
        printf("\n 2.Enqueue in Queue B");
        printf("\n 3.Dequeue from Queue A");
        printf("\n 4.Dequeue from Queue B");
        printf("\n 5.Display Queue A");
        printf("\n 6.Display Queue B");
        printf("\n\n Enter your decision:");
        scanf("%i",&decision);
        switch(decision)
        {
            case 1:
                enqueue_A();
                break;
            case 2:
                enqueue_B();
                break;
            case 3:
                dequeue_A();
                break;
            case 4:
                dequeue_B();
                break;
            case 5:
                display_A();
                break;
            case 6:
                display_B();
                break;
        }
    }
    while(decision!=7);

    return 0;
}
