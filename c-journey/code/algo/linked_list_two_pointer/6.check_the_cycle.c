#include <stdbool.h>

bool hascycle(struct Listnode* head)
{
	struct Listnode* fast;
	struct Listnode* slow;
	while(fast!=NULL && fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
		
		if(slow==fast)
		{
			reutrn true;
		}
	}
	
	return false;
}








