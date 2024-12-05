#include<stdio.h>
#include<stdlib.h>

#define SIZE 17

int bucket;
int hashtable[SIZE];

int Hash(int key)
{
    return key % SIZE;
}

int reHash(int key)
{
    return (key + 1) % SIZE;
}

int insert()
{
    int data;
    int count = 0;
    scanf("%d", &data);

    bucket = Hash(data);

    if(bucket >= SIZE)
    {
        bucket = 0;
    }

    while(hashtable[bucket] != 0)
    {
        bucket = reHash(bucket);
        count++;

        if(count >= SIZE)
        {
            printf("Memory Full! No space available for storage.\n");
            break;
        }
    }

    if(hashtable[bucket] == 0)
    {
        hashtable[bucket] = data;
    }

    printf("Data is stored at index %d", bucket);
}

void search()
{
    int key, i;
    int isFound = 0;

    printf("Enter the key to search: ");
    scanf("%d", &key);

    for(int i = 0; i < SIZE; i++)
    {
        if(hashtable[i] == key)
        {
            isFound = 1;
            break;
        }
    }

    if(isFound == 1)
    {
        printf("The key is found at index %d", i);
    }

    else
    {
        printf("No record found.\n");
    }
}

void delete()
{
    int i, key, isFound = 0;

    printf("Enter the key to delete: ");
    scanf("%d", &key);

    for(int i = 0 ; i < SIZE; i++)
    {
        if(hashtable[i] == key)
        {
            isFound = 1;
            break;
        }
    }

    if(isFound == 1)
    {
        hashtable[i] = 0;
        printf("The key has been deleted.\n");
    }

    else
    {
        printf("No record found.\n");
    }
}

void display()
{
    printf("Contents of hash table are: \n");
    for(int i = 0; i < SIZE; i++)
    {
        if(hashtable[i] != 0)
        {
            printf("H[%d]:%3d   ", i, hashtable[i]);
        }
    }
}

int main()
{
    int choice;

    for(int i = 0; i < SIZE; i++)
    {
        hashtable[i] == 0;
    }

    printf("The size of the Hash table is %d\n", SIZE);
    printf("1. Insert \n2. Search \n3. Delete \n4. Display \n5. Exit \n");

    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: insert();
                    break;
            case 2: search();
                    break;
            case 3: delete();
                    break;
            case 4: display();
                    break;
            case 5: exit(0);
            default: printf("Enter valid choice. \n");
        }
    }
}