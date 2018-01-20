#include <stdio.h>
#include <stdlib.h>
# include <math.h>
struct node
{
    int key;
    struct node *left, *right;
};
  

struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
  

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

struct node* insert(struct node* node, int key)
{
    
    if (node == NULL) return newNode(key);
 

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   
 

    return node;
}
 
 int diameter(struct node * tree)
{
   
   if (tree == NULL)
     return 0;
 
 
  int lheight = height(tree->left);
  int rheight = height(tree->right);
 
  
  int rdiameter = diameter(tree->right);
    int ldiameter = diameter(tree->left);
 
  
  return max(lheight + rheight + 1, max(ldiameter, rdiameter));
} 
 

int height(struct node* node)
{

   if(node == NULL)
       return 0;
 
   
   return 1 + max(height(node->left), height(node->right));
}
int max(int a, int b)
{
  return (a >= b)? a: b;
}     

int main()
{
   
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root,110);
    insert(root,220);
  
   
    inorder(root);


    printf("diameter== %d",diameter(root));
  
    return 0;
}