#include <stdio.h>
#include <stdlib.h>
#define MAX 8

int queue[MAX];

int front =-1 , rear = -1;

void enqueue()
{
    if( (rear+1)%(MAX) == front )
    {
        printf("\nOverflow!!!");
        return;
    }
    printf("\nEnter the element you want to enter:");
    int el;
    scanf("%i",&el);
    if(front==-1 && rear ==-1)
    {
        front++;
        rear++;
        queue[front] = el;
    }
    else
    {
        rear = (rear + 1)%MAX;
        queue[rear] = el;
    }
}

void dequeue()
{
    if(rear==-1 && front ==-1)
        printf("\nUnderflow!!!");
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front= (front+1)%MAX;
    }
}
void peek()
{
    if(rear==-1 && front ==-1)
        printf("\nThe Queue is empty!!!");
    else
        printf("\nPeek: %i",queue[front]);
}

void display()
{

    if(front ==-1 && rear == -1)
    {

        printf("\nThe Queue is empty!!!");
    }
    else
    {
        printf("\nThe Queue is as follows:\n");
        if(front<rear || front==rear)
        {
            for(int i=front;i<=rear;i++)
                printf("%i ",queue[i]);
        }
        else
        {
            for(int i=front;i<MAX;i++)
                printf("%i ",queue[i]);
            for(int i=0;i<=rear;i++)
                printf("%i ",queue[i]);
        }
    }
}
int main()
{
    int decision;
        do
        {
            printf("\n********MAIN MENU********");
            printf("\n 1. Enqueue");
            printf("\n 2. Dequeue");
            printf("\n 3. Peek");
            printf("\n 4. Display");
            printf("\n 5. Exit");
            printf("\nEnter your decision:");
            scanf("%i",&decision);
            switch(decision)
            {
                case 1:
                    enqueue();
                    break;
                case 2:
                    dequeue();
                    break;
                case 3:
                    peek();
                    break;
                case 4:
                    display();
                    break;
            }
        }
        while(decision!=5);
}
