#include <stdio.h>
int main()
{
	int i;
	char beep='\a';
	for(i=1;i<=3;i++)
	{
		printf("%c",beep);
		getchar();
	}
	
	
}