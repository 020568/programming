#include <stdio.h>
#include <stdlib.h>

int fibRec(int n, int* memo) {
    // 基础情况
    if (n <= 1) return n;

    // 查备忘录
    if (memo[n] != -1) return memo[n];

    // 计算、记录、返回
    memo[n] = fibRec(n - 1, memo) + fibRec(n - 2, memo);
    return memo[n];
}

int fib(int n) {
    // 动态分配备忘录并初始化为 -1
    int* memo = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) memo[i] = -1;

    int result = fibRec(n, memo);

    free(memo); // 别忘了释放内存
    return result;
}

int main() 
{
    int n = 5;
    printf("%d", fib(n));
    return 0;
}