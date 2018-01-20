#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <unistd.h>
#include <limits.h>
int opcount=0;
void min(int a[][4],int i,int n,int *cost,int pre,int *arr)
{
	int j;
	if(i>n-1)
	{
		opcount++;
		if(*cost>pre)
			*cost=pre;
		return;
	}
	for(j=0;j<n;j++)
	{
		opcount++;
		if(arr[j]!=0)
			continue;
		if(pre+a[i][(j)]>*cost)
			return;
		arr[j]=1;
		min(a,i+1,n,cost,pre+a[i][j],arr);
		arr[j]=0;
	}
}




int main(int argc, char const *argv[])
{
	int i,j;
  int a[][4]={{9,2,7,8},{6,4,3,7},{5,8,1,8},{7,6,9,4}};
  int arr[4]={0};
  int cost=65536;
  int pre=0;
  min(a,0,4,&cost,pre,arr);
  printf("the min cost is: %d\n",cost );
  printf("operation count is: %d\n", opcount);
	return 0;
}