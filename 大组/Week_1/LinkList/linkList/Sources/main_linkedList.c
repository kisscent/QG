#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

void printElement(ElemType e) {
    printf("%d ", e);
}

void showMenu() {
    int input;
    int error = 0;
    LinkedList list;
    ElemType data;

    printf("单链表ADT\n\n"
           "1.创建空链表\n"
           "2.销毁链表\n"
           "3.插入结点\n"
           "4.删除结点\n"
           "5.遍历输出链表\n"
           "6.查找链表\n"
           "7.反转链表\n"
           "8.判断链表是否成环\n"
           "9.奇偶结点反转\n"
           "10.查找中间结点\n"
           "11.退出\n");
    while (1) {
        if (error) {
            printf("输入错误，请重新输入：");
        } else {
            printf("输入你的选择：");
        }
        scanf("%d", &input);
        switch (input) {
            case 1:
                if (InitList(&list) == SUCCESS)
                    printf("链表创建成功！\n");
                else
                    printf("链表创建失败！\n");
                break;
            case 2:
                DestroyList(&list);
                printf("链表已销毁！\n");
                break;
            case 3:
                printf("请输入要插入的元素值：");
                scanf("%d", &data);
                printf("请输入要在哪个结点前插入：");
                scanf("%d", &input);
                if (InsertList(list, newNode(data)) == SUCCESS)
                    printf("插入成功！\n");
                else
                    printf("插入失败！\n");
                break;
            case 4:
                printf("请输入要删除的元素值：");
                scanf("%d", &data);
                if (DeleteList(list, &data) == SUCCESS)
                    printf("删除成功！\n");
                else
                    printf("删除失败！\n");
                break;
            case 5:
                printf("链表元素为：\n");
                TraverseList(list, &printElement);
                printf("\n");
                break;
            case 6:
                printf("请输入要查找的元素值：");
                scanf("%d", &data);
                if (SearchList(list, data) == SUCCESS)
                    printf("元素 %d 存在于链表中！\n", data);
                else
                    printf("元素 %d 不存在于链表中！\n", data);
                break;
            case 7:
                if (ReverseList(&list) == SUCCESS)
                    printf("链表已反转！\n");
                else
                    printf("链表反转失败！\n");
                break;
            case 8:
                if (IsLoopList(list) == SUCCESS)
                    printf("链表成环！\n");
                else
                    printf("链表不成环！\n");
                break;
            case 9:
                list = ReverseEvenList(&list);
                printf("奇偶结点已反转！\n");
                break;
            case 10:
                printf("中间结点为：\n");
                LNode *mid = FindMidNode(&list);
                printf("%d\n", mid->data);
                break;
            case 11:
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