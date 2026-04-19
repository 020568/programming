#include <stdio.h>
#define LEN 20

struct names{
	char first[LEN];
	char last[LEN];
	
};

struct guy{
	struct names handle;
	char favfood[LEN];
	char job[LEN];
	int income;
	
};

int main()
{
	struct guy fellow[2] = {
		{
		    {"wang","xu"},"noodles","student",100
		},
		{
			{"wang","peng"},"rice","student",20
		}
	};
	struct guy *him;
	him=&fellow[0];
	char fullname[50];
	sprintf(fullname,"%s %s",him->handle.first,him->handle.last);
	puts(fullname);
	
}

