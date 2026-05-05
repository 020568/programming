#include <stdio.h>
#include <stdlib.h>
long long solve(int n,long long* memo)
{
	if(n<=1)
	{
		return 1;
	}
	
	if(memo[n]!=-1)
	{
		return memo[n];
	}
	
	memo[n]=solve(n-1,memo)+solve(n-2,memo);
	return memo[n];
}

int main() {
    int n = 100; // 假设我们要算爬到 100 级的方法
    
    // 动态分配备忘录空间
    long long* memo = (long long*)malloc((n + 1) * sizeof(long long));
    
    // 初始化 memo，-1 表示还没算过
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }

    printf("%lld\n",solve(n, memo));

    free(memo);
    return 0;
}
