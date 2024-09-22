#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *new, *header, *ptr, *ptr1;

int i;
int count = 0;

void insert();
void delete();
void display();

int main()
{
    int choice;

    while(1)
    {
        printf("1. Insert Node \n2. Delete Node \n3. Display \n4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {   
            case 1: insert();
                break;

            case 2: delete();
                break;

            case 3: display();
                break;

            case 4: exit(0);

            default: printf("Enter Valid element.\n");
        }
    }   
}

void insert()
{
    int num;
    new = malloc(sizeof(struct Node));

    printf("Enter element: ");
    scanf("%d", &num);
    new -> data = num;

    if(header == NULL)
    {
        header = new;
        new -> next = NULL;
        count  = count + 1;
        
    }
    
    else
    {
        int position;
        printf("Enter position to enter: ");
        scanf("%d", &position);

        if(position < 1 || position > (count + 1))
        {
            printf("Invalid Position. \n");
        }
        
        else if(position == 1)
        {
            ptr = header;
            header = new;
            new -> next = ptr;
            count = count + 1;
        }
        
        else if(position == (count + 1))
        {
            ptr = header;
            new -> next = NULL;
            while(ptr -> next != NULL)
            {
                ptr = ptr -> next;
            }
            ptr -> next = new;
            count = count + 1;
        }

        else
        {
            ptr = header;
            for(int i = 1; i < (position - 1); i++)
            {
                ptr = ptr -> next;
            }
            ptr1 = ptr -> next;
            ptr -> next = new;
            new -> next = ptr1;
            count = count + 1;
        }
    }
}   

void delete()
{
    if(header == NULL)
    {
        printf("List is empty\n");
    }

    else
    {
        int position;

        printf("Enter position to delete: ");
        scanf("%d", &position);

        if(position < 1 || position > count)
        {
            printf("Invalid position. \n");
        }

        else if(position == 1)
        {
            printf("Deleted Element: %d \n", header -> data);
            ptr = header;
            header = header -> next;
            free(ptr);  
            count = count - 1;
        }

        else if(position == count)
        {
            ptr = header;
            while(ptr -> next != NULL)
            {
                ptr1 = ptr;
                ptr = ptr -> next;
            }
            printf("Deleted Element: %d \n", ptr -> data) ;
            ptr1 -> next = NULL;
            free(ptr);
            count = count - 1;
        }

        else
        {
            ptr = header;
            for(i = 0; i < position - 1; i++)
            {
                ptr1 = ptr;
                ptr = ptr -> next;
            }
            printf("Deleted Element: %d \n", ptr -> data);
            ptr1 -> next = ptr -> next;
            free(ptr);
            count = count - 1;
        }
    }   
}

void display()
{
    if(header == NULL)
    {   
        printf("List is empty \n");
    }
    else
    {
        ptr = header;
        while(ptr != NULL)
        {
            printf("%d \t", ptr -> data);
            ptr = ptr -> next;
        }
        printf("\n");   
    }
}