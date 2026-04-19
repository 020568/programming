#include <stdio.h>
/*
If you store from front to back, you have to overwrite a value each time, 
and the overwritten value needs to be stored in a new auxiliary space,
 otherwise you can't assign the next value. 
 If you store from back to front, you only need to store 
 the last value in the extra space.
*/
void insert_sort(int arry[] , int len)
{
	int i ;
	for(i=1;i<len;i++)
	{
		int store = arry[i];
		int j=i-1;
		while (j>=0 && store<arry[j])
		{
			arry[j+1]=arry[j];
			j--;
		}
		arry[j+1]=store;
    }
}

void arry_print(int arry[],int len)
{
	int i ;
	for (i=0;i<len;i++)
	    printf("%d ",arry[i]);
}

int main()
{
	int arr[] = { 12, 11, 13, 5, 6 };
    int len = sizeof(arr) / sizeof(arr[0]);
    if (len==0)
    {
    	printf("null");
    	return 0;
	}
    
    insert_sort(arr, len);
    arry_print(arr, len);

    return 0;
}

