#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *new, *header, *ptr, *ptr1;

int count_of_nodes = 0;

void insert();
void delete();
void traverse();

void main()
{
    int choice;

    while(1)
    {
        printf("1. Insert Node \n2. Delete Node \n3. Traverse List \n4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: insert();
                    break;
            
            case 2: delete();
                    break;

            case 3: traverse();
                    break;
            
            case 4: exit(0);

            default: printf("Invalid Number.\n");
        }
    }
}

void insert()
{
    int num;
    new = malloc(sizeof(struct Node));
    
    printf("Enter Number to insert: ");
    scanf("%d", &num);
    new -> data = num;

    if (header == NULL)
    {
        new -> next = new;
        header = new;
        count_of_nodes = count_of_nodes + 1;
    }

    else
    {
        int position;

        printf("Enter position: ");
        scanf("%d", &position);

        if(position < 1 || position > (count_of_nodes + 1))
        {
            printf("Invalid Position.\n");
        }

        else if(position == 1)
        {
            new -> next = header;
            header -> next = new;
            header = new;
            count_of_nodes = count_of_nodes + 1;
        }

        else if(position == (count_of_nodes + 1))
        {
            ptr = header;
            while(ptr -> next != header)
            {
                ptr = ptr -> next;
            }
            ptr -> next = new;
            new -> next = header;
            count_of_nodes = count_of_nodes + 1;
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
            new -> next = ptr;
            count_of_nodes = count_of_nodes + 1;
        }
    }
}

void delete()
{
    if(header == NULL)
    {
        printf("List is Empty.\n");
    }

    else
    {
        int position;
        
        printf("Enter position to be deleted: ");
        scanf("%d", &position);

        if(position < 1 || position > count_of_nodes)
        {
            printf("Invalid Position.\n");
        }

        else if(position == 1)
        {
            ptr = ptr1 =  header;
            while(ptr1 -> next != header)
            {
                ptr1 = ptr1 -> next;
            }
            header = ptr -> next;
            ptr1 -> next = header;
            printf("Deleted Element: %d\n", ptr -> data);
            free(ptr);
            count_of_nodes = count_of_nodes - 1;
        }

        else if(position == count_of_nodes)
        {
            ptr = header;
            for(int i = 1; i < (position - 1); i++)
            {
                ptr = ptr -> next;
            }
            ptr1 = ptr -> next;
            ptr -> next = header;
            printf("Deleted Element: %d\n", ptr1 -> data);
            free(ptr1);
            count_of_nodes = count_of_nodes - 1;
        }

        else
        {
            ptr = header;
            for(int i = 1; i < (position - 1); i++)
            {
                ptr = ptr -> next;
            }
            ptr1 = ptr -> next;
            ptr -> next = ptr1 -> next;
            printf("Deleted Element: %d\n", ptr1 -> data);
            free(ptr1);
            count_of_nodes = count_of_nodes - 1;
        }

    }
}

void traverse()
{
    if(header == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
            ptr = header;
            for(int i = 1; i <= count_of_nodes; i++)
            {
                printf("%d \t", ptr -> data);
                ptr = ptr -> next;
            }
            printf("\n");
    }
}