#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue()
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    printf("\nEnter the element to be inserted:");
    int el;
    scanf("%i",&el);
    temp->data = el;
    temp->next = NULL;

    if(front == NULL && rear == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
        rear->next = NULL;
    }
}

void dequeue()
{
    if(front == NULL && rear ==NULL)
    {
        printf("\nUnderflow!!!");
    }
    else if(front==rear)
    {
        free(front);
        front = NULL;
        rear = NULL;
    }
    else
    {
        struct node *temp = front;
        front = front->next;
        free(temp);
    }
}

void peek()
{
    if(front == NULL)
    {
        printf("\nThe queue is empty!!!");
    }
    else
        printf("\n Peek: %i",front->data);
}

void display()
{
    if(front == NULL && rear == NULL)
    {
        printf("\nThe queue is empty!!!");
    }
    else
    {
        struct node *ptr = front;
        printf("\nThe queue is as follows:\n");
        while(ptr!=NULL)
        {
            printf("%i ",ptr->data);
            ptr = ptr->next;
        }
    }
}
int main()
{
    int decision;
    do
    {
        printf("\n********MAIN MENU********");
        printf("\n 1.Enqueue");
        printf("\n 2.Dequeue");
        printf("\n 3.Peek");
        printf("\n 4.Display");
        printf("\n 5.Exit");
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
    return 0;
}
