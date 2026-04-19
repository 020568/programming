//based linked list
#include <stdio.h>
#include <assert.h>
typedef struct listnode
{
	int val;
	struct listnode *next;
}listnode;

typedef struct linked_list_queue{
	listnode * front ,*rear;
	int quesize;
}linked_list_queue;

linked_list_queue*  new_linked_list_queue()
{
	linked_list_queue * queue=(linked_list_queue *)malloc(sizeof(linked_list_queue));
	queue->front=NULL;
	queue->rear =NULL;
	queue->quesize=0;
	return queue;
}

void del_linked_list_queue(linked_list_queue *queue)
{
	while(queue->front!=NULL)
	{
		listnode * tmp=queue->front;
		queue->front=queue->front->next;
		free(tmp);
	}
	free(queue);
	
}

int size(linked_list_queue *queue)
{
	return queue->quesize;
}

bool empty(linked_list_queue * queue)
{
	return (size(queue)==0);
}

//push the element into the arry
void push(linked_list_queue *queue,int num)
{
	listnode *node = (listnode *)malloc(sizeof(listnode));
	if(node==NULL)
	{
		return;
	}
	
	node->next=NULL;
	node->val=num;
	
	if(queue->front==NULL)
	{
		queue->rear=node;
		queue->front=node;
	}
	else
	{
		queue->rear->next=node;
		queue->rear=node;
	}
	queue->quesize++;
}

int peek(linked_list_queue * queue)
{
	assert(size(queue) && queue->front);
	return queue->front->val;
}

int pop(linked_list_queue *queue)
{
	int num=peek(queue);
	listnode *tmp = queue->front;
	queue->front=queue->front->next;
	free(tmp);
	queue->quesize--;
	return num;
}


void print_arry(int arry[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d ",arry[i]);
	}
}

//print
void print_linked_list_queue(linked_list_queue * queue)
{
	int *arry=(int *)malloc(sizeof(int)*queue->quesize);
	int i;
	listnode * node;
	for(i=0,node=queue->front;i<queue->quesize;i++)
	{
		arry[i]=node->val;
		node=node->next;
		
	}
	print_arry(arry,queue->size);
	free(arry);
}



