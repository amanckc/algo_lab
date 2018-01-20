#include <stdio.h>
#include <stdlib.h>
 
void swap(int *a,int*b)
{int temp=*a;
*a=*b;
*b=temp;
}
void heapify(int arr[], int n, int i)
{
    int largest = i;  
    int l = 2*i + 1;  
    int r = 2*i + 2;  
if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {   swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{int i;
    for ( i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);//extract
for ( i=n-1; i>=0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
 
void printArray(int arr[], int n)
{   int i;
    for ( i=0; i<n; ++i)
        printf("%d\n",arr[i] );
}
 
int main()
{
    int arr[100],i,n ;n = sizeof(arr)/sizeof(arr[0]);
    printf("enter the number of elements\n");
    scanf("%d",&n);
    printf("\nEnter the Elements:max 100");
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    heapSort(arr, n);
printf("the sorted array is\n");
    printArray(arr, n);
}