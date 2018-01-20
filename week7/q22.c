#include <stdio.h>
#include <stdlib.h>

#define MIN(A, B) ((A > B)? B : A)
#define MAX(A, B) ((A > B)? A : B)

typedef struct  tree
{
	int k1,k2;
	
	struct tree *left,*mid,*right;
	
}node,*node_pt;

node_pt new()
{
	node_pt temp=(node_pt)malloc(sizeof(node));
	temp->left=temp->mid=temp->right=NULL;
	temp->k1=-999;
	temp->k2=-999;

}


node_pt searchTree (node_pt tree, int key) {
	if (tree == NULL)
		return NULL;
	if (key == tree->k1 || key == tree->k2)
		return tree;
	if (key < tree->k1)
		return searchTree(tree->left, key);
	else if (key > tree->k2)
		return searchTree(tree->right, key);
	return searchTree(tree->mid, key);
}


node_pt insertItem(node_pt tree,int item)
{
	if (tree == NULL) {
		node_pt node = new();
		node->k1 = item;
		return node;
	}
	if (tree->k1 == -999) {
		tree->k1 = item;
		return tree;
	} else if (tree->k2 == -999) {
		tree->k2 = MAX(item, tree->k1);
		tree->k1 = MIN(item, tree->k1);
		return tree;
	} else {
		if (item < tree->k1) {
			tree->left = insertItem(tree->left, item);
		} else if (item > tree->k2) {
			tree->right = insertItem(tree->right, item);
		} else {
			tree->mid = insertItem(tree->mid, item);
		}
	}

	if (tree->left == NULL && tree->mid == NULL && tree->right == NULL) {
		node_pt leftNode = new();
		node_pt rightNode = new();
		if (item < tree->k1) {
			
			leftNode->k1 = item;
			rightNode->k1 = tree->k2;
		} else if (item > tree->k2) {
			leftNode->k1 = tree->k1;
			tree->k1 = tree->k2;
			rightNode->k1 = item;
		} else {
			leftNode->k1 = tree->k1;
			tree->k1 = item;
			rightNode->k1 = tree->k2;
		}
		tree->k2 = -999;
		tree->left = leftNode;
		tree->mid = rightNode;
		return tree;
	}

	return tree;

}

void inorderTraversal (node_pt root) {
	if (root == NULL)
		return;
	inorderTraversal(root->left);
	if (root->k1 != -999)
		printf(" %d", root->k1);
	inorderTraversal(root->mid);
	if (root->k2 != -999)
		printf(" %d", root->k2);
	inorderTraversal(root->right);
}



int main (int argc, char const * argv []) {

	int x;
	printf("Enter elements one by one, -1 to break: ");

	node_pt tree = NULL;

	do {
		scanf(" %d", &x);
		if (x >= 0)
			tree = insertItem(tree, x);
	} while (x >= 0);

	printf("Inorder: \n");
	inorderTraversal(tree);

	printf("\n\n");

	return 0;

}


