#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct  tree
{
	int key;
	int height;
	struct tree *left,*right;
	
}node;

int max(int a, int b)
{
    return (a > b)? a : b;
}

int height(node *t)
{
	if(t==NULL)
		return 0;
	else
		return t->height;
}
node * newnode(int key)
{
	node *new=(node*)malloc(sizeof(node));
	new->left=NULL;
	new->right=NULL;
	new->key=key;
	new->height=1;
	return new;

}
int balance(node* root)
{
	if(root==NULL)
		return 0;
	else
		return height(root->left)-height(root->right);
}

node *rightRotate(node *y)
{
    node *x = y->left;
    node *temp = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = temp;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}
node *leftRotate(node *x)
{
    node *y = x->right;
    node *temp = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = temp;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}

node* insert(node * root,int key)
{
	if (root == NULL)
        return(newnode(key));
	if (root->key>key)
	{
		root->left=insert(root->left,key);
		
	}
	else if(root->key<key)
		root->right=insert(root->right,key);
	else
		return root;

	 root->height = 1 + max(height(root->left),height(root->right));
	 int bal=balance(root);

	 //check for balance

	 //L.L. case
	 if(bal>1 && key<root->left->key)
	 	return rightRotate(root);
	 //R.R  case
	 else if(bal<-1 && key>root->right->key)
	 	return leftRotate(root);
	 // L R Case
    if (bal > 1 && key > root->left->key)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    // R L Case
    if (bal < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
  
    return root;

}
void preorder(node* root)
{
	if(root!=NULL)
	{
		printf("%d\n",root->key );
		preorder(root->left);
		preorder(root->right);
	}
}

int main(int argc, char const *argv[])
{
	node*root = NULL;
 
 
  root = insert(root, 1);
  root = insert(root, 3);
  root = insert(root, 5);
  root = insert(root, 7);
  root = insert(root, 9);
  //root = insert(root, 25);
  preorder(root);
	return 0;
}