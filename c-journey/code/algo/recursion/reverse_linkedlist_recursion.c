#include <stdio.h>
struct Listnode* reverse_linkedlist(struct Listnode * head)
{
	if(head==NULL || head->next==NULL)
	{
		return head;
	}
	
	struct Listnode* last=reverse_linkedlist(head->next);
	head->next->next=head;
	head->next=NULL;
	
	return last;
	
	
}