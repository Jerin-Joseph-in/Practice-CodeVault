#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
    int data;
    struct BSTNode *lChild;
    struct BSTNode *rChild;
} BSTNode;

BSTNode *ROOT = NULL;

// Function to create a new node
BSTNode* createNode(int item) {
    BSTNode* new = (BSTNode*)malloc(sizeof(BSTNode));
    new->data = item;
    new->lChild = NULL;
    new->rChild = NULL;
    return new;
}

// BST Search
void BST_Search(int item) {
    BSTNode *ptr = ROOT;
    int flag = 0;

    while (ptr != NULL && flag == 0) {
        if (ptr->data == item) {
            flag = 1;
        } else if (ptr->data < item) {
            ptr = ptr->rChild;
        } else {
            ptr = ptr->lChild;
        }
    }

    if (flag == 1) {
        printf("Search data found\n");
    } else {
        printf("Search data not found\n");
    }
}

// BST Insertion
void BST_Insertion(int item) {
    BSTNode *ptr = ROOT, *parent = NULL;

    while (ptr != NULL) {
        if (item == ptr->data) {
            printf("Item already exists\n");
            return;
        }
        parent = ptr;
        if (item < ptr->data) {
            ptr = ptr->lChild;
        } else {
            ptr = ptr->rChild;
        }
    }

    BSTNode *new = createNode(item);
    if (parent == NULL) {
        ROOT = new;
    } else if (item < parent->data) {
        parent->lChild = new;
    } else {
        parent->rChild = new;
    }
}

// Helper function to find inorder successor
BSTNode* findInorderSuccessor(BSTNode *ptr) {
    BSTNode *current = ptr->rChild;
    while (current && current->lChild != NULL) {
        current = current->lChild;
    }
    return current;
}

// BST Deletion
void BST_Deletion(int item) {
    BSTNode *ptr = ROOT, *parent = NULL;
    int flag = 0;

    // Search for the node to be deleted
    while (ptr != NULL && flag == 0) {
        if (item == ptr->data) {
            flag = 1;
        } else {
            parent = ptr;
            if (item < ptr->data) {
                ptr = ptr->lChild;
            } else {
                ptr = ptr->rChild;
            }
        }
    }

    if (flag == 0) {
        printf("Item does not exist\n");
        return;
    }

    // Node with two children
    if (ptr->lChild != NULL && ptr->rChild != NULL) {
        BSTNode *y = findInorderSuccessor(ptr);
        int successorData = y->data;
        BST_Deletion(y->data);
        ptr->data = successorData;
    } 
    // Node with one or zero children
    else {
        BSTNode *child = (ptr->lChild != NULL) ? ptr->lChild : ptr->rChild;
        if (parent == NULL) {
            ROOT = child;
        } else if (parent->lChild == ptr) {
            parent->lChild = child;
        } else {
            parent->rChild = child;
        }
        free(ptr);
    }
}

// Preorder traversal
void preorderTraversal(BSTNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->lChild);
        preorderTraversal(root->rChild);
    }
}

// Inorder traversal
void inorderTraversal(BSTNode* root) {
    if (root != NULL) {
        inorderTraversal(root->lChild);
        printf("%d ", root->data);
        inorderTraversal(root->rChild);
    }
}

// Postorder traversal
void postorderTraversal(BSTNode* root) {
    if (root != NULL) {
        postorderTraversal(root->lChild);
        postorderTraversal(root->rChild);
        printf("%d ", root->data);
    }
}

int main() {
    // Example usage
    BST_Insertion(50);
    BST_Insertion(30);
    BST_Insertion(70);
    BST_Insertion(20);
    BST_Insertion(40);
    BST_Insertion(60);
    BST_Insertion(80);

    // Search for some values
    BST_Search(30);
    BST_Search(90);

    // Deletion
    BST_Deletion(50);
    BST_Search(50);

    // Traversals
    printf("\nPreorder traversal: ");
    preorderTraversal(ROOT);
    printf("\nInorder traversal: ");
    inorderTraversal(ROOT);
    printf("\nPostorder traversal: ");
    postorderTraversal(ROOT);
    
    return 0;
}
