#include <stdio.h>

void heapify(int arry[], int len , int i )
{
	int largest=i;
	int l = 2*i+1;
	int r = 2*i+2;
	if(l<len && arry[l]> arry[largest])
	{
		largest=l;
	}
	if (r<len  &&  arry[r]>arry[largest])
	{
		largest=r;
	}
	
	if(largest !=i )
	{
		int temp=arry[i];
		arry[i]=arry[largest];
		arry[largest]=temp;	
		
		heapify(arry,len,largest);
	}
	
}

void heapsort(int arry[],int len)
{
	for (int i=len/2-1;i>=0;i--)
	{
		heapify(arry,len,i);
	}
	//before this step , the arry become a sorted heap
	//which has the biggest number top
	//so in next step,we should put the biggest element 
	//of heap into the last of arry.]
	for ( int i = len-1; i>0 ; i-- )
	{
		int temp=arry[0];
		arry[0]=arry[i];
		arry[i]=temp;
		//this step is to renew the heap ,make sure the
		//second and... largest number is on the top.
		heapify(arry,i,0);
	}
}

int main() {
    int arr[] = { 9, 4, 3, 8, 10, 2, 5 };
    int len = sizeof(arr) / sizeof(arr[0]);

    heapsort(arr, len);

    for (int i = 0; i < len; ++i)
        printf("%d ", arr[i]);

    return 0;
}










