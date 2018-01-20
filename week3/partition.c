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
void getpartition(int sum,int p1[],int p2[],int n,int x,int arr[])
{
int i,temp=0;

for(i=0;i<n;i++)
{
p1[i]=0;p2[i]=0;}
for(i=x;i<n;i++)
{
//printf("%d\n",i);
if(temp+arr[i] <= sum){temp=temp+arr[i];p1[i]=1;p2[i]=0;}
else {p2[i]=1;p1[i]=0;}
}
if(temp!=sum)getpartition(sum,p1,p2,n,x+1,arr);
//else printf("%d\n",x);
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
getpartition(sum,p1,p2,n,0,arr);
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
