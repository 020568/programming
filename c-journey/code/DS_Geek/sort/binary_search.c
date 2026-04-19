#include <stdio.h>
int search(int arry[], int len , int x)
{
	int right = len-1;
	int left = 0;
	while (left<=right)
	{
		int mid = left + (right-left)/2;
		if(arry[mid]==x)
		{
			return mid;
		}
		else if (arry[mid]<x)
		{
			left = mid +1;
		}
		else if (arry[mid]>x)
		{
			right = mid -1;
		}
	}
	return -1;
	 
}

int main(void)
{
	int arry[] = {1,2,5,23,35,45,65};
	int len;
	len = sizeof(arry)/sizeof(arry[0]);
	
	printf("the key number's index is:%d\n",search(arry,len,5));
}








