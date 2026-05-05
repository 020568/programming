#include <stdio.h>
#include <stdlib.h>

// --- 并查集基础逻辑 ---

typedef struct {
    int *parent;
    int n;
} DSU;

DSU* createDSU(int n) {
    DSU* dsu = malloc(sizeof(DSU));
    dsu->parent = malloc(n * sizeof(int));
    dsu->n = n;
    for (int i = 0; i < n; i++) dsu->parent[i] = i;
    return dsu;
}

int findParent(DSU* dsu, int u) {
    if (u == dsu->parent[u]) return u;
    return dsu->parent[u] = findParent(dsu, dsu->parent[u]); // 路径压缩
}

void unite(DSU* dsu, int u, int v) {
    int pu = findParent(dsu, u);
    int pv = findParent(dsu, v);
    if (pu != pv) dsu->parent[pu] = pv;
}


void printComponents(DSU* dsu, int V) {
    // 为了模拟 map，我们准备一个数组记录哪些点已经被打印过
    int *visited = calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        // 如果这个点所属的帮派还没被展示过
        int root = findParent(dsu, i);
        
        // 查找所有和 i 属于同一个帮派的点
        bool foundNew = false;
        for (int j = 0; j < V; j++) {
            if (!visited[j] && findParent(dsu, j) == root) {
                printf("%d ", j);
                visited[j] = 1;
                foundNew = true;
            }
        }
        if (foundNew) printf("\n");
    }
    free(visited);
}

int main() {
    int V = 6;
    DSU* dsu = createDSU(V);

    // 对应 addEdge(1, 2), (0, 3), (2, 0), (5, 4)
    unite(dsu, 1, 2);
    unite(dsu, 0, 3);
    unite(dsu, 2, 0);
    unite(dsu, 5, 4);

    printf("Connected Components (DSU):\n");
    printComponents(dsu, V);

    // 释放内存
    free(dsu->parent);
    free(dsu);
    return 0;
}