#include "linkedlist.h"
#include <stdlib.h>

// 初始化头结点
Status InitList(LinkedList *L) {
    *L = (LinkedList) malloc(sizeof(LNode)); //内存
    if (*L == NULL)
        exit(OVERFLOW); //没内存
    (*L)->next = NULL; //初始化next
    return SUCCESS;
}

// 释放链表
void DestroyList(LinkedList *L) {
    LinkedList p;
    while (*L) {
        p = (*L)->next; // 暂存
        free(*L); //释放结点
        *L = p; //便历
    }
}

// 在p后插入q
Status InsertList(LNode *p, LNode *q) {
    if (p == NULL || q == NULL)
        return ERROR;
    q->next = p->next; //先接后面
    p->next = q; //再接前面
    return SUCCESS;
}

// 删除p之后的第一个节点，并将其值赋给e
Status DeleteList(LNode *p, ElemType *e) {
    if (p == NULL || p->next == NULL)
        return ERROR;
    LNode *q = p->next; //暂存
    *e = q->data; //赋值
    p->next = q->next; //链表跳过q结点
    free(q); //释放
    return SUCCESS;
}

