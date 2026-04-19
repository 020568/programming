#include <stdio.h>
long long  sum(long long n);

int main()
{
	long long n;
	scanf("%lld",&n);
	printf("%lld",sum(n));
}

long long total=0;
int s = 1;
long long sum(long long n)
{
	if (s<=n)
	{
	    total+=s;
	    s++;
	    sum(n);
	}
	return total;
	    
}