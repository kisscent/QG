/***************************************************************************************
 *	File Name				:	linkedList.c
 *	SYSTEM					:   win11
 *	Create Data				:	2024.3.17
 ***************************************************************************************/

#include "linkedlist.h"
#include <stdlib.h>

/**************************************************************
 *	Function Implementation Section
 **************************************************************/

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

// 便历链表调用 visit 函数
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    LNode *p = L->next;
    while (p) {
        visit(p->data); //调用
        p = p->next; //便历
    }
}

// 在链表中找到值为e的结点
Status SearchList(LinkedList L, ElemType e) {
    LNode *p = L->next;
    while (p && p->data != e)
        p = p->next; //便历找结点
    if (p)
        return SUCCESS;
    else
        return ERROR;
}

// 反转链表
Status ReverseList(LinkedList *L) {
    if (*L == NULL || (*L)->next == NULL)
        return ERROR;
    LNode *p = (*L)->next; //第一个结点
    (*L)->next = NULL; //现在第一个结点为空
    LNode *q;
    while (p) {
        q = p->next; //暂存
        p->next = (*L)->next;
        (*L)->next = p; //把p往头结点后插
        p = q;
    }
    return SUCCESS;
}

//是否是循环链表
Status IsLoopList(LinkedList L) {
    LNode *slow = L, *fast = L;
    // 同找中点，一个走两步，一个走一步，看有没有可能相等
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return SUCCESS;
    }
    return ERROR;
}

// 交换奇偶（跳过头结点）
LNode *ReverseEvenList(LinkedList *L) {
    if (*L == NULL || (*L)->next == NULL)
        return *L;
    LNode *last = *L; //暂存上一个
    LNode *odd = (*L)->next; //寄,跳过头结点
    LNode *even = odd->next; //偶
    while (even && even->next) {
        odd->next = even->next; //寄接后面
        even->next = odd; //偶接寄前面
        last->next = even;
        last = odd;
        odd = last->next; //下一个寄
        even = odd->next; //下一个偶
    }
    return *L;
}

// 找中点
LNode *FindMidNode(LinkedList *L) {
    if (*L == NULL || (*L)->next == NULL)
        return *L;
    //一个走一步，一个走两步，快的走完，慢的就是中点
    LNode *slow = *L, *fast = *L;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
