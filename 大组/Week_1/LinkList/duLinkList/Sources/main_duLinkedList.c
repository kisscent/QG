#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void printElement(ElemType e) {
    printf("%d ", e);
}

void showMenu() {
    int input;
    int error = 0;
    DuLinkedList L;
    ElemType e;

    printf("双向链表ADT\n\n"
           "1.创建空链表\n"
           "2.销毁链表\n"
           "3.结点前插\n"
           "4.结点后插\n"
           "5.删除结点\n"
           "6.遍历链表\n"
           "7.退出\n\n"
           "输入你的选择：");
    while (1) {
        if (error) {
            printf("输入错误，请重新输入：");
        } else {
            printf("输入你的选择：");
        }
        scanf("%d", &input);
        switch (input) {
            case 1:
                if (InitList_DuL(&L) == SUCCESS)
                    printf("链表创建成功！\n");
                else
                    printf("链表创建失败！\n");
                break;
            case 2:
                DestroyList_DuL(&L);
                printf("链表已销毁！\n");
                break;
            case 3:
                printf("请输入待插入结点的值：");
                scanf("%d", &e);
                printf("请输入要在哪个结点前插入：");
                scanf("%d", &input);
                if (InsertBeforeList_DuL(searchNode(&L, input), newNode(e)) == SUCCESS)
                    printf("结点插入成功！\n");
                else
                    printf("结点插入失败！\n");
                break;
            case 4:
                printf("请输入待插入结点的值：");
                scanf("%d", &e);
                printf("请输入要在哪个结点后插入：");
                scanf("%d", &input);
                if (InsertAfterList_DuL(searchNode(&L, input), newNode(e)) == SUCCESS)
                    printf("结点插入成功！\n");
                else
                    printf("结点插入失败！\n");
                break;
            case 5:
                printf("请输入要删除的结点值：");
                scanf("%d", &input);
                if (DeleteList_DuL(L, &e) == SUCCESS)
                    printf("结点删除成功！\n");
                else
                    printf("结点删除失败！\n");
                break;
            case 6:
                printf("遍历链表：\n");
                TraverseList_DuL(L, &printElement); // Assuming printNode is a function to print a node
                break;
            case 7:
                return;
            default:
                error = 1;
                continue;
        }
        error = 0;
    }
}

int main() {
    system("chcp 936 > NUL");
    showMenu();
    return 0;
}