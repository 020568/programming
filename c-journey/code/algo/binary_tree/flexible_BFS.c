#include <stdio.h>

struct state
{
	struct Treenode* node;
	int depth;
}

void level_order_traverse(struct Treenode* root)
{
	if(root!=NULL)
	{
		return;
	}
	
	struct state q[1000];
	int front=0;
	int rear=0;
	q[rear++]=(struct state){root,1};
	
	
	while(front<rear)
	{
		struct state cur=q[front++];
		if(cur.node->left!=NULL)
		{
			q[rear++]=(struct state){cur.node->left,cur.depth+1};
		}
		if(cur.node->right!=NULL)
		{
			q[rear++]=(struct state){cur.node->right,cur.depth+1};
		}
	}
}














