#include <stdio.h>

int maxdepth(struct Treenode* root)
{
	if(root==NULL)
		return;
		
		
	int leftmax=maxdepth(root->left);
	int rightmax=maxdepth(root->right);
	
	return 1+(leftmax>rightmax? leftmax:rightmax);
}










