struct Listnode* detect_cycle(struct Listnode* head)
{
	struct Listnode* fast;
	struct Listnode* slow;
	while(fast!=NULL && fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next
		
		if(fast==slow) break;
	}
	
	slow=head;
	while(slow!=fast)
	{
		fast=fast->next;
		slow=slow->next;
	}
}