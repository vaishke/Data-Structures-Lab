#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

void DFS(int adj[][SIZE], int visited[], int start)
{
    int s[SIZE];
    int top = -1, i, k;

    for(k = 0; k < SIZE; k++)
    {
        visited[k] = 0;
    }

    s[++top] = start;
    visited[start] = 1;
     
     while(top != -1)
     {
        start = s[top--];
        printf("%c--", start + 65);

        for(i = 0; i < SIZE; i++)
        {
            if(adj[start][i] && visited[i] == 0)
            {
                s[++top] = 1;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int visited[SIZE] = {0};
    int adj[SIZE][SIZE], i, j;
    int ch, size;

    while(1)
    {
        printf("\nMAIN MENU \n");
        printf("1. Enter values to enter into adjacency matrix: \n");
        printf("2. DFS Traversal \n");
        printf("3. Exit \n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: printf("Enter values into adjacency matrix: \n");
                    for(i = 0; i < SIZE; i++)
                    {
                        for(j = 0; j < SIZE; j++)
                        {
                            scanf("%d", &adj[i][j]);
                        }
                    }
                    break;
            case 2: printf("BFS Traversal \n");
                    DFS(adj, visited, 3);
                    break;
            case 3: exit(0);
            default: printf("Enter valid choice. \n");
        }
    }
}