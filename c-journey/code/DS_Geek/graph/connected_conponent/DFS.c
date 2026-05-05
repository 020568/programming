#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 邻接表节点
struct Node {
    int vertex;
    struct Node* next;
};

// 图结构
struct Graph {
    int V;
    struct Node** adjLists;
};

// 创建节点
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// DFS 遍历并打印当前分量
void dfs(struct Graph* graph, bool* visited, int s) {
    visited[s] = true;
    printf("%d ", s); // 发现一个，打印一个

    struct Node* temp = graph->adjLists[s];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            dfs(graph, visited, adjVertex);
        }
        temp = temp->next;
    }
}

void findComponents(struct Graph* graph) {
    bool* visited = calloc(graph->V, sizeof(bool));

    printf("Connected Components:\n");
    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            // 每次进入这个 if，就代表发现了一个新的连通分量
            dfs(graph, visited, i);
            printf("\n"); // 一个分量结束，换行
        }
    }
    free(visited);
}

// 后面是创建图和 addEdge 的逻辑... (省略以保持简洁)