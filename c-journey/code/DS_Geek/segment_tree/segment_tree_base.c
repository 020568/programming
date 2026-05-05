#include <stdio.h>
#include <stdlib.h>

// 全局变量或通过参数传递，这里为了简洁使用全局数组
int *A;  // 原数组
int *ST; // 线段树数组

/**
 * 构建线段树
 * node: 当前线段树节点的编号
 * L, R: 当前节点负责的区间范围
 */
void build(int node, int L, int R) {
    // 叶子节点：区间只包含一个元素
    if (L == R) {
        ST[node] = A[L];
    } else {
        int mid = (L + R) / 2;
        // 递归构建左子树 (2*node)
        build(2 * node, L, mid);
        // 递归构建右子树 (2*node + 1)
        build(2 * node + 1, mid + 1, R);
        
        // 状态转移：父节点存储左右子节点的和
        ST[node] = ST[2 * node] + ST[2 * node + 1];
    }
}

/**
 * 单点更新
 * idx: 要修改的原数组索引
 * val: 增量值
 */
void update(int node, int L, int R, int idx, int val) {
    if (L == R) {
        // 找到叶子节点，进行更新
        A[idx] += val;
        ST[node] += val;
    } else {
        int mid = (L + R) / 2;
        // 判断 idx 在左半区还是右半区
        if (L <= idx && idx <= mid) {
            update(2 * node, L, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, R, idx, val);
        }
        // 更新完子节点后，向上更新父节点的值
        ST[node] = ST[2 * node] + ST[2 * node + 1];
    }
}

/**
 * 区间查询
 * tl, tr: 当前节点负责的区间 (Tree Left, Tree Right)
 * l, r: 用户查询的目标区间 (Query Left, Query Right)
 */
int query(int node, int tl, int tr, int l, int r) {
    // 情况 1：查询区间与当前区间完全不重叠
    if (r < tl || tr < l) {
        return 0;
    }
    // 情况 2：当前区间完全被包含在查询区间内
    if (l <= tl && tr <= r) {
        return ST[node];
    }
    
    // 情况 3：部分重叠，递归查找左右子树
    int tm = (tl + tr) / 2;
    return query(2 * node, tl, tm, l, r) + 
           query(2 * node + 1, tm + 1, tr, l, r);
}

int main() {
    int n = 6;
    int initial_A[] = {0, 1, 3, 5, -2, 3};
    
    // 动态分配内存
    A = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) A[i] = initial_A[i];
    
    // 线段树数组大小通常设为 4*n
    ST = (int*)calloc(4 * n, sizeof(int));

    // 1. 构建
    build(1, 0, n - 1);
    printf("Sum of values in range 0-4 are: %d\n", query(1, 0, n - 1, 0, 4));

    // 2. 更新 (将索引 1 的值增加 100)
    update(1, 0, n - 1, 1, 100);
    printf("Value at index 1 increased by 100\n");

    // 3. 再次查询
    printf("Sum of value in range 1-3 are: %d\n", query(1, 0, n - 1, 1, 3));

    // 释放内存
    free(A);
    free(ST);
    
    return 0;
}