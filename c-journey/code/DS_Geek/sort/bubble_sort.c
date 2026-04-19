#include <stdio.h>
#include <stdbool.h>
void swap(int * left , int * right);
void bubble_sort(int arry[],int len);
void arry_print(int arry[],int len);

//use adress because when void end , and no return ,the 
//type of int will be destoryed .
void swap(int * left , int * right)
{
	int temp= * left;
	*left=*right;
	*right=temp;
}

void bubble_sort(int arry[],int len)
{
	int i;
	bool swapped;
	while(len>=2)
	{
		swapped=false;
		for(i=0;i<len-1;i++)
	    {
		    if(arry[i]>arry[i+1])
		    {
		    	swap(&arry[i],&arry[i+1]);
		    	swapped=true;
			}
		        
	    }
	    if (!swapped) return;
	    len=len-1;	
	}

}

void arry_print(int arry[],int len)
{
	int i ;
	for(i=0;i<len;i++)
	    printf("%d ",arry[i]);
}

int main()
{
	int arry[]={1,2,3};
	int len = sizeof(arry)/sizeof(arry[0]);
	if(len == 0)
	{
	    printf("arry is null");
	    return 0 ;		
	}
	
	bubble_sort(arry,len);
	arry_print(arry,len);

}

