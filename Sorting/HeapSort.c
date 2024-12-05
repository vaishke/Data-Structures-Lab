#include<stdio.h>
#include<stdlib.h>

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && a[left] > a[largest])
    {
        largest = left;
    }

    if(right < n && a[right] > a[largest])
    {
        largest = right;
    }
}