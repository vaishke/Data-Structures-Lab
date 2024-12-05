#include<stdio.h>
#include<stdlib.h>

struct treeNode
{
    int data;
    struct treeNode *right;
    struct treeNode *left;
};

void inorder(struct treeNode *root)
{
    inorder(root -> left);
    printf("%d\n", root -> data);
    inorder(root -> right);
}

void preorder(struct treeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d\n", root -> data);
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(struct treeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    printf("%d\n", root -> data);
}

struct treeNode *createNode(int data)
{
    struct treeNode *new = (struct treeNode *) malloc(sizeof(struct treeNode *));
    new -> data = data;
    new -> left = NULL;
    new -> right = NULL;
}

struct treeNode *insertNode(struct treeNode *root, int key)
{
    if(root == NULL)
    {
        return createNode(key);
    }

    else if(key < root -> data)
    {
        root -> left = insertNode(root -> left, key);
    }

    else
    {
        root -> right = insertNode(root -> right, key);
    }

    return root;
}

void searchNode(struct treeNode *root, int key)
{
    if(root == NULL)
    {
        printf("Element not found.\n");
    }
    else
    {
        if(root -> data == key)
        {
            printf("Element found.\n");
        }
        else if(key < root -> data)
        {
            searchNode(root -> left, key);
        }
        else
        {
            searchNode(root -> right, key);
        }
    }
}

struct treeNode *searchMin(struct treeNode *root)
{
    while(root -> left != NULL)
    {
        root = root -> left;
    }
    return root;
}

struct treeNode *searchMax(struct treeNode *root)
{
    while(root -> right != NULL)
    {
        root = root -> right;
    }
    return root;
}

struct treeNode *deleteNode(struct treeNode *root, int value)
{
    if(root == NULL)
    {
        printf("Element not found to delete.\n");
    }

    if(value < root -> data)
    {
        root -> left = deleteNode(root -> left, value);
    }

    else if (value > root -> data)
    {
        root -> right = deleteNode(root -> right, value);
    }

    else
    {
        if(root -> left == NULL && root -> right == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root -> left == NULL)
        {
            struct treeNode *temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL)
        {
            struct treeNode *temp = root -> left;
            free(root);
            return temp;
        }
        else
        {
            int choice;
            printf("Node with two children. Choose replacement strategy.\n");
            printf("1. In-order predecessor ie left subtree max\n");
            printf("2. In-order successor ie right subtree min\n");
            printf("Enter your choice: \n");
            scanf("%d", &choice);

            if(choice == 1)
            {
                struct treeNode *temp = searchMax(root -> left);
                root -> data = temp -> data;
                root -> left = deleteNode(root -> left, temp -> data);
            }

            else if(choice == 2)
            {
                struct treeNode *temp = searchMin(root -> right);
                root -> data = temp -> data;
                root -> right = deleteNode(root -> right, temp -> data);
            }

            else
            {
                printf("Invalid choice. Node deletion aborted.\n");
            }
        }
    }
    return root;
}

int main()
{
    struct treeNode *root;
    root = NULL;
    int choice, value;

    while(1)
    {
        printf("1. Insert \n2. Search \n3. Delete \n4. Inorder \n5. Preorder \n6. Postorder \n7. Exit \n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: printf("Enter value: "); scanf("%d", &value);
                    insertNode(root, value);
                    break;
            case 2: printf("Enter value: "); scanf("%d", &value);
                    if(root -> data == value)
                    {
                        printf("Element found.\n");
                    }
                    else
                    {
                        searchNode(root, value);
                    }
                    break;
            case 3: printf("Enter value: "); scanf("%d", &value);
                    deleteNode(root, value);
                    break;
            case 4: printf("Enter value: "); scanf("%d", &value);
                    if(root == NULL)
                    {
                        printf("BST is empty.\n");
                    }
                    else
                    {
                        inorder(root);
                    }
                    break;
            case 5: printf("Enter value: "); scanf("%d", &value);
                    if(root == NULL)
                    {
                        printf("BST is empty.\n");
                    }
                    else
                    {
                        preorder(root);
                    }
                    break;
            case 6: printf("Enter value: "); scanf("%d", &value);
                    if(root == NULL)
                    {
                        printf("BST is empty.\n");
                    }
                    else
                    {
                        postorder(root);
                    }
                    break;
            case 7: exit(0);
                    break;
            default: printf("Enter valid choice.\n"); 
        }
    }
}