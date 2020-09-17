#include <stdio.h>
#include <stdlib.h>
# define MAX 8
int queue[MAX];
int front =-1;
int rear = -1;

void enqueue_right()
{
    if((rear+1)%MAX == front)
    {
        printf("\nOverflow!!!");
        return;
    }
    else
    {
        int el;
        printf("\nEnter the element you want to enter:");

        scanf("%i",&el);
        if(front==-1 && rear == -1)
        {
            front++;
            rear++;
            queue[rear] = el;
        }
        else
        {
            rear = (rear+1)%MAX;
            queue[rear] = el;
        }
    }

}

void enqueue_left()
{
    if((rear+1)%MAX == front)
    {
        printf("\nOverflow!!!");
        return;
    }
    else
    {
        int el;
        printf("\nEnter the element you want to enter:");
        scanf("%i",&el);
        if(front==-1 && rear ==-1)
        {

            front++;
            rear++;
            queue[rear] = el;
        }
        else
        {
            front = (MAX + front-1)%MAX;
            queue[front]=el;
        }
    }
}

void dequeue_left()
{
    if(front==-1 && rear ==-1)
    {
<<<<<<< HEAD
        printf("\nUnderflow!!!");
=======
        printf("\nUndeflow!!!");
>>>>>>> 9c6a159e13af88f445e6c83c4db04ef3322af9dc
        return;
    }
    else if(front == rear)
    {
        front =-1;
        rear=-1;
    }
    else
    {
        front = (front+1)%MAX;
    }
     printf("\nElement Dequeued from left successfully!!!");
}

void dequeue_right()
{
    if(front==-1 && rear ==-1)
    {
        printf("\nUnderflow!!!");
        return;
    }
    else if(front == rear)
    {
        front =-1;
        rear= -1;
    }
    else
    {
        rear = (MAX +rear -1)%MAX;
    }
     printf("\nElement Dequeued from right successfully!!!");
}

void display()
{
    if(front==-1 && rear == -1)
    {
        printf("\nThe queue is empty!!!");
    }
    else
    {
        printf("\nThe queue is as follows:\n");
        if(front<=rear)
        {
<<<<<<< HEAD
            for(int i= front;i<=rear;i++)
=======
            for(int i=front;i<=rear;i++)
>>>>>>> 9c6a159e13af88f445e6c83c4db04ef3322af9dc
            {
                printf("%i ", queue[i]);
            }
        }
        else
        {
            for(int i= front;i<MAX;i++)
            {
                printf("%i ",queue[i]);
            }
            for(int i=0;i<=rear;i++)
                printf("%i ",queue[i]);
        }
    }
}
void IR_deque()
{
    int decision;
    do
    {
        printf("\n 1. Enqueue");
        printf("\n 2. Dequeue from Right");
        printf("\n 3. Dequeue from Left");
        printf("\n 4. Display");
        printf("\n 5.Quit");
        printf("\nEnter your decision:");
        scanf("%i",&decision);
        switch(decision)
        {
            case 1:
                enqueue_right();
                break;
            case 2:
                dequeue_right();
                break;
            case 3:
                dequeue_left();
                break;
            case 4:
                display();
                break;
        }

    }
    while(decision!=5);
}

void OR_deque()
{
    int decision;
    do
    {
        printf("\n 1. Enqueue from left");
        printf("\n 2. Enqueue from Right");
        printf("\n 3. Dequeue");
        printf("\n 4. Display");
        printf("\n 5.Quit");
        printf("\nEnter your decision:");
        scanf("%i",&decision);
        switch(decision)
        {
            case 1:
                enqueue_left();
                break;
            case 2:
                enqueue_right();
                break;
            case 3:
                dequeue_left();
                break;
            case 4:display();
                break;
        }

    }
    while(decision!=5);
}
int main()
{
    int decision;
    printf("\n********MAIN MENU********");
    printf("\n 1. Input restricted Deque");
    printf("\n 2. Output restricted Deque");
    printf("\n 3. Exit");
    printf("\n Enter your decision:");
    scanf("%i",&decision);
    switch(decision)
    {
        case 1:
            IR_deque();
            break;
        case 2:
            OR_deque();
            break;
    }
    return 0;
}
