#include <stdio.h>
#include <stdlib.h>
 
typedef struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
}node;
int flag=0;
node *create()
{
    node *temp;
    printf("\nEnter data to create bst\n:");
    temp=(node*)malloc(sizeof(node));
    scanf("%d",&temp->data);
    temp->left=temp->right=NULL;
    return temp;
}

void insert(node *,node *);
void preorder(node *);
void postorder(node *);
void inorder(node *);

void searchNode(int i, node **n) 
    { flag=0;
    	if (*n == NULL)
    	    printf("\nValue does not exist in tree!\n");
    	else if((*n)->data == i)
        {
        printf("\nValue found!\n");
        flag=1;
    }
    else if(i > (*n)->data)
        searchNode(i, &((*n)->right));
    else
        searchNode(i, &((*n)->left));
	}

int main()
{
    char ch;
    int trav;
    int search;
    node *root=NULL,*temp;
    node *temp1;
    do
    {
        temp=create();
        if(root==NULL)
            root=temp;
        else    
            insert(root,temp);
        
            
        printf("enter more(y/n)?\n");
        getchar();
        scanf("%c",&ch);
    }
    while(ch=='y'|ch=='Y');
    do{
    printf("which traversal 1:pre 2:post 3:inorder 4:search 5:exit\n");
    scanf("%d",&trav);
    if(trav==1)
    { 
    	printf("nPreorder Traversal: \n");
    	preorder(root);
        printf("...................................\n");
    	//return 0;
    } 
    else if (trav==2)
    {
    	printf("nPostorder Traversal:\n ");
    	postorder(root);
        printf("...................................\n");
    	//return 0;
    }
    else if (trav==3)
    {
    	printf("\nInorder traversal: \n");
    	inorder(root);
        printf("...................................\n");
    	//return 0;
    }
    else if(trav==4)
    {
    	printf("enter the value \n");
    	scanf("%d",&search);
    	searchNode(search,&root);  
        if(flag==0)
        {   printf("value not found ,now it's being inserted\n");
           
            temp1=(node*)malloc(sizeof(node));
    temp1->data=search;
    temp->left=temp->right=NULL;



            insert(root,temp);
        }
        printf("...................................\n");  
	}
   }while(trav!=5);
   return 0;
}


void insert(node *root,node *temp)
{
    if(temp->data<root->data)
    {
        if(root->left!=NULL)
            insert(root->left,temp);
        else
            root->left=temp;
    }
    
    if(temp->data>root->data)
    {
        if(root->right!=NULL)
            insert(root->right,temp);
        else
            root->right=temp;
    }
}

void preorder(node *root)
{
    if(root!=NULL)
    {
        printf("%d \n",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d \n",root->data);
	}
}

void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d \n",root->data);
		inorder(root->right);
	}
}