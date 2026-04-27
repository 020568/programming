void insert(BST* bst,int num)
{
	if(bst->root==NULL)
	{
		bst->root=newTreenode(num);
		return;
	}
	
	Treenode* cur=bst->root;
	*pre=NULL;
	
	while(cur!=NULL)
	{
		if(cur->val==num)
		{
			return;
		}
		pre=cur;
		if(cur->val<num)
		{
			cur=cur->right;
		}
		
		if(cur->val>num)
		{
			cur=cur->left;
		}	
	}
	Treenode* node=newTreenode(num);
	if(pre->val<num)
	{
		pre->right=node;
	}
	else if(pre->val>num)
	{
		pre->left=node;
	}
}