#incldue <stdio.h>
#include <stdlib.h>
struct Listnode* midlen(struct Listnode* head)
{
	struct Listnode* slow;
	struct Listnode* fast;
	
	while(fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next;
	}
	return slow;
}


















