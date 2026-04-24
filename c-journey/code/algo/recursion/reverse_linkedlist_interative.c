#include <stdio.h>
struct Listnode* reverse(struct Listnode* head)
{
	if(head==NULL || head->next==NULL)
	{
		return head;
	}
	
	struct Listnode *pre,*cur,*nxt;
	pre=NULL;
	cur=head;
	nxt=head->next;
	
	while(cur!=NULL)
	{
		cur->next=pre;
		pre=cur;
		cur=nxt;
		if(nxt->next!=NULL)
		{
			nxt=nxt->next;
		}
	}
	
	return pre;
}