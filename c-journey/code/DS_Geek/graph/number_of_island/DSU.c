#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// --- 并查集 (DSU) 结构定义 ---
typedef struct {
    int *parent;
    int *rank;
    int n;
} DisjointSet;

// 初始化 DSU
DisjointSet* createDSU(int n) {
    DisjointSet* ds = (DisjointSet*)malloc(sizeof(DisjointSet));
    ds->parent = (int*)malloc(n * sizeof(int));
    ds->rank = (int*)malloc(n * sizeof(int));
    ds->n = n;
    for (int i = 0; i < n; i++) 
	{
        ds->parent[i] = i; // 每个点的初始父节点是自己
        ds->rank[i] = 0;   // 初始秩为 0
    }
    return ds;
}

// 查找操作 (带路径压缩)
int find(DisjointSet* ds, int x) 
{
    if (ds->parent[x] != x)
	{
        ds->parent[x] = find(ds, ds->parent[x]); // 递归并压缩路径
    }
    return ds->parent[x];
}

// 合并操作 (按秩合并)
void unite(DisjointSet* ds, int x, int y) {
    int rootX = find(ds, x);
    int rootY = find(ds, y);

    if (rootX != rootY) {
        if (ds->rank[rootX] < ds->rank[rootY]) {
            ds->parent[rootX] = rootY;
        } else if (ds->rank[rootX] > ds->rank[rootY]) {
            ds->parent[rootY] = rootX;
        } else {
            ds->parent[rootY] = rootX;
            ds->rank[rootX]++;
        }
    }
}

// 释放内存
void freeDSU(DisjointSet* ds) {
    free(ds->parent);
    free(ds->rank);
    free(ds);
}

// --- 核心计算函数 ---

int countIslands(int rows, int cols, char grid[rows][cols]) {
    int totalCells = rows * cols;
    DisjointSet* ds = createDSU(totalCells);

    // 8 个方向的变化量
    int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

    // 遍历网格进行合并
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 'L') {
                int currIdx = r * cols + c; // 二维转一维索引
                
                for (int i = 0; i < 8; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 'L') {
                        unite(ds, currIdx, nr * cols + nc);
                    }
                }
            }
        }
    }

    // 统计独立的根节点数量
    // 在 C 中我们用一个数组记录哪些根已经被统计过了
    int *rootCounted = (int*)calloc(totalCells, sizeof(int));
    int islandCount = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 'L') {
                int root = find(ds, r * cols + c);
                if (rootCounted[root] == 0) {
                    islandCount++;
                    rootCounted[root] = 1; // 标记该岛屿已计数
                }
            }
        }
    }

    free(rootCounted);
    freeDSU(ds);
    return islandCount;
}

int main() {
    char grid[5][5] = {
        {'L', 'L', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'W', 'W'},
        {'L', 'W', 'L', 'L', 'W'}
    };

    int result = countIslands(5, 5, grid);
    printf("Number of Islands: %d\n", result);

    return 0;
}