#include <stdio.h>
#include <stdlib.h>


int opcount=0;
struct Node
{
int data;
struct Node* l;
struct Node* r;
};
typedef struct Node* node;

node getNode(int x)
{
node temp=(node)malloc(sizeof(node));
temp->data=x;
temp->l=NULL;
temp->r=NULL;
}


node searchnode(node root,int x)
{
  if(root==NULL)return NULL;
  if(root->data==x)
  return root;
  node t1=searchnode(root->r,x);
  if(t1==NULL)return searchnode(root->l,x);else return t1;
  //node t2=searchnode(root->l);
//  if(t1==NULL)return t2;
//  else return t1;
}


void insert(node root,int x,int p,int a)
{
node temp=searchnode(root,p);
if(temp==NULL){printf("This parent does not exist in the tree\n");return ;}
if(a==1)
{
  if(temp->l==NULL)temp->l=getNode(x);
  else printf("%d already has a let node\n",p);
}
else
{
  if(temp->r==NULL)temp->r=getNode(x);
  else printf("%d already has a right child",p);
}
}
int getcount(node root)
{
    opcount++;
    if(root==NULL)return 0;
    else return (1+getcount(root->l)+getcount(root->r));
}

int main()
{
int ch,x,p,a,c=0;
node root;
printf("Enter 1 to add another element or 0 to end entering\n");
while(1)
{
  printf("Enter chocie?");
  scanf("%d",&ch);
  if(ch==0)break;
  printf("Enter the number?");
  scanf("%d",&x);
  if(c==0){c++;root=getNode(x);continue;}
  printf("Enter parent value:");
  scanf("%d",&p);
  printf("1-left child OR 2-right child:");
  scanf("%d",&a);
  insert(root,x,p,a);
}
printf("%d",getcount(root));
}