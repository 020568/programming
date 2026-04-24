#include <stdio.h>

struct Listnode* insert_node(struct Listnode* head1,struct Listnode* head2)
{
	struct Listnode* p1=head1;
	struct Listnode* p2=head2;
	while(p1!=p2)
	{
		p1=p1->next;
		if(p1->next=NULL)
		{
			p1=head2;
		}
		p2=p2->next;
		if(p2->next=NULL)
		{
			p2=head1;
		}
	}
	
	return p1;
}













