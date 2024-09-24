#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *previous, *next;
} *new, *header, *ptr, *ptr1, *ptr2;

int count = 0;

void insert();
void delete();
void display();

int main()
{
    int choice;
    header = NULL;

    while(1)
    {
        printf("*****Circular DLL*****\n");
        printf("1. Insert \n2. Delete \n3. Display \n4. Exit \n");
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

            default: printf("Invalid choice.\n");
        }
    }
}

void insert()
{
    int element;
    new = malloc(sizeof(struct Node));

    printf("Enter element: ");
    scanf("%d", &element);
    new -> data = element;

    if(header == NULL)
    {
        new -> previous = new;
        new -> next = new;
        header = new;
        count = count + 1;
    }

    else
    {
        int position;
        printf("Enter position: ");
        scanf("%d", &position);

        if(position < 1 || position > (count + 1))
        {
            printf("Invalid position.\n");
        }

        else if(position == 1)
        {
            ptr = header;
            for(int i = 0; i < count; i++)
            {
                ptr = ptr -> next;
            }

            ptr -> next = new;
            new -> previous = ptr;
            new -> next = header;
            header -> previous = new;
            header = new;
            count = count + 1;
        }

        else if(position == (count + 1))
        {
            ptr = header;
            for(int i = 1; i < count; i++)
            {
                ptr = ptr -> next;
            }
            ptr -> next = new;
            new -> previous = ptr;
            new -> next = header;
            header -> previous = ptr;
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
            new -> previous = ptr;
            new -> next = ptr1;
            ptr1 -> previous = new;
            count = count + 1;
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
        printf("Enter your position: ");
        scanf("%d", &position);

        if(position < 1 || position > count)
        {
            printf("Invalid position.\n");
        }

        else if(position == 1)
        {
            ptr = header;
            ptr1 = header -> next;
            for(int i = 1; i < count; i++)
            {
                ptr = ptr -> next;
            }
            ptr -> next = ptr1;
            ptr1 -> previous = ptr;
            printf("Deleted Element: %d\n", header -> data);
            free(header);
            header = ptr1;
            count = count - 1;
        }

        else if(position == count)
        {
            ptr = header;
            for(int i = 1; i < (count - 1); i++)
            {
                ptr = ptr -> next;
            }
            ptr1 = ptr -> next;
            ptr -> next = header;
            header -> previous = ptr;
            printf("Deleted Element: %d\n", ptr1 -> data);
            free(ptr1);
            count = count - 1;
        }

        else
        {
            ptr = header;
            for(int i = 0; i < (position - 1); i++)
            {
                ptr = ptr -> next;
            }
            ptr1 = ptr -> next;
            ptr2 = ptr1 -> next;
            ptr -> next = ptr2;
            ptr2 -> previous = ptr;
            printf("Deleted Element: %d\n", ptr1 -> data);
            free(ptr1);
            count = count - 1;
        }
    }
}

void display()
{
    if(header == NULL)
    {
        printf("List is Empty.\n");
    }

    else
    {
        int choice;
        printf("1. Traverse \n2. Reverse Traverse \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            ptr = header;
            for(int i = 1; i <= count; i++)
            {
                printf("%d\t", ptr -> data);
                ptr = ptr -> next;
            }
            printf("\n");
        }

        else if(choice == 2)
        {
            ptr = header;
            for(int i = 1; i < count; i++)
            {
                ptr = ptr -> next;
            }
            ptr1 = ptr;
            for(int i = 1; i <= count; i++)
            {
                printf("%d\t", ptr1 -> data);
                ptr1 = ptr1 -> previous;
            }
            printf("\n");
        }

        else
        {
            printf("Invalid Choice.\n");
        }
    }
}