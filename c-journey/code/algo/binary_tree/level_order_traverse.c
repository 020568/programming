#include <stdio.h>

void level_order_traverse(struct Treenode* root)
{
	if(root==NULL)
		return;
		
		
	struct Treenode* q[1000];
	int front=0;
	int rear=0;
	q[rear++]=root;
	
	while(front<rear)
	{
		struct Treenode* cur =q[front++];
		
		printf("%d\n",cur->val);
		
		if(cur->left!=NULL)
		{
			q[rear++]=cur->left;
		}
		if(cur->right!=NULL)
		{
			q[rear++]=cur->right;
		}
	}
	
}










