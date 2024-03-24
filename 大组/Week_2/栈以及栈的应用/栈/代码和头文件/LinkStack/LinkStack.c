#include "../head/LinkStack.h" 
#include <stdio.h>
#include <stdlib.h>
//Á´Õ»

//³õÊ¼»¯Õ»
Status initLStack(LinkStack *s) {
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}

//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
Status isEmptyLStack(LinkStack *s) {
    return s->count == 0 ? SUCCESS : ERROR;
}

//µÃµ½Õ»¶¥ÔªËØ
Status getTopLStack(LinkStack *s, ElemType *e) {
    if (isEmptyLStack(s) == SUCCESS) {
        return ERROR;
    }
    *e = s->top->data;
    return SUCCESS;
}

//Çå¿ÕÕ»
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

//Ïú»ÙÕ»
Status destroyLStack(LinkStack *s) {
    clearLStack(s);
    free(s);
    return SUCCESS;
}

//¼ì²âÕ»³¤¶È
Status LStackLength(LinkStack *s, int *length) {
    *length = s->count;
    return SUCCESS;
}

//ÈëÕ»
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

//³öÕ»
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
