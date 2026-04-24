#include <stdio.h>

void traverse(struct Treenode* root,int* depth,int* res)
{
	if(root==NULL)
	{
		return;
	}
	
	(*depth)++;
	
	if(root->left==NULL && root->right==NULL)
	{
		*res=*depth>*res ? *depth:*res;
	}
	
	traverse(root->left,depth,res);
	traverse(root->right,depth,res);
	
	(*depth)--;
	
}

int maxdepthsize(struct Treenode* root)
{
	int depth=0;
	int res=0;
	traverse(root,&depth,&res);
	return res;
}








