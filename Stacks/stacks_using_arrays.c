#include<stdio.h>
#include<stdlib.h> 
#include<stdbool.h>

#define SIZE 5

int stack[SIZE];
int top = -1;

bool isEmpty();
bool isFull();
void push();
void pop();
int peak();
void display();

int main()
{
	int choice;
	while(1)
	{
		printf("Stack Operations: \n1. Push \n2. Pop \n3. Display \n4. Exit \n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1: push();
					break;
			case 2: pop();
					break;
			case 3: display();
					break;
			case 4: exit(0);
					break;
			default: printf("Enter valid choice.\n");
		}
	}
}

bool isEmpty()
{
	return top == -1;
}

bool isFull()
{
	return top == SIZE - 1;
}

int peak()
{
	return stack[top];
}

void push()
{
	if(isFull())
	{
		printf("Stack Overflow\n");
	}
	else
	{
		int element;
		printf("Enter element: ");
		scanf("%d", &element);
		top += 1;
		stack[top] = element;
	}
}

void pop()
{
	if(isEmpty())
	{
		printf("Stack Underflow\n");
	}
	else
	{
		printf("Deleted element: %d\n", stack[top]);
		top -= 1;
	}
}

void display()
{
	if(isEmpty())
	{
		printf("Stack is Empty.\n");
	}
	else
	{
		for(int i = top; i >= 0; i--)
		{
			printf("%d \t", stack[i]);
		}
		printf("\n");
	}
}
