#include <stdio.h>
int search(int arry[],int len , int x)
{
	int i ;
	for ( i =0; i < len ; i++)
	{
		if (arry[i] == x)
		{
			printf("the key number's index is : %d\n",i);
			return 1;
		}
		
	}
	/*if (arry[len-1] !=x)
	{
		printf("the key number is not in this arry.\n");
		when the interate is end,straightly print this part,
		because if we compare again ,it will wrong when the arry
		is empty.
		
		
		return 0 ;
	}
	return 0;*/
	printf("the key number is not in this arry.\n");
	return 0;
}

int main()
{
	int arry[0] = {};
	int len =sizeof(arry)/sizeof(arry[0]);
	search(arry,5,0);
	// when you put 5 in len ,the arry will be 5 , and if you
	//find 0,it will return 1!!!
	search(arry,len,0);
}







