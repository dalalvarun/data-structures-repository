#include <stdio.h>
#include <stdlib.h>
#define MAX 8

int queue[MAX];
int FRONT=-1, REAR =-1;

void enqueue(int x)
{
    if(REAR = MAX-1)
    {

        printf("Overflow!!!");
        return;
    }
    else if(FRONT == -1 && REAR ==-1)
    {
        FRONT++;
        REAR++;
    }
    else
    {
        REAR++;
    }
    queue[REAR] = x;
    return;
}

void dequeue()
{
    if(FRONT ==-1 || FRONT>REAR)
    {
        printf("\nUnderflow!!!");
    }
    else
    {

        FRONT++;
    }
    return;
}

void peek()
{
    if(REAR==-1)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("%d",queue[REAR]);
    }
}

void display()
{
    if(REAR == -1 || FRONT>REAR)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\nThe Queue is as follows:\n");
        for(int i=FRONT;i<=REAR;i++)
        {
            printf("%d ",queue[i]);
        }
    }
}

int main()
{
    int choice;
    int val;
    do
    {
        printf("\n************MAIN MENU***************");
        printf("\n1.Insert an Element");
        printf("\n2.Delete an Element");
        printf("\n3.Peek");
        printf("\n4.Display");
        printf("\n5.EXIT");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the element to be inserted:");
                scanf("%d",&val);
                enqueue(val);
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

    }while(choice!=5);
}
