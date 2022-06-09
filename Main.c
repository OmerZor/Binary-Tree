
#include "BST (1).h"
#include "TreePrintLibrary (1).h"

void main() 
{
	
	BST bst;
	initBST(&bst);
	insertBST(&bst, 3); 
	insertBST(&bst, 1);
	insertBST(&bst, 2);
	insertBST(&bst, 0);
	insertBST(&bst, 5);
	insertBST(&bst, 4);
	insertBST(&bst, 8);
	insertBST(&bst, 9);
	print_ascii_tree(bst.root);
	printTreeInorder(&bst);
	
	printf("the reutrn val is %d",(findIndexNFromLast(&bst, 3)));


	if (sameHeightLeaves(&bst))
		printf("the tree is in the same high!\n");
	else
		printf("the tree is`nt in the same high\n");
	
	destroyBST(&bst);
}