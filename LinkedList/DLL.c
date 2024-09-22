#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *previous, *next;
} *new, *header, *ptr, *ptr1, *ptr2;

void insert();
void delete();
void traversal();

int count = 0;

int main()
{
	int choice;

	while(1)
	{
		printf("*****Double Linked List*****\n	");
		printf("1. Insert Node \n2. Delete Node \n3. Traverse List \n4. Exit \n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1: insert();
				break;

			case 2: delete();
				break;

			case 3: traversal();
				break;

			case 4: exit(0);

			default: printf("Enter valid choice.\n");
		}
	}
}

void insert()
{
	int position;
	int num;
	new = malloc(sizeof(struct Node));
	
	printf("Enter element: ");
	scanf("%d", &num);
	new -> data = num;

	if(header == NULL)
	{
		new -> previous = NULL;
		new -> next = NULL;
		header = new;
		count = count + 1;
	}

	else
	{
		printf("Enter position to enter: ");
		scanf("%d", &position);
		
		if(position < 1 || position > (count + 1))
		{
			printf("Invalid Position.\n");
		}

		else if(position == 1)
		{
			new -> previous = NULL;
			new -> next = header;
			header -> previous = new;
			header = new;
			count = count + 1;
		}

		else if(position == (count + 1))
		{
			ptr = header;
			while(ptr -> next != NULL)
			{
				ptr = ptr -> next;
			}
			ptr -> next = new;
			new -> previous = ptr;
			new -> next = NULL;
			count = count + 1;
		}

		else
		{
			for(int i = 1; i < (position - 1); i++)
			{
				ptr = ptr -> next;
			}
			
			ptr1 = ptr -> next;
			ptr -> next = new;
			ptr1 -> previous = new;
			new -> previous = ptr;
			new -> next = ptr1;
			count = count + 1;
		}
	}
}

void delete()
{
	int position;
	printf("Enter position to delete: ");
	scanf("%d", &position);

	if(header == NULL)
	{
		printf("List is empty.\n");
	}
	
	else
	{
		ptr = header;

		if(position < 1 || position > count)
		{
			printf("Invalid Position.\n");
		}	
		
		else if(position == 1)
		{
			ptr = header;
			header = ptr -> next;
			if(header != NULL)
			{
				header -> previous = NULL;
			}
			free(ptr);
			count = count - 1;
		}
		
		else if(position == count)
		{
			while(ptr != NULL)
			{
				ptr = ptr -> next;
			}
			ptr1 = ptr -> previous;
			ptr1 -> next = NULL;
			free(ptr);
			count = count - 1;
		}

		else
		{
			ptr = header;
			for(int i = 1; i < position; i++)
			{
				ptr = ptr -> next;
			}
			ptr1 = ptr -> previous;
			ptr2 = ptr -> next;
			ptr1 -> next = ptr2;;
			if(ptr2 != NULL)
			{
				ptr2 -> previous = ptr1;
			}
			free(ptr);
			count = count - 1;
		}
	}
}

void traversal()
{
	if(header == NULL)
	{
		printf("List is empty.\n");
	}

	else
	{
		int choice;
		printf("1. Traverse \n2. Reverse Traversal \n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		if(choice == 1)
		{
			ptr = header;
			while(ptr != NULL)
			{
				printf("%d \t", ptr -> data);
				ptr = ptr -> next;
			}
			printf("\n");
		}

		else if(choice == 2)
		{
			ptr = header;
			while(ptr -> next != NULL)
			{
				ptr = ptr -> next;
			}
			
			while(ptr != NULL)
			{
				printf("%d \t", ptr -> data);
				ptr = ptr -> previous;
			}
			printf("\n");
		}

		else
		{
			printf("Invalid Choice.");
		}

	}	
}
