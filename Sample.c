#include<stdio.h>
#include<stdlib.h>

struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
}

struct treeNode *inorder(struct treeNode *root)
{
    inorder(root -> left);
    printf("%d", root -> data);
    inorder(root -> right);
}

struct treeNode *preorder(struct treeNode *root)
{
    if(root == NULL)
    {
        printf("Empty.\n");
    }
    printf("%d", root -> data);
    inorder(root -> left);
    inorder(root -> right);
}

struct treeNode *postorder(struct treeNode *root)
{
    if(root == NULL)
    {
        printf("empty.\n");
    }
    inorder(root -> left);
    inorder(root -> right);
    printf("%d", root -> data);
}

struct treeNode *createNode(int key)
{
    struct treeNode *new = (struct treeNode *) malloc(sizeof(struct treeNode *));
    new -> data = key;
    new -> left = NULL;
    new -> right = NULL;
}

struct treeNode *insert(int key, struct treeNode *root)
{
    if(root == NULL)
    {
        return createNode(key);
    }

    else if(key < root -> data)
    {
        root -> left = insert(key, root -> left);
    }

    else(key > root -> data)
    {
        root -> right = insert(key, root -> right);
    }

    return root;
}

void search(int key, struct treeNode *root)
{
    if(root == NULL)
    {
        printf("Tree is empty.\n");
    }

    else
    {
        if(key == root -> data)
        {
            printf("found");
        }

        else if(key < root -> data)
        {
            search(key, root -> left);
        }

        else(key > root -> data)
        {
            search(key, root -> right);
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

struct treeNode *delete(int key, struct treeNode *root)
{
    
}