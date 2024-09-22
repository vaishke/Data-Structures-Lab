#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 5

int front = -1;
int rear = -1;
int queue[SIZE];

bool isEmpty();
bool isFull();
void Enqueue();
void Dequeue();
void Display();

int main()
{
	int choice;
	while(1)
	{
        printf("Queue Operations: \n1. Enqueue \n2. Dequeue \n3. Display \n4. Exit \n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1: Enqueue();
					break;
			
			case 2: Dequeue();
					break;
			
			case 3: Display();
					break;
			
			case 4: exit(0);
			
			default: printf("Enter relevant number.\n");
		}
		
	}
}

bool isEmpty()
{
	return (front == -1) || (front == SIZE -1);
}

bool isFull()
{
	return (rear ==  SIZE - 1);
}

void Enqueue()
{
	int element;
	printf("Enter an element: ");
	scanf("%d", &element);
	
	if(front == -1 && rear == -1)
	{
		front = front + 1;
		rear = rear + 1;
		queue[rear] = element;
	}
	
	else if(isFull())
	{
		printf("Queue is full.\n");
	}
	
	else
	{
		rear = rear + 1;
		queue[rear] = element;
	}
	
}

void Dequeue()
{
	if(isEmpty())
	{
		printf("Queue is empty.\n");
	}
	
	else
	{
		printf("Dequeued element: %d \n", queue[front]);
		front = front + 1;
	}
}

void Display()
{
	int i;
	if(isEmpty())
	{
		printf("Queue is empty.\n");
	}
	else
	{
		for(i = front; i <= rear; i++)
		{
			printf("%d \t", queue[i]);
		}
		printf("\n");
	}
}
