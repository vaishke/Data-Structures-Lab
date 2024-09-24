#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

bool isEmpty();
bool isFull();
void enqueue();
void dequeue();
void display();

int main()
{
    int choice;

    while(1)
    {
        printf("***** Circular Queue *****\n");
        printf("1. Insert\t2. Delete\t3. Display\t4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}

bool isEmpty()
{
    return front == -1;
}

bool isFull()
{
    return front == (rear + 1) % SIZE;
}

void enqueue()
{
    if(isFull())
    {
        printf("full");
    }

    else if(isEmpty())
    {
        int element;
        printf("Enter element: ");
        scanf("%d", &element);
        front = rear = 0;
        queue[rear] = element;
    }

    else
    {
        int element;
        printf("Enter element: ");
        scanf("%d", &element);
        rear = (rear + 1) % SIZE;
        queue[rear] = element;
    }
}

void dequeue()
{
    if(isEmpty())
    {
        printf("queue is empty.\n");
    }

    else
    {
        printf("Dequeued: %d\n", queue[front]);
        front = (front + 1) % SIZE;
    }
}

void display()
{
    int i = front;
    while(i != rear)
    {
        printf("%d", queue[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d", queue[rear]);
}