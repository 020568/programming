#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node * next;
} Node, * pNode;

// 逻辑一：初始化（建议用返回指针的方式，最不容易乱）
pNode initList() {
    pNode head = (pNode)malloc(sizeof(Node)); // 申请头节点
    if (head != NULL) 
	{
        head->next = NULL; // 确保新车头后面是空的
    }
    return head;
}

// 逻辑二：头插法（老板，看这个逻辑，绝不会丢掉旧节点）
void insertNode(pNode head, int val) {
    pNode newNode = (pNode)malloc(sizeof(Node));
    newNode->data = val;

    // 先让新节点勾住老节点，再让头节点勾住新节点
    newNode->next = head->next; 
    head->next = newNode;
}


int main() 
{
    pNode L = initList(); // 拿到真正的地址
    insertNode(L, 100);    // 插入数据
    printf("头节点后的第一个数据是: %d\n", L->next->data);
    return 0;
}