#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

void showMenu() {
    int input;
    int error = 0;
    while (1) {
        if (error) {
            printf("����������������룺");
        } else {
            printf("������ADT\n\n"
                   "1.����������\n"
                   "2.��������\n"
                   "3.������\n"
                   "4.ɾ�����\n"
                   "5.��������\n"
                   "6.��������\n"
                   "7.��ת����\n"
                   "8.�ж������Ƿ�ɻ�\n"
                   "9.��ż��㷴ת\n"
                   "10.�����м���\n"
                   "11.�˳�\n\n"
                   "�������ѡ��");
        }
        scanf("%d",&input);
        fflush(stdin); //������뻺����
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