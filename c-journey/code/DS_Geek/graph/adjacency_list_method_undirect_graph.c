#include <stdio.h>
#include <stdlib.h>

/**
 * 创建有向图的邻接矩阵
 */
int** createDirectedGraph(int V, int edges[][2], int edgeCount) {
    // 动态分配二维数组
    int** mat = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        mat[i] = (int*)calloc(V, sizeof(int)); // 初始化为 0
    }

    // 填充边信息
    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i][0]; // 起点
        int v = edges[i][1]; // 终点
        
        // 关键：只记录单向关系 (u -> v)
        mat[u][v] = 1;
    }
    
    return mat;
}

int main() {
    int V = 3;
    // 边列表: 1->0, 2->0, 1->2
    int edges[][2] = {{1, 0}, {2, 0}, {1, 2}};
    int edgeCount = 3;

    int** mat = createDirectedGraph(V, edges, edgeCount);

    printf("Directed Adjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    // 释放内存
    for (int i = 0; i < V; i++) free(mat[i]);
    free(mat);

    return 0;
}