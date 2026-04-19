#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void counter_sort(int arry[],int len)
{
	int m=0;
	for(int i=0;i<len;i++)
	{
		if(arry[i]>m)
			m=arry[i];
	}
	
	int *counter=calloc(m,sizeof(int));
	for(int i=0;i<len;i++)
	{
		counter[arry[i]]++;
	}
	
	for(int i=0;i<m;i++)
	{
		counter[i+1]+=counter[i];
	}
	
	int *res=malloc(len * sizeof(int));
	for(int i=len-1;i>=0;i--)
	{
		int num=arry[i];
		res[counter[num]-1]=num;
		counter[num]--;
	}
	
	memcpy(arry,res,len*sizeof(int));
	free(res);
	free(counter);
}


int main() {
    int arr[] = {2, 5, 3, 0, 2, 3, 0, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sorting the array
    counter_sort(arr, n);

    // Printing the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}





