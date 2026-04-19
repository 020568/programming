#include <stdio.h>
#include <stdlib.h>
void counter_sort(int arry[],int len)
{
	//find the max number
	int m=0;
	for(int i=0;i<len;i++)
	{
		if (arry[i]>m)
		{
			m=arry[i];
		}
	}
	
	int *counter = calloc(m+1,sizeof(int));
	for(int i =0;i<len;i++)
	{
		counter[arry[i]]++;	
	}
	
	int i=0;
	for(int num =0 ;num<m+1;num++)
	{
		for(int j =0;j<counter[num];j++)
		{
			arry[i]=num;
			i++;
		}
	}
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












