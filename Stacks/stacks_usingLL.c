#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void display();

struct node
{
	int data;
	struct node *link;
} *top, *new, *ptr;


int main()
{
	top = NULL;
	int choice;
	while(1)
	{
		printf("1. Push \n2. Pop \n3. Display \n4. Exit \n");
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
			default: printf("Enter valid choice");
		}
	}
	
}

void push()
{
	int element;
	printf("Enter element: ");
	scanf("%d", &element);
	
	new = malloc(sizeof(struct node));
	new -> data = element;
	new -> link = top;
	top = new;
}

void pop()
{
	if(top == NULL)
	{
		printf("The stack is Empty.\n");
	}
	else
	{
		printf("Deleted element: %d\n", top -> data);
		top = top -> link;
	}
}

void display()
{
	if(top == NULL)
	{
		printf("The stack is empty.\n");
	}
	else
	{
		for(ptr = top; ptr != NULL; ptr = ptr -> link)
		{
			printf("%d\t", ptr -> data);
		}
		printf("\n");
	}
}