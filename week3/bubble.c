#include <stdio.h>
#include <stdlib.h>

void bubblesort(int *arr,int n)
{
	int i,j,temp,opcount=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
				opcount++;
			if(arr[j]>arr[j+1])
			{
				//swap
			
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("opcount= %d\n",opcount);
}


int main(int argc, char const *argv[])
{
	int n,i;
	printf("enter the size of array\n");
	scanf("%d",&n);
	int *arr=(int*)malloc(sizeof(int )*n);
	for(i=0;i<n;i++)
	{
		printf("enter the element\n");
		scanf("%d",&arr[i]);
	}
	bubblesort(arr,n);
	printf("sorted array>>\n");
	for ( i = 0; i < n; i++)

	{
		printf("%d\n",arr[i]);
	}






	return 0;
}
