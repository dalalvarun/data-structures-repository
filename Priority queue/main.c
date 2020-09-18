#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    int prio;
    struct node *next;
};

struct node *start = NULL;

void enqueue()
{
    struct node *ptr = (struct node *) malloc(sizeof(struct node ));
    if(ptr==NULL)
    {
        printf("\nOverflow!!!");
        return;
    }
    else
    {
        int element, priority;
        printf("\n Enter the element to be inserted in the Priority Queue:");
        scanf("%i", &element);
        printf("\n Enter the priority of the element:");
        scanf("%i",&priority);
        ptr->data = element;
        ptr->prio = priority;
        if(start==NULL)
        {
            start = ptr;
            ptr->next = NULL;
        }
        else
        {
            struct node *temp = start;
            if(start->prio > priority)
            {
                ptr->next = start;
                start = ptr;
                return;
            }
            while(temp->next!= NULL && temp->next->prio <=priority )
                temp = temp->next;
            if(temp->next==NULL)
            {
                temp->next = ptr;
                ptr->next = NULL;
            }
            else
            {
                ptr->next = temp->next;
                temp->next = ptr;
            }
        }
        printf("\nElement enqueued successfully!!!");
    }
}
void dequeue()
{
    if(start == NULL)
    {
        printf("\nUnderflow!!!");
        return;
    }
    else if(start->next == NULL)
    {
        free(start);
        start = NULL;
    }
    else
    {
        struct node *temp = start;
        start = start->next;
        free(temp);
    }
    printf("\nElement dequeued successfully!!!");
}

void display()
{
    if(start==NULL)
    {
        printf("\nThe Priority Queue is empty!!!");
        return;
    }
    else
    {
        struct node *ptr = start;
        printf("\nThe Priority Queue is as follows: \n");
        while(ptr!=NULL)
        {
            printf("%i [%i] ",ptr->data,ptr->prio);
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
        printf("\n Welcome to Priority Queue");
        printf("\n 1.Enqueue");
        printf("\n 2.Dequeue");
        printf("\n 3.Display");
        printf("\n 4.Exit");
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
                display();
                break;
        }
    }
    while(decision!=4);
}
