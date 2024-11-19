#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

void BFS(int adj[][SIZE], int visited[], int start)
{
    int q[SIZE], rear = -1, front = -1, i, k;

    for(k = 0; k < SIZE; k++)
    {
        visited[k] = 0;
    }

    q[++rear] = start;
    ++front;
    visited[start] = 1;

    while(rear >= front)
    {
        start = q[front++];
        printf("%c--", start + 65);

        for(i = 0; i < SIZE; i++)
        {
            if(adj[start][i] && visited[i] == 0)
            {
                q[++rear] = i;
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
        printf("2. BFS Traversal \n");
        printf("3. Exit \n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: printf("Enter values into adjacency matrix: \n");
                    for(i = 0; i < SIZE; i++)
                    {
                        for(j = 0; j < SIZE; j++)
                        {
                            scanf("%d", adj[i][j]);
                        }
                    }
                    break;
            case 2: printf("BFS Traversal \n");
                    BFS(adj, visited, 3);
                    break;
            case 3: exit(0);
            default: printf("Enter valid choice. \n");
        }
    }
}