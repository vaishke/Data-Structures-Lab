#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node *link;
} *new, *front, *rear, *ptr;

bool isEmpty();
void enqueue();
void dequeue();
void display();

int main()
{
    int choice;
    front = NULL;
    rear = NULL;

    while(1)
    {
        printf("*****Queue with Linked List*****\n");
        printf("1. Enqueue \n2. Dequeue \n3. Display \n4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: enqueue();
                    break;
            
            case 2: dequeue();
                    break;
            
            case 3: display();
                    break;
            
            case 4: exit(0);

            default: printf("Invalid Choice.\n");
        }
    }
}

bool isEmpty()
{
    return ((front == NULL) && (rear == NULL));
}

void enqueue()
{
    int element;
    new = malloc(sizeof(struct Node));

    printf("Enter your element: ");
    scanf("%d", &element);
    new -> data = element;
    new -> link = NULL;

    if(isEmpty())
    {
        front = new;
        rear = new;
    }

    else
    {
        rear -> link = new;
        rear = new;
    }
}

void dequeue()
{
    if(isEmpty())
    {
        printf("Queue is empty.\n");
    }

    else
    {
        printf("Delete element: %d\n", front -> data);
        front = front -> link;

        if(front == NULL)
        {
            rear = NULL;
        }
    }
}

void display()
{
    if(isEmpty())
    {
        printf("Queue is empty.\n");
    }

    else
    {
        ptr = front;
        while(ptr != NULL)
        {
            printf("%d\t", ptr -> data);
            ptr = ptr -> link;
        }
        printf("\n");
    }
}