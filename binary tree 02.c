#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
};

struct node *root = NULL;

// Insert function
void insert(int item) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->lchild = NULL;
    newNode->rchild = NULL;

    if (root == NULL) { // Tree is empty
        root = newNode;
        return;
    } else {
        struct node *ptr = root;
        struct node *parent = NULL;

        while (ptr != NULL) {
            if (ptr->data == item) {
                printf("Element %d already exists\n", item);
                free(newNode); // Free memory for the new node
                return; // Exit the function
            } else if (ptr->data > item) {
                parent = ptr;
                ptr = ptr->lchild; // Move to the left child
            } else {
                parent = ptr;
                ptr = ptr->rchild; // Move to the right child
            }
        }

        // Insert the new node in the correct position
        if (item < parent->data) {
            parent->lchild = newNode;
        } else {
            parent->rchild = newNode;
        }
    }
}

void search(int item)
{    struct node*ptr;
    ptr=root;
    int flag=0;
    while(ptr!=NULL&& flag==0)
    {
        if(ptr->data==item)
        {
            flag=1;
            break;
        }
        else if(ptr->data>item)
        {
            ptr=ptr->lchild;
            
        }
        else
        {
            ptr=ptr->rchild;
        }
    }
    if(flag==1)
    {
        printf("search found");
    }
    else
    {
        printf("not found");
    }
}

// Inorder traversal function
void inorderTraversal(struct node *root) {
    if (root != NULL) {
        inorderTraversal(root->lchild);
        printf("%d ", root->data);
        inorderTraversal(root->rchild);
    }
}

int main() {
    int size;
    int array[60]; // Declare a fixed-size array

    printf("Enter the number of elements : ");
    scanf("%d", &size);

  

    // Get the elements from the user
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]); // Read each element
    }

    // Insert each element of the array into the BST
    for (int i = 0; i < size; i++) {
        insert(array[i]);
    }
    
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
 int item;
 printf("enter the item ");
 scanf("%d",&item);
 search(item);
    return 0;
}
