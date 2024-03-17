#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void showMenu() {
    int input;
    int error = 0;
    while (1) {
        if (error) {
            printf("输入错误，请重新输入：");
        } else {
            printf("双向链表ADT\n\n"
                   "1.创建空链表\n"
                   "2.销毁链表\n"
                   "3.结点前插\n"
                   "4.结点后插\n"
                   "5.删除结点\n"
                   "6.遍历链表\n"
                   "7.退出\n\n"
                   "输入你的选择：");
        }
        scanf("%d", &input);
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