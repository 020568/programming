#include <stdlib.h>

Treenode* BST(BST* bst,int num)
{
	Treenode* cur=bst->root;
	while(cur!=NULL)
	{
		if(cur->val<num)
		{
			cur=cur->right;
		}
		if(cur->val>num)
		{
			cur=cur->left;
		}
		else
		{
			break;
		}
	}
	
	return cur;
}












