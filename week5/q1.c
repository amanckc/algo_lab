#include<stdio.h>
#include<stdlib.h>
#define MAX 30
int n;
int mat[30][30]={0};
int visited[30]={0};
int queue[30];
int front=-1,rear=-1;
int inedges[30];

int isEmpty()
{
  if(front==-1 || front>rear)return 1;
  else return 0;
}
int delete()
{
    int del;
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }

    del= queue[front];
    front = front+1;
    return del;
}


void insert(int vertex)
{
    if(rear == MAX-1)
        printf("Queue Overflow\n");
    else
    {
        if(front == -1)
            front = 0;
        rear = rear+1;
        queue[rear] = vertex ;
    }
}


void addedge(int a,int b)
{
  mat[a][b]=1;
}
int getedgecount(int a)
{
  int i,j,count=0;
  for(i=0;i<n;i++)
  {
    if(mat[i][a]==1)
    count++;
  }
  return count;
}

void topological()
{
int i,j;
int order[MAX],inedges[MAX];
for(i=0;i<n;i++)
{
  inedges[i]=getedgecount(i);

  if(inedges[i]==0)
  insert(i);
}
int a=0,temp;
while(!isEmpty() && a<n)
{
  temp=delete();
  order[a++]=temp;
  for(i=0;i<n;i++)
  {
    if(mat[temp][i]==1)
    {
      inedges[i]--;
      
    }
    else continue;
    if(inedges[i]==0)insert(i);
  }
}
if(a!=n){printf("Graph has a cycle topological sorting not applicable");exit(1);}
for(i=0;i<n;i++)
printf("%d ",order[i]);
}


int main()
{
//  int n;
  printf("Enter the number of vertices");
  scanf("%d",&n);
  int ch,a,b;
  printf("Enter 1 to add an edge OR 0 when all edges are entered");
  while(1)
  {
    printf("Enter choice?");
    scanf("%d",&ch);
    if(ch==1)
    {
      printf("Enter source:");
      scanf("%d",&a);
      printf("Enter destination");
      scanf("%d",&b);
      addedge(a,b);
    }
    else break;
  }
  topological();//BY Removing
}