#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[15];
int top=-1;

void rev_arr(int arr[], int num)
{
    for(int i=0;i<num;i++)
    {
        stack[top+1] = arr[i];
        top = top+1;
    }
}

void display(int top)
{
    for(int i=top;i>=0;i--)
    {
        printf("%d  ",stack[i]);
    }

}

int main()
{
    printf("\nEnter the number of elements in array (max 15):");
    int num;
    scanf("%d",&num);
    int arr[num];
    for(int i=0;i<num;i++)
    {
        printf("\nEnter element %i:",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\nThe array after reversal is as follows:");
    rev_arr(arr,num);
    display(top);
    return 0;
}
