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

    printf("˫������ADT\n\n"
           "1.����������\n"
           "2.��������\n"
           "3.���ǰ��\n"
           "4.�����\n"
           "5.ɾ�����\n"
           "6.��������\n"
           "7.�˳�\n\n"
           "�������ѡ��");
    while (1) {
        if (error) {
            printf("����������������룺");
        } else {
            printf("�������ѡ��");
        }
        scanf("%d", &input);
        switch (input) {
            case 1:
                if (InitList_DuL(&L) == SUCCESS)
                    printf("�������ɹ���\n");
                else
                    printf("������ʧ�ܣ�\n");
                break;
            case 2:
                DestroyList_DuL(&L);
                printf("���������٣�\n");
                break;
            case 3:
                printf("��������������ֵ��");
                scanf("%d", &e);
                printf("������Ҫ���ĸ����ǰ���룺");
                scanf("%d", &input);
                if (InsertBeforeList_DuL(searchNode(&L, input), newNode(e)) == SUCCESS)
                    printf("������ɹ���\n");
                else
                    printf("������ʧ�ܣ�\n");
                break;
            case 4:
                printf("��������������ֵ��");
                scanf("%d", &e);
                printf("������Ҫ���ĸ�������룺");
                scanf("%d", &input);
                if (InsertAfterList_DuL(searchNode(&L, input), newNode(e)) == SUCCESS)
                    printf("������ɹ���\n");
                else
                    printf("������ʧ�ܣ�\n");
                break;
            case 5:
                printf("������Ҫɾ���Ľ��ֵ��");
                scanf("%d", &input);
                if (DeleteList_DuL(L, &e) == SUCCESS)
                    printf("���ɾ���ɹ���\n");
                else
                    printf("���ɾ��ʧ�ܣ�\n");
                break;
            case 6:
                printf("��������\n");
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