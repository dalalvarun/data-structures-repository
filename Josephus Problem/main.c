#include <stdio.h>
#include <conio.h>
#include <malloc.h>
int n,k;
struct node
{
    int player_id;
    struct node *next;
};
struct node *start = NULL;
struct node *prev = NULL;

void enqueue(int i)
{
    struct node *new_node = (struct node *) malloc (sizeof(struct node));
    new_node->player_id = i;
    if(start == NULL)
    {
        start = new_node;
        new_node->next = new_node;
    }
    else
    {
        struct node *ptr = start;
        while(ptr->next != start)
            ptr = ptr->next;
        ptr->next = new_node;
        new_node->next = start;
    }
}
void dequeue()
{
    struct node *ptr = start;
    if(prev == NULL)
    {
        for(int i=0;i<k-1;i++)
            ptr = ptr->next;
        prev = ptr;
        struct node *temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
    }
    else
    {
        for(int i=0;i<k-1;i++)
            prev = prev->next;
        struct node *temp = prev->next;
        prev->next = temp->next;
        free(temp);
    }
}
int main()
{
    printf("\nEnter n:");
    scanf("%i",&n);
    printf("\nEnter k:");
    scanf("%i",&k);
    for(int i=1;i<=n;i++)
        enqueue(i);
    for(int i=0;i<n-1;i++)
        dequeue();
    printf("\nThe winner: ");
    struct node *temp =start;
    while(temp->next!=start)
    {
        printf("%i ",temp->player_id);
        temp = temp->next;
    }

}
