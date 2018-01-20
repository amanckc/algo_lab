#include <stdio.h>
#include <stdlib.h>

int heapify(int arr[],int j)
{
	int p=j;
	int q=(j-1)/2;
	while(arr[p]>arr[q])
	{
		int x=arr[p];
		arr[p]=arr[q];
		arr[q]=x;
		p=(p-1)/2;
		q=(p-1)/2;//(q-1)/2;
		if(p<0 || q<0)
			break;
	}
}

int main(int argc, char const *argv[])
{
	int count = 1, x = 0;
	int arr[100],i=0;
	for(i=0;i<100;i++)
		arr[i]=-1;
	while(1)
	{
		int element;
		printf("Enter elements \n");
		scanf("%d",&element);
		if(x==0 && arr[x]==-1)
		{
			arr[x]=element;
		}
		else
		{
			if(arr[2*x+1]==-1)
			{
				arr[2*x+1]=element;
				heapify(arr,2*x+1);
			}
			else
			{
				arr[2*x+2]=element;
				heapify(arr,2*x+2);
				x+=1;
			}
		}
		printf("press 0 to exit\n");
		scanf("%d",&element);
		if(element==0)
			break;
		else
			count++;
	}
	printf("display\n");
	for(i=0;i<count;i++)
		printf("%d ",arr[i]);
}