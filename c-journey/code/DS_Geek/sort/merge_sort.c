#include <stdio.h>
void divide_conquer(int arry[],int l , int m , int r)
{
	int i;
	int j;
	int len1=m-l+1;
	int len2=r-m;
	int a1[len1];
	int a2[len2];
	
	for(i=0;i<len1;i++)
	{
		a1[i]=arry[l+i];
	}
	
	for(j=0;j<len2;j++)
	{
		a2[j]=arry[m+1+j];
	}
	
	i=0;
	j=0;
	int k=l;
	while(i<len1 && j<len2)
	{
		if(a1[i]<=a2[j])
		{
			arry[k]=a1[i];
			i++;
		}
		else
		{
			arry[k]=a2[j];
			j++;
		}
		k++;
	}
	
	while(i<len1)
	{
		arry[k]=a1[i];
		k++;
		i++;
	}
	
	while(j<len2)
	{
		arry[k]=a2[j];
		k++;
		j++;
	}
	
}

void merge_sort(int arry[] , int l , int r)
{
	if(l<r)
	{
		int m =l+(r-l)/2;
		merge_sort(arry,l,m);
		merge_sort(arry,m+1,r);
		
		
		divide_conquer(arry,l,m,r);

	}
}


int main(){
    
    int arry[] = {38, 27};
    int arr_size = sizeof(arry) / sizeof(arry[0]);

    merge_sort(arry, 0, arr_size - 1);
    int i;
    for (i = 0; i < arr_size; i++)
        printf("%d ", arry[i]);
    printf("\n");
    
    return 0;
}


