/*
#include<stdio.h>
#include<stdlib.h>

int isPossible(int arr[],int sum,int n)
{
if(sum<0 || n<0)return 0;
if(sum==0)return 1;
else return (isPossible(arr,sum,n-1)+isPossible(arr,sum-arr[n],n-1));
}
int getsum(int arr[],int n)
{
int sum=0;int i;
	for(i=0;i<n;i++)
		sum=sum+arr[i];
return sum;}
int checkif(int arr[],int n)
{
int i=0;int sum=0;
sum=getsum(arr,n);
if(sum%2==0)return isPossible(arr,sum/2,n-1);
else return 0;
}
int main()
{
int n,sum;int arr[100];
printf("Enter the number of elements to be entered");
scanf("%d",&n);
printf("Enter the elements");
int i;
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
if(checkif(arr,n)==0){printf("Parition of this set is not Possible \n");exit(0);}
sum=getsum(arr,n)/2;
int temp=0,temp2=0;
int p1[100]={0},p2[100]={0};
for(i=0;i<n;i++)
{
if(temp+arr[i] <= sum){temp=temp+arr[i];p1[i]=1;}
else p2[i]=1;
}
int l1=0,l2=0;//char t="";
for(i=0;i<n;i++)
{
	if(p1[i]==1){p1[i]=arr[i];l1++;}
	else {p2[i]=arr[i];l2++;}
}
for(i=0;i<n;i++)
{
	if(p1[i]==0)continue;
	printf("%d ",p1[i]);
}
printf("\n");
for(i=0;i<n;i++)
{
	if(p2[i]==0)continue;
	printf("%d ",p2[i]);
}
printf("\n");

return 0;
}

*/


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
//using namespace std;

int sum;
int opcount;

void printSet(int *a,int x,int n)
{
	int i;
	printf("Set1: \n");
	for( i=0;i<n;i++){
		if((x>>i)&1)
			printf("%d \n",a[i]);
	}
	printf("Set2: \n");
	for(i=0;i<n;i++){
		if(((~x)>>i)&1)
			printf("%d \n",a[i]);
	}
	printf("\n");
}

void partition(int* a,int n){
	double total=pow(2,n-1);
	int val=0,i,x;
	for( i=1;i<total;i++){
		 val=0;
		for( x=0;x<n;x++){
			if((i>>x)&1){
				opcount++;
				val=val+a[x];
				if(val==(sum-val)){
					printSet(a,i,n);
					return;
				}	
			}
		}
	}
	printf("\nNo partition\n");
}



int main(int argc,char** argv){
	// printfargv[0];
	// string _filename=string(argv[0])+".csv";
	int T,i;
	scanf("%d",&T);
	FILE *fp=fopen("partition.csv","a");
    printf("test cases\n");
	while(T--){
		opcount=0;
		int n;
		printf("size\n");//<<endl;
		scanf("%d",&n);
		int *a=(int*)malloc(sizeof(int )*n);
		sum=0;
		printf("enter elements");//<<endl;
		for( i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum=sum+a[i];
		}
		partition(a,n);
		printf("\nOpCount %d",opcount);
		fprintf(fp,"%d,%d\n",n,opcount);
	}

	return 0;
}