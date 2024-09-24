#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

bool isEmpty();
bool isFull()
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
    return ((rear + 1) % SIZE) == front;
}

void enqueue()
{
    int data;

    printf("Enter the data: ");
    scanf("%d", &data);

    // Check if the queue is full
    if(isFull())
    {
        printf("Queue is full.\n");
    }
    else if(isEmpty())  // Inserting the first element
    {
        front = rear = 0;
        queue[rear] = data;
    }
    else
    {
        rear = (rear + 1) % SIZE;
        queue[rear] = data;
    }
}

void dequeue()
{
    // Check if the queue is empty
    if(isEmpty())
    {
        printf("Queue is empty.\n");
    }
    //Last Element Dequeued
    else if(front == rear)
    {
        printf("Dequeued: %d\n", queue[front]);
        front = rear = -1;  // Reset the queue
    }
    else
    {
        printf("Dequeued: %d\n", queue[front]);
        front = (front + 1) % SIZE;
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
        int i = front;
        while(i != rear)
        {
            printf("%d\t", queue[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d\n", queue[rear]);
    }
}
