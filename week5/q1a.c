#include <stdio.h>
#include <stdlib.h>
#define MAX 30
int topostack[MAX];int n;
int mat[MAX][MAX]={0};
int visited[MAX]={0};
int top=-1;

void push(int x)
{
  if(top<MAX)
  {
    top++;
    topostack[top]=x;
  }
  else 
  {
    printf("Stack Full");exit(1);

  }
}

int pop()
{
  if(top>-1)
  {
    top--;
    return topostack[top+1];
  }
  printf("Error 101:Stack empty");exit(1);
}     
void gettopo(int a)
{

  int i;
  visited[a]=1;
  for(i=0;i<n;i++)
  {
  if(i==a)continue;
  if(mat[a][i]==1 && visited[i]==0)
  gettopo(i);
  }

  push(a);

}
int isEmpty()
{
  if(top==-1)
  return 1;
  return 0;
}

void topological()
{
    int i=0;
    for(i=0;i<n;i++)
    {
      if(visited[i]==0)
      gettopo(i);
    }
    printf("Sorted Order:\n");
    while(!isEmpty())
    {
      printf("%d ",pop());
    }
    printf("\n");
   
}

void addedge(int a,int b)
{
  mat[a][b]=1;
}

int main()
{

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
      if(a<0 || a>=n || b<0 || b>=n){printf("Invalid edge\n");continue;}
      addedge(a,b);      
    }
    else break;
  }
  topological();//By DFS
}