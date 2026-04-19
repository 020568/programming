#include <stdio.h>
#define Slen 40
#define Lim 5
int main()
{
	const char *mytalents[Lim] =
	{
		"Adding numbers swiftly",
		"Multiplying accurately",
		"Following instruction to the letter",
		"Understanding the C language",
		"Stashing data"
	};
	
	char yourtalents[Lim][Slen] = 
	{
		"Walking in a straight television",
		"Sleeping",
		"Watching televison",
		"Mailing letters",
		"Reading email"
	};
	int i;
	puts("Let's compare talents.");
	printf("%-36s %-25s\n","My Talents" , "Your Talents");
	for(i=0;i<Lim;i++)
	    printf("%-36s %-25s\n",mytalents[i],yourtalents[i]);
	printf("\nsizeof mytalents is %zd , sizeof yourtalents is %zd ",sizeof(mytalents),sizeof(yourtalents));
	/*Cross-platform compatibility: The actual size of size_t may vary from 
	platform to platform (e.g., 32-bit system vs. 64-bit system). 
	Using %zd can ensure that the value of this type is printed correctly.*/
	
	return 0 ;
}






