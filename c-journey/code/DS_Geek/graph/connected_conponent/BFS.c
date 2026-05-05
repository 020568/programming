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

// 模拟队列的点
typedef struct {
    int* items;
    int front, rear, capacity;
} Queue;

Queue* createQueue(int cap) {
    Queue* q = malloc(sizeof(Queue));
    q->items = malloc(cap * sizeof(int));
    q->front = 0; q->rear = 0;
    q->capacity = cap;
    return q;
}

void enqueue(Queue* q, int v) { q->items[q->rear++] = v; }
int dequeue(Queue* q) { return q->items[q->front++]; }
bool isEmpty(Queue* q) { return q->front == q->rear; }

// --- BFS 核心逻辑 ---

void bfs(struct Graph* graph, int src, bool* visited) {
    Queue* q = createQueue(graph->V);
    
    visited[src] = true;
    enqueue(q, src);

    while (!isEmpty(q)) {
        int curr = dequeue(q);
        printf("%d ", curr); // 打印当前圈子里的成员

        struct Node* temp = graph->adjLists[curr];
        while (temp) {
            int adjV = temp->vertex;
            if (!visited[adjV]) {
                visited[adjV] = true; // 进队即标记，防止重复
                enqueue(q, adjV);
            }
            temp = temp->next;
        }
    }
    free(q->items);
    free(q);
}

void findComponents(struct Graph* graph) {
    bool* visited = calloc(graph->V, sizeof(bool));

    printf("Connected Components (BFS):\n");
    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            bfs(graph, i, visited);
            printf("\n"); // 完结一个圈子
        }
    }
    free(visited);
}

// 注：addEdge 等初始化函数与之前邻接表实现一致