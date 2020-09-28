#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define max(a,b) (((a)>(b))?(a):(b))
struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *BST = NULL;
struct node* insert_node(struct node *tree, int val)
{
    if(tree==NULL)
    {
        struct node *temp = (struct node *) malloc(sizeof(struct node));
        temp->data = val;
        temp->right = NULL;
        temp->left = NULL;
        tree= temp;
        return tree;
    }
    else
    {
        struct node *iterator=tree, *parent_iterator = NULL;
        while(iterator!=NULL)
        {
            parent_iterator = iterator;
            if(val<iterator->data)
                iterator = iterator->left;
            else
                iterator = iterator->right;
        }
        struct node * temp = (struct node *) malloc(sizeof(struct node));
        temp->data = val;
        temp->left = temp->right = NULL;
        if(val<parent_iterator->data)
        {
            parent_iterator->left = temp;
        }
        else
        {
            parent_iterator->right = temp;
        }
    }
    return tree;
}

void preOrder(struct node *tree)
{
    if(tree==NULL)
    {
        printf("\nThe BST is empty!!!");
        return;
    }
    printf("%i ",tree->data);
    if(tree->left)
        preOrder(tree->left);
    if(tree->right)
        preOrder(tree->right);
}

void inOrder(struct  node *tree)
{
    if(tree==NULL)
    {
        printf("\nThe BST is empty!!!");
        return;
    }
    if(tree->left)
        inOrder(tree->left);
    printf("%i ",tree->data);
    if(tree->right)
        inOrder(tree->right);
}

void postOrder(struct node *tree)
{
    if(tree==NULL)
    {
        printf("\nThe BST is empty!!!");
        return;
    }
    if(tree->left)
        postOrder(tree->left);
    if(tree->right)
        postOrder(tree->right);
    printf("%i ",tree->data);
}
struct node * smallestElement(struct node *tree)
{
    struct node *temp = tree;
    while(1)
    {
        if(temp->left == NULL)
            break;
        temp = temp->left;
    }
    return temp;
}
struct node * largestElement(struct node *tree)
{
    struct node *temp = tree;
    while(1)
    {
        if(temp->right == NULL)
            break;
        temp = temp->right;
    }
    return temp;
}
struct node *delete_element(struct node *tree, int val)
{
    struct node *iterator = tree, *parentIterator = NULL;
    bool found = false;
    if(iterator->data == val && iterator->left == NULL && iterator->right==NULL)
    {
        free(iterator);
        tree=NULL;
        return tree;
    }
    while(iterator!=NULL)
    {
        if(iterator->data==val)
        {
            found=true;
            break;
        }
        parentIterator = iterator;
        iterator = (val<iterator->data)?iterator->left:iterator->right;
    }
    if(found)
    {
        if(iterator->left && iterator->right)
        {
            //some declarations
            struct node * temp = iterator->left, *pTemp = NULL;

            //iterating to the correct place
            while(1)
            {
                if(temp->right==NULL)
                    break;
                pTemp = temp;
                temp = temp->right;
            }
            iterator->data = temp->data;
            if(pTemp==NULL)
            {
                iterator->left = NULL;
                free(temp);
                return tree;

            }
            if(pTemp->left == temp)
                pTemp->left = NULL;
            else
                pTemp->right = NULL;
            free(temp);
            return tree;

        }
        else if (iterator->left == NULL && iterator->right)
        {
            if(parentIterator==NULL)
            {
                tree = iterator->right;
                free(iterator);
                return tree;
            }
            if(parentIterator->left == iterator)
                parentIterator->left = iterator->right;
            else
                parentIterator->right = iterator->right;
            free(iterator);
            return  tree;
        }
        else if(iterator->right == NULL && iterator->left)
        {
            if(parentIterator==NULL)
            {
                tree = iterator->left;
                free(iterator);
                return tree;
            }
            if(parentIterator->left==iterator)
                parentIterator->left = iterator->left;
            else
                parentIterator->right = iterator->right;
            free(iterator);
            return tree;
        }
        else
        {
            if(parentIterator==NULL)
            {
                free(iterator);
                tree = NULL;
                return  tree;
            }
            if(parentIterator->left ==iterator)
                parentIterator->left = NULL;
            else
                parentIterator->right = NULL;
            free(iterator);
            return tree;
        }
    }
    else
    {
        printf("\nThe BST does not contain element %i",val);
        return tree;
    }

}
int countAll(struct node *tree)
{
    if(tree==NULL)
        return 0;
    else if(tree->left && tree->right)
        return 1 + countAll(tree->left) + countAll(tree->right);
    else if(tree->left && tree->right == NULL)
        return  1 + countAll(tree->left);
    else if (tree->right && tree->left == NULL)
        return 1 + countAll(tree->right);
    else if(tree->left== NULL && tree->right == NULL)
        return 1;
}

int countExternal(struct node *tree)
{
    if(tree==NULL)
        return 0;
    else if(tree->left || tree->right)
    {
        return 0 + countExternal(tree->left) + countExternal(tree->right);
    }
    else
        return 1;
}

int countInternal(struct node *tree)
{
    if(tree==NULL)
        return  0;
    if(tree->left || tree->right)
    {
        return  1 + countInternal(tree->left) + countInternal(tree->right);
    }
    else
        return 0;
}
int countHeight(struct node *tree)
{
    if(tree==NULL)
    {
        return 0;
    }
    else if(tree->left && tree->right)
    {
        return 1 + max(countHeight(tree->left),countHeight(tree->right));
    }
    else if(tree->right)
    {
        return 1 + countHeight(tree->right);
    }
    else if(tree->left)
    {
        return 1 + countHeight(tree->left);
    }
    else
        return 1;
}

struct node *mirrorTree(struct node *tree)
{
    if(tree!=NULL)
    {
        struct node * temp = tree->left;
        tree->left = tree->right;
        tree->right = temp;
        mirrorTree(tree->left);
        mirrorTree(tree->right);
    }
    return tree;
}
struct node *deleteTree(struct node *tree)
{
    if(tree==NULL)
        return tree;
    else
    {
        if(tree->left)
            deleteTree(tree->left);
        if(tree->right)
            deleteTree((tree->right));
        free(tree);

    }
    return  NULL;
}
int main()
{
    int decision, ip;
    struct node *temp;
    do
    {
        printf("\n********MAIN MENU********");
        printf("\n1. Insert node");
        printf("\n2. Pre-Order Traversal");
        printf("\n3. In-order Traversal");
        printf("\n4. Post-Order Traversal");
        printf("\n5. Find the smallest element");
        printf("\n6. Find the largest element");
        printf("\n7. Delete an element");
        printf("\n8. Count the total number of nodes");
        printf("\n9. Count the total number of external nodes");
        printf("\n10. Count the total number of internal nodes");
        printf("\n11. Determine height of the tree");
        printf("\n12.Find mirror image of the tree");
        printf("\n13. Delete the tree");
        printf("\n14. Exit");
        printf("\nEnter your choice:");
        scanf("%i",&decision);
        switch (decision)
        {
            case 1:
                printf("\nEnter the element to be entered:");
                scanf("%i",&ip);
                BST = insert_node(BST,ip);
                break;
            case 2:
                printf("\nThe preorder traversal is as follows:\n");
                preOrder(BST);
                break;
            case 3:
                printf("\nThe inorder traversal is as follows:\n");
                inOrder(BST);
                break;
            case 4:
                printf("\nThe postorder traversal is as follows:\n");
                postOrder(BST);
                break;
            case 5:
                temp = smallestElement(BST);
                printf("\nThe smallest element is : %i",temp->data);
                break;
            case 6:
                temp = largestElement(BST);
                printf("\nThe largest element is: %i",temp->data);
                break;
            case 7:
                printf("\nEnter the element to be deleted:");
                scanf("%i" ,&ip);
                BST = delete_element(BST,ip);
                break;
            case 8:
                ip = countAll(BST);
                printf("\nTotal nodes: %i",ip);
                break;
            case 9:
                ip = countExternal(BST);
                printf("\nExternal Nodes: %i",ip);
                break;
            case 10:
                ip = countInternal(BST);
                printf("\nInternal Nodes: %i",ip);
                break;
            case 11:
                ip = countHeight(BST);
                if(!ip)
                    printf("\nThe BST is empty!!!");
                else
                    printf("\nThe Height of BST is: %i",ip-1);
                break;
            case 12:
                BST = mirrorTree(BST);
                printf("\nTree mirrored successfully!!!");
                break;
            case 13:
                BST = deleteTree(BST);
                break;
            default:
                printf("\nWrong decision! Try Again!");
                break;
        }
    }
    while(decision!=14);

}