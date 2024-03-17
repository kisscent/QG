#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

void showMenu() {
    int input;
    int error = 0;
    while (1) {
        if (error) {
            printf("输入错误，请重新输入：");
        } else {
            printf("单链表ADT\n\n"
                   "1.创建空链表\n"
                   "2.销毁链表\n"
                   "3.插入结点\n"
                   "4.删除结点\n"
                   "5.遍历链表\n"
                   "6.查找链表\n"
                   "7.反转链表\n"
                   "8.判断链表是否成环\n"
                   "9.奇偶结点反转\n"
                   "10.查找中间结点\n"
                   "11.退出\n\n"
                   "输入你的选择：");
        }
        scanf("%d",&input);
        fflush(stdin); //清除输入缓冲区
        switch (input) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
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

    system("pause");
    return 0;
}