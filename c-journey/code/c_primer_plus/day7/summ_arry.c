#include <stdio.h>
#define SIZE    10

int sum(int arry[],int n);
int main()
{
	int arry[SIZE] = {20,10,5,39,4,16,19,26,31,20};
	long answer;
	answer = sum(arry,SIZE);
	printf("The total number of arry is %d. \n",answer);
	printf("The size of arry is %zd bytes. \n",sizeof arry);
	return 0;
	
}

int sum(int arry[], int n)
{
	int i ;
	int total=0;
	for(i=0;i<SIZE;i++)
	{
		total+=arry[i];
    }
    printf("The size of ar is %zd bytes. \n", sizeof arry);//sizeof ar :ar is a pointer,8bit
    return total;
}



