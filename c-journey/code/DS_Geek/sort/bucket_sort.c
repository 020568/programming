#include <stdio.h>
#include <stdlib.h>
//1.先放裁判（比较函数）
int compare(const void* a, const void* b) {
    float fa = *(const float*)a;
    float fb = *(const float*)b;
    return (fa > fb) - (fa < fb);
}

void bucket_sort(float arry[],int len)
{
	int k = len/2;
	int *sizes = malloc(k * sizeof(int));
	float **bucket = (float **) malloc(k*sizeof(float*));
	
	for(int i=0;i<k;i++)
	{
		bucket[i]=malloc(len * sizeof(float));
		sizes[i]=0;
	}
	
	for(int i=0;i<len;i++)
	{
		int idx = (int)(arry[i]*k);
		bucket[idx][sizes[idx]++] = arry[i];
		//equal with 
		//bucket[idx][size[idx]]=arry[i];
		//size[idx]++;
	}
	
	for(int i = 0;i<k;++i)
	{
		qsort(bucket[i],sizes[i],sizeof(float),compare);
	}
	
	int idx=0;
	for(int i =0;i<k;i++)
	{
		for(int j =0;j<sizes[i];j++)
		{
			arry[idx]=bucket[i][j];
			idx++;
		}
		free(bucket[i]);
	}

	free(sizes);
	free(bucket);
}


int main(void)
{
	float arry[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
	int len=sizeof(arry)/sizeof(arry[0]);
	bucket_sort(arry,len);
	for(int i =0;i<len;i++)
	{
		printf("%.4f " , arry[i]);
	}
}









