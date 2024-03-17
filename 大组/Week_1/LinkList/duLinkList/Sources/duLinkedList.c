/***************************************************************************************
 *	File Name				:	linkedList.c
 *	SYSTEM					:   win11
 *	Create Data				:	2024.3.17
 ***************************************************************************************/

#include "duLinkedList.h"
#include <stdlib.h>

/**************************************************************
 *	Function Implementation Section
 **************************************************************/

// 初始化头结点
Status InitList_DuL(DuLinkedList *L) {
    *L = (DuLinkedList) malloc(sizeof(DuLNode));
    if (*L == NULL)
        exit(OVERFLOW); //内存不足
    (*L)->prior = NULL;
    (*L)->next = NULL; //初始化
    return SUCCESS;
}

// 释放链表
void DestroyList_DuL(DuLinkedList *L) {
    DuLinkedList p;
    while (*L) {
        p = (*L)->next;
        free(*L);
        *L = p;
    }
}

// 在p前插入q
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    if (p == NULL || q == NULL)
        return ERROR;
    q->prior = p->prior;
    q->next = p; //直接先把p自己连上
    p->prior->next = q;
    p->prior = q; //再把别的连到p
    return SUCCESS;
}

// 在p后插入q
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    if (p == NULL || q == NULL)
        return ERROR;
    q->next = p->next;
    q->prior = p;
    if (p->next)
        p->next->prior = q;
    p->next = q;
    return SUCCESS;
}

// 删除p之后的第一个节点，并将其值赋给e
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    if (p == NULL || p->next == NULL)
        return ERROR;
    DuLNode *q = p->next;
    *e = q->data;
    p->next = q->next;
    if (q->next)
        q->next->prior = p;
    free(q);
    return SUCCESS;
}

// 遍历调用visit函数
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    DuLNode *p = L->next;
    while (p) {
        visit(p->data);
        p = p->next;
    }
}
