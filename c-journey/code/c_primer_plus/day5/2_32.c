#include <stdio.h>
int main()
{
	int i;
	long long product=1;
	for(i=1;i<=32;i++)
	{
		product*=2;
	}
	printf("product=%llu",product);
}