#include <stdio.h>
void selection_sort(int arry[] , int len )
{
	int i ;
	for(i=0;i<len;i++)
	{
		int j ;
		int current_index = i;
		for(j=i+1;j<len;j++)
		{
			if (arry[j]<arry[current_index])
			{
				current_index=j;
			}
		}
		//this step will find the minimum element by changing
		//the current_index
		
		//swap
		int temp;
		temp=arry[i];
		arry[i]=arry[current_index];
		arry[current_index]=temp;
		
	}
	
}

void printfarry(int arry[],int len)
{
	for (int i=0; i<len ;i++)
	{
		printf("%d ",arry[i]);
	}
	printf("\n");
}

int main(void)
{
	int arry[]={64, 25, 12, 22, 11};
	int len =sizeof(arry)/sizeof(arry[0]);
	selection_sort(arry,len);
	printfarry(arry,len);
}







