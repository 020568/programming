#include <stdio.h>
#include <stdlib.h>

void heapSwap(struct Listnode ** a,struct Listnode ** b)
{
	struct Listnode* t=*a;
	*a=*b;
	*b=t;
}

void heapPush(struct Listnode** heap,int* size,struct Listnode* node)
{
	heap[(*size)++]=node;
	int i=*size-1;
	while(i>0 && heap[i]->val<heap[(i-1)/2]->val)
	{
		heapSwap(&heap[i],&heap[(i-1)/2]);
		i=(i-1)/2;
	}
}










