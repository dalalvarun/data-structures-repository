#include <stdio.h>
#include <stdlib.h>
#define MAX 8

int queue[MAX];
int FRONT=-1, REAR =-1;

void enqueue()
{

    if(REAR == MAX-1)
    {
        printf("\nOverflow!!!");
    }
    else
    {

        if(FRONT==-1)
        {
            FRONT++;
        }
        REAR++;
        int temp;
        printf("\nEnter the element to enter:");
        scanf("%i",&temp);
        queue[REAR] = temp;
        printf("\nThe element was inserted successfully!!!");
    }
}

void dequeue()
{
    if(FRONT==-1 && REAR ==-1)
    {
        printf("\nUnderflow!!!!");
    }
    else if(FRONT==REAR)
    {
        FRONT=-1;
        REAR=-1;
        printf("\nElement removed successfully!!!");
    }
    else
    {

        FRONT++;
        printf("\nElement removed successfully!!!");
    }
}

void peek()
{
    if(FRONT== -1)
        printf("\nThe Queue is empty!!!");
    else
    {
        printf("\nPeek: %i", queue[FRONT]);
    }
}

void display()
{

    if(FRONT==-1 && REAR ==-1)
    {

        printf("\nThe Queue is empty!!!");
    }
    else
    {
        printf("\nThe Queue is as follows:\n");
        for(int i=FRONT; i<=REAR;i++)
        {

            printf(" %i",queue[i]);
        }
    }
}

int main()
{
    int decision;
    do
    {

        printf("\n*********MAIN MENU********");
        printf("\n 1.Insert an Element in the Queue");
        printf("\n 2.Delete an Element in the Queue");
        printf("\n 3.Peek first element");
        printf("\n 4.Display the Queue");
        printf("\n.5.Exit");
        printf("\n Enter your choice:");
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
