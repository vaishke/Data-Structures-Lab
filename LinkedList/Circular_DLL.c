#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *previous, *next;
} *new, *header, *ptr, *ptr1, *ptr2;

int count_of_nodes = 0;

void insert();
void delete();
void traverse();

int main()
{
    int choice;

    while(1)
    {
        printf("*****Circular Double Linked List*****\n");
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

            default: printf("Invalid Choice.\n");
        }
    }
}

void insert()
{
    int num;
    new = malloc(sizeof(struct Node));

    printf("Enter Number: ");
    scanf("%d", &num);
    new -> data = num;

    if(header == NULL)
    {
        new -> previous = new;
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
            ptr = header;
            while(ptr -> next != header)
            {
                ptr = ptr -> next;
            }
            ptr -> next = new;
            new -> previous = ptr;
            new -> next = header;
            header -> previous = new;
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
            ptr1 = ptr -> next;
            ptr1 -> next = new;
            new -> previous = ptr1;
            new -> next = header;
            header -> previous = new;
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
            ptr1 -> next = new;
            new -> previous = ptr1;
            new -> next = ptr;
            ptr -> previous = new;
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

        printf("Enter position to delete: ");
        scanf("%d", &position);

        if(position < 1 || position > count_of_nodes)
        {
            printf("Invalid Position.\n");
        }

        else if(position == 1)
        {
            ptr = header;
            for(int i = 1; i < (position - 1); i++)
            {
                ptr = ptr -> next;
            }
            ptr1 = header -> next;
            ptr2 = ptr -> next;
            ptr -> next = ptr1;
            ptr1 -> previous = ptr;
            free(ptr2);
            count_of_nodes = count_of_nodes - 1;
        }

        else if(position == count_of_nodes)
        {
            ptr = header;            
            for(int i = 1; i < (position - 1); i++)
            {
                ptr = ptr -> next;
            }
            ptr2 = ptr -> next;
            ptr -> next = header;
            header -> previous = ptr;
            free(ptr2);
            count_of_nodes = count_of_nodes - 1;
        }

        else
        {
            ptr = header;            
            for(int i = 1; i < (position - 1); i++)
            {
                ptr = ptr -> next;
            }
            ptr2 = ptr -> next;
            ptr1 = ptr2 -> next;
            ptr -> next = ptr1;
            ptr1 -> previous = ptr;

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
        int choice;
        printf("*****Traversal*****\n");
        printf("1. Traversal \n2. Reverse Traversal \n");
        scanf("%d", &choice);

        if(choice == 1)
        {
            ptr = header;
            for(int i = 1; i <= count_of_nodes; i++)
            {
                printf("%d \t", ptr -> data);
                ptr = ptr -> next;
            }
            printf("\n");    
        }

        else if(choice == 2)
        {
            ptr = header;
            for(int i = 0; i < count_of_nodes; i++)
            {
                ptr = ptr -> next;
            }

            while(ptr != header)
            {
                printf("%d \t", ptr -> data);
                ptr = ptr -> previous;
            }
            printf("\n");
        }

        else
        {
            printf("Invalid Choice.\n");
        }
    }
}