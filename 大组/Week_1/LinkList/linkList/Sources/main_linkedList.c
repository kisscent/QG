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
    Status status;
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
        fflush(stdin); // 清除输入缓冲区
        switch (input) {
            case 1:
                status = InitList(&list);
                if (status == SUCCESS)
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
                status = InsertList(list, newNode(data));
                if (status == SUCCESS)
                    printf("插入成功！\n");
                else
                    printf("插入失败！\n");
                break;
            case 4:
                printf("请输入要删除的元素值：");
                scanf("%d", &data);
                status = DeleteList(list, &data);
                if (status == SUCCESS)
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
                status = SearchList(list, data);
                if (status == SUCCESS)
                    printf("元素 %d 存在于链表中！\n", data);
                else
                    printf("元素 %d 不存在于链表中！\n", data);
                break;
            case 7:
                status = ReverseList(&list);
                if (status == SUCCESS)
                    printf("链表已反转！\n");
                else
                    printf("链表反转失败！\n");
                break;
            case 8:
                status = IsLoopList(list);
                if (status == SUCCESS)
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
        }
        if (input >= 1 && input <= 11) error = 0;
        else error = 1;
    }
}

int main() {
    system("chcp 936 > NUL");
    showMenu();
    return 0;
}