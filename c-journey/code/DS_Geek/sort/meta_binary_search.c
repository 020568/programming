#include <stdio.h>
int meta_binary_search(int A[], int n, int target) {
    int pos = 0;
    int k = 0;
    
    // 1. 先计算最大的步长 (找到最大的 2^k < n)
    // 比如 n=10, 步长就是 8, 4, 2, 1
    while ((1 << (k + 1)) <= n) {
        k++;
    }

    // 2. 从大步长往小步长试探
    for (int i = k; i >= 0; i--) {
        int next_pos = pos + (1 << i); // 尝试往右跳 2^i 步
        
        // 如果跳到的位置没越界
        if (next_pos < n) {
            if (A[next_pos] == target) return next_pos; // 运气好直接撞上
            
            if (A[next_pos] < target) {
                pos = next_pos; // 目标还在右边，确定这个落脚点
            }
            // 如果 A[next_pos] > target，我们什么都不做，下一轮步长变小再试
        }
    }

    // 3. 最后检查一下落脚点是不是目标
    return (A[pos] == target) ? pos : -1;
}