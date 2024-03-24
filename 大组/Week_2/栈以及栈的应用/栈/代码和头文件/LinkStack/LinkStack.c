#include "../head/LinkStack.h" 
#include <stdio.h>
#include <stdlib.h>
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s) {
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s) {
    return s->count == 0 ? SUCCESS : ERROR;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s, ElemType *e) {
    if (isEmptyLStack(s) == SUCCESS) {
        return ERROR;
    }
    *e = s->top->data;
    return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack *s) {
    LinkStackPtr p, q;
    p = s->top;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack *s) {
    clearLStack(s);
    free(s);
    return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack *s, int *length) {
    *length = s->count;
    return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack *s, ElemType data) {
    LinkStackPtr newNode = (LinkStackPtr)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        return ERROR;
    }
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
    s->count++;
    return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s, ElemType *data) {
    if (isEmptyLStack(s) == SUCCESS) {
        return ERROR;
    }
    *data = s->top->data;
    LinkStackPtr temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->count--;
    return SUCCESS;
}
