#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
int digit(int num ,int exp)
{
	return (num/exp)%10;
}

void counting_sort_digit(int arry[],int len,int exp)
{
	int *counter=(int *)malloc(10*sizeof(int));
	memset(counter,0,sizeof(int)*10);
	for(int i;i<len;i++)
	{
		int d = digit(arry[i],exp);
		counter[d]++;
	}
	
	for (int i=1;i<10;i++)
	{
		counter[i]+=counter[i-1];
	}
	
	int *res=(int *	)malloc(len*sizeof(int));
	for(int i=len-1;i>=0;i--)
	{
		int d =digit(arry[i],exp);
		//fatch the number:15 fatch 5
		int j=counter[d]-1;
		res[j]=arry[i];
		counter[d]--;
		
	}
	
	for(int i=0;i<len;i++)
	{
		arry[i]=res[i];
	}
	free(res);
	free(counter);
}

void radix_sort(int arry[],int len)
{
	int max=INT32_MIN;
	/*int max = 0;	❌ 如果数组全是负数，结果错误
    int max = nums[0];	✅ 可行，但需要数组非空
	int max = INT32_MIN;	✅ 最安全，适用于任何情况*/
	
	for(int i=0;i<len;i++)
	{
		if(arry[i]>max)
		{
			max=arry[i];
		}
	}
	
	for(int exp=1;max>exp;exp*=10)
	{
		// 对数组元素的第 k 位执行计数排序
        // k = 1 -> exp = 1
        // k = 2 -> exp = 10
        // 即 exp = 10^(k-1)
        
        counting_sort_digit(arry,len,exp);
	}
}

int main(void)
{
	int arry[]={12,35,68,666,451,256,35545,323,545};
	int len=sizeof(arry)/sizeof(arry[0]);
	if (len==0)
	{
		printf("null");
		return 0;
	}
	radix_sort(arry,len);
	for(int i =0;i<len;i++)
		printf("%d ",arry[i]);
	
	
}


