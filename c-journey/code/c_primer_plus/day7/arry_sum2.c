#include <stdio.h>
#define SIZE    4
int sum(int *start , int *end);
int main(void)
{
	int arry [SIZE] = {20,10,10,10};
	long answer;
	answer = sum(arry, arry+SIZE);
	printf("The total number of arry is %ld. \n",answer);
	return 0;
}

int sum(int *start , int *end)//start is an adress ,*start is a value of first number of arry
{
	int total=0;
	while (start<end)
	{
		total += *start;
		start++;
	}
	return total;
}


