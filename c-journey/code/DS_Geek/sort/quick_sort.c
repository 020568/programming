#include <stdio.h>
void swap(int*a,int*b);
void quick_sort(int arry[],int l, int r);

int partition(int arry[],int l , int r)
{
	int pivot = arry[r];
	int i = l-1;
	int j ;
	for(j=l;j<r;j++) //this r is n-1 rather than len. except the last element.
	{
		if (arry[j]<pivot)
		{
			i++;
			swap(&arry[i],&arry[j]);
		}
	}
	swap(&arry[i+1],&arry[r]);
	return i+1;
	
}



void quick_sort(int arry[], int l , int r)
{
	if(l<r)
	{
		int i = partition(arry,l,r);
		quick_sort(arry,l,i-1);
		quick_sort(arry,i+1,r);
	}
}

void swap(int*a,int*b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}










