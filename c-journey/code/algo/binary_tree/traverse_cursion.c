#include <stdio.h>
struct Treenode
{
	int val;
	struct Treenode* left;
	struct Treenode* right;
	
}

void traverse(struct Treenode* root)
{
	if(root==NULL)
	{
		return;
	}
	
	// pre-order position
    traverse(root->left);
    // in-order position
    traverse(root->right);
    // post-order position
}












