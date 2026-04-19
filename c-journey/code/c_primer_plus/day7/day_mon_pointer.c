#include <stdio.h>
#define SIZE  12
int main()
{
	int days[SIZE] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int index;
	
	for (index=0;index<SIZE;index++)
	{
		printf("Month %d has %d days \n", index+1, *(days+index));
	}
	return 0;
}



