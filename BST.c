#include "BST (1).h"
#include <stdio.h>
#include <stdlib.h>

#define allocCheck(x) \
do \
{  \
if(x==0){ \
printf("allocation faild");\
exit(1);\
}\
else \
return;\
} while (1);

BST* creatNode(int val);
void printTreeInorder(BST* bst);

void initBST(BST* bst)
{
	bst->root = NULL;

}

void insertBST(BST* bst, int value)
{
	if (bst->root == NULL)
	{
		bst = creatNode(value);
		return;
	}
	if (value < bst->root->element)
	{
		if (bst->root->left == NULL) {
			bst->root->left = creatNode(value);
			return;
		}

		else
			insertBST(bst->root->left,value);

	}

	if (value > bst->root->element)
	{
		if (bst->root->right == NULL) {
			bst->root->right = creatNode(value);
			return;
		}

		else
			insertBST(bst->root->right, value);

	}
	

	

}

void printTreeInorder(BST* bst) {
	if (bst == NULL)
	{
		printf("the tree is empty!");
		return -1;
	}
	printTree(bst);
}

void destroyBST(BST* bst)
{
	if (bst == NULL)
	{
		printf("the tree is empty\n");
		return;
	}

	if (bst->root->left == NULL && bst->root->right == NULL)
	free(bst->root);

	else
	{
		if (bst->root->left != NULL)
			destroyBST(bst->root->left);
		
		if (bst->root->right != NULL)
			destroyBST(bst->root->right);
	}
}



int findIndexNFromLast(BST* bst, int N)
{
	if (N > treehigh(bst))
	{
		findIndexNFromLast(bst->root->left->right, N-treehigh(bst));

	}
	int realH = (treehigh(bst) - N);

	if (realH == 0)
	{
		return bst->root->element;
	}

	else
	{
		findIndexNFromLast(bst->root->right, N);

		findIndexNFromLast(bst->root->left, N);
	}

	
	
}
int sameHeightLeaves(BST* bst)
{
	int rHigh = treehigh(bst->root->right);
	int lHigh = treehigh(bst->root->left);
	
	if (rHigh == lHigh)
		return 1;
	else
		return 0;
}
//privet func
BST* creatNode(int val)
{
	BST* newRoot;
	newRoot = (BST*)malloc(sizeof(BST));
	allocCheck(newRoot);
	

	newRoot->root->element = val;
	newRoot->root->left = NULL;
	newRoot->root->right = NULL;
	
	return newRoot;

}

int treehigh(BST* bst)
{
	{
		if (bst == NULL)
			return 0;
		if (bst->root->left == NULL && bst->root->right == NULL)
			return 0;

		int heighL = treehigh(bst->root->left);
		int heighR = treehigh(bst->root->right);
		if (heighL > heighR)
			return 1 + heighL;
		return 1 + heighR;

	}
}

int printTree(BST* bst)
{
	if (bst->root == NULL)
	{
		return;
	}

	else
	{
		printTree(bst->root->left);
		printf("%d", bst->root->element);

		printTree(bst->root->right);

	}
}



int reversInorder(TreeNode* node, int N) {
	if (N == 0) {
		if (node == NULL)
			exit(1);

		return node->element;
	}

	if (node != NULL) {
		reversInorder(node->right, --N);
		reversInorder(node->left, --N);
	}
}
