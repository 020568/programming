#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct Arry
{
	int * pbase;
	int len;
	int cnt;
};

void init_arry(struct Arry * ,int length);
_Bool is_empty(struct Arry * );
_Bool is_full(struct Arry * );
void show_arry(struct Arry * );
_Bool append_arry(struct Arry * , int val);
_Bool insert_arry(struct Arry * , int pos , int val );
_Bool delete_arry(struct Arry * parr,int n , int *pval);
_Bool inversion_arry(struct Arry * );



int main(void)
{
	int val;
	struct Arry arry;
	init_arry(&arry,6);
	show_arry(&arry);
	append_arry(&arry,5);
	append_arry(&arry,5);
	append_arry(&arry,5);
	append_arry(&arry,5);
	append_arry(&arry,5);
	insert_arry(&arry,2,3);
	printf("%d",delete_arry(&arry,1,&val));
	show_arry(&arry);
}

void init_arry(struct Arry *parr , int length)
{
	parr->pbase = (int *) malloc(sizeof(int) * length);
	if(parr->pbase == NULL)
	{
		printf("Wrong");
		exit(-1);
	}
	else
	{
		parr->len = length;
		parr->cnt = 0;
	}
}

_Bool is_empty(struct Arry * parr)
{
	if (parr-> cnt == 0)
	    return 1;
	else
	    return 0; 
}

_Bool is_full(struct Arry * parr)
{
	if (parr->cnt == parr->len)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void show_arry(struct Arry * parr)
{
	if (is_empty(parr))
	{
		printf("arry is empty \n");
	}
	else
	{
		int i;
		for(i=0;i<parr->cnt;++i)
		    printf("%d     ",parr->pbase[i]);
	}
}

_Bool append_arry(struct Arry * parr ,int val)
{
	if(is_full(parr) )
	{
		printf("arry is full!");
		return 0;
	}
	else//zhuijia
	{
		parr-> pbase[parr->cnt] = val;
		(parr->cnt)++;  //相当于定义了cnt为数组的有效元素的个数。
		return 1;
	}
}

_Bool insert_arry(struct Arry * parr , int pos , int val )
{
	int i;
	if(is_full(parr))
	    return 1;
	if (pos<1 || pos> parr->cnt+1)
	    return 0;
	
	for(i=parr->cnt-1 ; i>= pos-1 ; --i)//before pos
	{
		parr->pbase[i+1]=parr->pbase[i];
		
	}
	parr->pbase[pos-1] = val;
	parr->cnt++;
	return 1;
}

_Bool delete_arry(struct Arry * parr , int pos , int *pval)
{
	int i;
	if (is_empty );
	{
		return 0;
	}
	if (pos<1||pos>parr->cnt)
	    return 0;
	*pval=parr->pbase[pos-1];
	for(i=pos;i<parr->cnt ; ++i)
	    parr->pbase[i-1]=parr->pbase[i];
	parr->cnt--;
	return 1;


}










