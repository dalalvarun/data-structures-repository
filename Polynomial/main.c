#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

struct node
{
    int coef;
    int pow;
    struct node *next;
};

struct node *start1 = NULL;
struct node *start2 = NULL;
struct node *start3 = NULL;
struct node *start4 = NULL;


struct node *add(struct node *);
struct node *display(struct node *);
struct node *add_two(struct node *,struct node *,struct node *);
struct node *sub_two(struct node *,struct node *,struct node *);
int main()
{
    int option;
    do
    {
        printf("\n*****MAIN MENU*****");
        printf("\n 1.Add first polynomial");
        printf("\n 2.Display first polynomial");
        printf("\n 3.Add second polynomial");
        printf("\n 4.Display second polynomial");
        printf("\n 5.Add the polynomials");
        printf("\n 6.Subtract the polynomials");
        printf("\nEnter your choice:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                start1 = add(start1);
                break;
            case 2:
                start1 = display(start1);
                break;
            case 3:
                start2 = add(start2);
                break;
            case 4:
                start2 = display(start2);
                break;
            case 5:
                start3 = add_two(start1, start2,start3);
                display(start3);
                break;
            case 6:
                start4 = sub_two(start1,start2,start4);
                display(start4);
                break;
        }
    }while(option!=7);
}
struct node *add(struct node *start)
{
   printf("\nEnter the order of polynomial:");
   int order;
   scanf("%d",&order);
   for(int i=order;i>=0;i--)
   {
       struct node *new_node = (struct node *) malloc(sizeof(struct node *));
       printf("\nEnter the coefficient of power %d:",i);
       int c;
       scanf("%d",&c);
       new_node->coef = c;
       new_node->pow = i;
       if(start == NULL)
       {
           start = new_node;
           new_node->next = NULL;
       }
       else
       {
           struct node *ptr = start;
           while(ptr->next!=NULL)
            ptr = ptr->next;
           ptr->next = new_node;
           new_node->next = NULL;
       }

   }
   return start;
}
struct node *display(struct node *start)
{
    if(start == NULL)
    {
        printf("\nThe polynomial is empty");
        return start;
    }
    else
    {
        printf("\nThe polynomial is as follows:\n");
        struct node *ptr = start;
        while(ptr->next!=NULL)
        {

           printf("%d * x^ %d ",ptr->coef,ptr->pow);
           if((ptr->next)->coef >=0)
                printf("+ ");
           ptr = ptr->next;
        }
        printf(" %d",ptr->coef);
    }
    return start;
}

struct node *add_two(struct node *start1, struct node *start2, struct node *start3)
{
    int max;
    struct node *ptr1 = start1;
    struct node *ptr2 = start2;
    if(start1==NULL || start2==NULL)
    {
        printf("\nEither of the polynomial is empty");
        return start3;
    }
    if(start1->pow >= start2->pow)
        max = start1->pow;
    else
        max = start2->pow;
    while(max>=0)
    {

        if(ptr1->pow == ptr2->pow)
        {
            struct node *new_node = (struct node *) malloc(sizeof(struct node *));
            new_node->coef = ptr1->coef + ptr2->coef;
            new_node->pow = ptr1->pow;
            if(start3==NULL)
            {
                start3 = new_node;
                new_node->next = NULL;
            }
            else
            {
                struct node *ptr = start3;
                while(ptr->next!=NULL)
                    ptr=ptr->next;
                ptr->next = new_node;
                new_node->next = NULL;
            }
            ptr1= ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr2->pow > ptr1->pow)
        {
            struct node *ptr = start3;
            struct node *new_node = (struct node *) malloc(sizeof(struct node *));
            new_node->coef = ptr2->coef;
            new_node->pow = ptr2->pow;

            if(start3==NULL)
            {
                start3 = new_node;
                new_node->next = NULL;
            }
            else
            {
                while(ptr->next!=NULL)
                    ptr = ptr->next;
                ptr->next = new_node;
                new_node->next = NULL;

            }
            ptr2 = ptr2->next;
        }
        else
        {
            struct node *ptr = start3;
            struct node *new_node = (struct node *) malloc(sizeof(struct node *));
            new_node->coef = ptr1->coef;
            new_node->pow = ptr1->pow;

            if(start3==NULL)
            {
                start3 = new_node;
                new_node->next = NULL;
            }
            else
            {
                while(ptr->next!=NULL)
                    ptr = ptr->next;
                ptr->next = new_node;
                new_node->next = NULL;

            }
            ptr1 = ptr1->next;
        }

        max-=1;

    }
    return start3;
}

struct node *sub_two(struct node *start1,struct node *start2, struct node *start3)
{
    int max;
    struct node *ptr1 = start1;
    struct node *ptr2 = start2;
    if(start1==NULL || start2==NULL)
    {
        printf("\nEither of the polynomial is empty");
        return start3;
    }
    if(start1->pow >= start2->pow)
        max = start1->pow;
    else
        max = start2->pow;
    while(max>=0)
    {

        if(ptr1->pow == ptr2->pow)
        {
            struct node *new_node = (struct node *) malloc(sizeof(struct node *));
            new_node->coef = ptr1->coef - ptr2->coef;
            new_node->pow = ptr1->pow;
            if(start3==NULL)
            {
                start3 = new_node;
                new_node->next = NULL;
            }
            else
            {
                struct node *ptr = start3;
                while(ptr->next!=NULL)
                    ptr=ptr->next;
                ptr->next = new_node;
                new_node->next = NULL;
            }
            ptr1= ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr2->pow > ptr1->pow)
        {
            struct node *ptr = start3;
            struct node *new_node = (struct node *) malloc(sizeof(struct node *));
            new_node->coef = -(ptr2->coef);
            new_node->pow = ptr2->pow;

            if(start3==NULL)
            {
                start3 = new_node;
                new_node->next = NULL;
            }
            else
            {
                while(ptr->next!=NULL)
                    ptr = ptr->next;
                ptr->next = new_node;
                new_node->next = NULL;

            }
            ptr2 = ptr2->next;
        }
        else
        {
            struct node *ptr = start3;
            struct node *new_node = (struct node *) malloc(sizeof(struct node *));
            new_node->coef = (ptr1->coef);
            new_node->pow = ptr1->pow;


            if(start3==NULL)
            {
                start3 = new_node;
                new_node->next = NULL;
            }
            else
            {
                while(ptr->next!=NULL)
                    ptr = ptr->next;
                ptr->next = new_node;
                new_node->next = NULL;

            }
            ptr1 = ptr1->next;
        }

        max-=1;

    }
    return start3;
}
