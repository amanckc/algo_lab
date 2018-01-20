#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node *left,*right;
};
typedef struct node *NODE;
NODE head=NULL;

  
  void create(int val)
  {
  	NODE new;
  	if(head==NULL)
  	{
  		new=(NODE) malloc(sizeof(struct node));
  		new->left=new->right=NULL;
  		new->data=val;
  		head=new;

  	}
  	else
  		printf("list alredy exists\n");
  }

void insert(int val ,int before)
{
	NODE temp,newnd;
	temp=head;
	while(temp!=NULL && temp->data!=before)
	{
		temp=temp->right;
	}
	if (temp!= NULL) {
		newnd = (NODE)malloc(sizeof(struct node));
		newnd->left = newnd->right = NULL;
		newnd->data = val;
		if (temp->left != NULL) {
			temp->left->right = newnd;
			newnd->left= temp->left;
			newnd->right = temp;
			temp->left= newnd;
		}
		else {
			newnd->right = temp;
			temp->left= newnd;
			head=newnd;
		}
	}
	else
		printf( "Unable to insert, node with value  %d not found", val);

	
}

void delete(int delVal)
{
	NODE nd,nxtNode;
	nd = head;

	while (nd != NULL) {
		if (nd->data== delVal) {
			if (nd->left != NULL) {
				nd-> left ->right = nd -> right;
				if (nd->right != NULL) {
					nd->right->left = nd->left;
					nxtNode = nd->right;
					free(nd);
					nd = nxtNode;
				}
				else {
					nd->left->right = NULL;
					free(nd);
					nd=NULL;		
				}
				
			}
			else { 
				if (nd->right != NULL) {
					nd ->right->left = NULL;
					head = nd->right;
					free(nd);
					nd = head;
					
				}
				else {
					free(nd);
					head = nd = NULL;
				}
			}
		}
		else
			nd = nd->right;
	}
}

void search(int searchVal) {
	NODE nd;
	nd=head;
	while (nd != NULL) {
		if (nd->data == searchVal)
			printf( "Node is found with key %d\n", searchVal);
		nd = nd->right;
	}
}

void display()
{
	NODE nd;
	nd = head;
	while (nd != NULL) { 
		printf("Node    with val  %d\n", nd->data);
		nd = nd->right;
	}
}
int main()
{
	int ch,data,b4;
	do{
	printf("enter 1 to create\n");
	printf("enter 2 to insert\n");
	printf("enter 3 to delete\n");
	printf("enter 4 to search\n");
	printf("enter 5 to display\n");
	printf("enter 6 to exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:printf("Please enter the node value\n");
                scanf("%d", &data);
                create(data);
                break;
        case 2:printf("Please enter the node value\n");
                scanf("%d", &data);
                printf("Please enter the value of node to be inserted before value\n");
                scanf("%d",&b4);
               insert(data,b4);
                break;    
        case 3:printf("enter the node value to be deleted\n" );            
        		scanf("%d", &data);
        		delete(data);
        		break;
        case 4:printf("enter the vale of node to search\n");
        			scanf("%d", &data);
        			search(data);
        			break;
        case 5:display();
        		break;
        case 6:   break;
        default:printf("Invalid choice ");
                break;		

	}
  }while(ch!=6);

  return 0;

}



