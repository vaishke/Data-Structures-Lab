#include<stdio.h>
#include<stdlib.h>
void insert();
void deletion();
void display();
struct node{
	int data;
	struct node *next;
	struct node *prev;
}*header,*ptr,*ptr1,*ptr2,*news;
int count=0;
int main()
{
	while(1)
	{
		int choice;
		printf("**********MENU**********\n");
		printf("1.Insert\t2.Delete\t3.Display\t4.Exit\n");
		printf("Enetr correct choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insert();break;
			case 2: deletion();break;
			case 3: display();break;
			case 4: exit(0);
			default: printf("Invalid choice.\n");		
		}
	}
}
void insert()
{
	news = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d",&news->data);
	if(header == NULL)
	{
		news->prev = news;
		news->next = news;
		header = news;
	}
	else{
		int pos;
		printf("Enter the position: ");
		scanf("%d",&pos);
		if(pos == 1)
		{
			ptr = header;
			news->prev = ptr->prev;
			ptr2=ptr->prev;
			ptr2->next = news;
			ptr->prev = news;
			news->next = ptr;
			header = news;
		}
		else if(pos == count+1)
		{
			ptr = header;
			for(int i=1;i<pos-1;i++)
			{
				ptr = ptr->next;
			}
			ptr->next = news;
			news->prev = ptr;
			news->next = header;
			header->prev = news;
		}
		else if(pos<1 || pos>count+1)
		{
			printf("Invalid position.\n");
			count--;
		}
		else{
			ptr = header;
			for(int i=1;i<pos-1;i++)
			{
				ptr = ptr->next;
			}
			ptr1 = ptr->next;
			ptr1->prev = news;
			ptr->next = news;
			news->prev = ptr;
			news->next = ptr1;
		}
	}
	count++;
}
void deletion()
{
	if(header == NULL)
		printf("List is empty.\n");
	else{
		int pos;
		printf("Enter the position: ");
		scanf("%d",&pos);
		if(pos<1 || pos>count)
		{
			printf("Invalid position.\n");
		}
		else if(pos == 1 && count == 1)
		{
			header = NULL;
			count--;
		}
		else if(pos == 1)
		{
			ptr = header;
			ptr1 = ptr -> next;
			ptr1 -> prev = ptr -> prev;
			ptr2 = ptr -> prev;
			ptr2 -> next = ptr1;
			printf("%d is deleted\n",ptr->data);
			free(ptr);
			header = ptr1;
			count--;
		}
		else if(pos == count)
		{
			ptr = header;
			for(int i = 1;i < pos - 1; i++)
			{
				ptr = ptr->next;
			}
			ptr1 = ptr->next;
			ptr->next = ptr1->next;
			header->prev = ptr;
			printf("%d is deleted\n",ptr1->data);
			free(ptr1);
			count--;
		}
		else{
			ptr = header;
			for(int i = 1;i < pos - 1; i++)
			{
				ptr = ptr->next;
			}
			ptr1 = ptr->next;
			ptr2=ptr1->next;
			ptr->next = ptr1->next;
			ptr2->prev = ptr;
			printf("%d is deleted\n",ptr1->data);
			free(ptr1);
			count--;
		}
	}
}
void display()
{
	if(header == NULL)
	{
		printf("List is empty.\n");
	}
	
	else{
		int po;
		printf("Enter the position from where to display: ");
		scanf("%d",&po);
		int choice;
		printf("1.From left to right.\t 2.From right to left.\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		if(choice>2 || choice<1 || po<1 || po>count)
		{
			printf("Invalid choice or position.\n");
		}
		else if(choice == 1)
		{
			ptr = header;
			for(int i=1;i<po;i++)
			{
				ptr = ptr->next;
			}
			for(int j = 1;j<=count;j++)
			{
				printf("%d\t",ptr->data);
				ptr = ptr->next;
			}
			printf("\n");
		}
		else{
			ptr = header;
			for(int i=1;i<po;i++)
			{
				ptr = ptr->next;
			}
			for(int j = 1;j<=count;j++)
			{
				printf("%d\t",ptr->data);
				ptr = ptr->prev;
			}
			printf("\n");
		}
	}
}
