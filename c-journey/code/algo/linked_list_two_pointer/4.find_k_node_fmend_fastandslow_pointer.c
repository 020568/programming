struct Listnode* fromend(struct Listnode* head,int k)
{
	struct Listnode* p1=head;
	for(int i=0;i<k;i++)
	{
		p1=p1->next;
	}
	
	struct Listnode* p2=head;
	while(p1->next!=NULL)
	{
		p1=p1->next;
		p2=p2->next;
	}
	
	return p2;
}