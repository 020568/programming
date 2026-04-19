#include <stdio.h>
int search(int arry[], int left , int right , int x)
{
	if (left<=right)
	{
		int mid;
	    mid=left+(right - left)/2;
	    if (arry[mid]==x)
	        return mid;
	    else if (arry[mid]<x)
	        return search(arry, mid+1, right ,x);
	    else if (arry[mid]>x)
	        return search(arry,left ,mid - 1, x);
	}
	
	return -1;

}

int main(void)
{
	int arry[]={};
	int len = sizeof(arry)/sizeof(arry[0]);
    if (len==0)
	{
	    printf("arry is null");	
	    return 0;
	}
//if this part behind the flag , len will be negative number
//there is no bug just because the logic "left<right" don't be 
//passed.
// 
	int flag = search(arry,0,len-1,0);
	if ( flag==-1) 
	    printf("there is no key number");
	else 
	    printf("the index of the key number is :%d\n",flag);
	return 0;	
}
