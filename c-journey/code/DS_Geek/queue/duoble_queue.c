#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct double_list_node {
    int val;
    struct double_list_node *next;
    struct double_list_node *prev;
} double_list_node;

// 修正：创建节点
double_list_node *new_double_list_node(int num) {
    double_list_node *node = malloc(sizeof(double_list_node));
    node->val = num;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

typedef struct {
    double_list_node *front, *rear;
    int quesize;
} linked_list_dqueue;

linked_list_dqueue *new_linked_list_dqueue() {
    linked_list_dqueue *dqueue = malloc(sizeof(linked_list_dqueue));
    dqueue->front = NULL;
    dqueue->rear = NULL;
    dqueue->quesize = 0;
    return dqueue;
}

// 修正：入队逻辑
void push(linked_list_dqueue *dqueue, int num, bool is_front) {
    double_list_node *node = new_double_list_node(num);
    if (dqueue->quesize == 0) {
        dqueue->front = dqueue->rear = node;
    } else if (is_front) {
        node->next = dqueue->front;
        dqueue->front->prev = node;
        dqueue->front = node;
    } else {
        dqueue->rear->next = node;
        node->prev = dqueue->rear;
        dqueue->rear = node;
    }
    dqueue->quesize++;
}

// 修正：出队逻辑（这是最诡异的地方，现在理顺了）
int pop(linked_list_dqueue *dqueue, bool is_front) {
    if (dqueue->quesize == 0) return -1;
    
    double_list_node *tmp;
    int val;

    if (is_front) {
        tmp = dqueue->front;
        val = tmp->val;
        dqueue->front = tmp->next;
        if (dqueue->front) dqueue->front->prev = NULL;
        else dqueue->rear = NULL; // 删完后队列空了
    } else {
        tmp = dqueue->rear;
        val = tmp->val;
        dqueue->rear = tmp->prev;
        if (dqueue->rear) dqueue->rear->next = NULL;
        else dqueue->front = NULL; // 删完后队列空了
    }

    free(tmp);
    dqueue->quesize--;
    return val;
}

void print_queue(linked_list_dqueue *dqueue) {
    printf("Queue: ");
    double_list_node *node = dqueue->front;
    while (node != NULL) {
        printf("%d <-> ", node->val);
        node = node->next;
    }
    printf("NULL\n");
}