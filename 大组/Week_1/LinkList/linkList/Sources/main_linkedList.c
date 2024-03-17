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

    printf("������ADT\n\n"
           "1.����������\n"
           "2.��������\n"
           "3.������\n"
           "4.ɾ�����\n"
           "5.�����������\n"
           "6.��������\n"
           "7.��ת����\n"
           "8.�ж������Ƿ�ɻ�\n"
           "9.��ż��㷴ת\n"
           "10.�����м���\n"
           "11.�˳�\n");
    while (1) {
        if (error) {
            printf("����������������룺");
        } else {
            printf("�������ѡ��");
        }
        scanf("%d", &input);
        switch (input) {
            case 1:
                if (InitList(&list) == SUCCESS)
                    printf("�������ɹ���\n");
                else
                    printf("������ʧ�ܣ�\n");
                break;
            case 2:
                DestroyList(&list);
                printf("���������٣�\n");
                break;
            case 3:
                printf("������Ҫ�����Ԫ��ֵ��");
                scanf("%d", &data);
                printf("������Ҫ���ĸ����ǰ���룺");
                scanf("%d", &input);
                if (InsertList(list, newNode(data)) == SUCCESS)
                    printf("����ɹ���\n");
                else
                    printf("����ʧ�ܣ�\n");
                break;
            case 4:
                printf("������Ҫɾ����Ԫ��ֵ��");
                scanf("%d", &data);
                if (DeleteList(list, &data) == SUCCESS)
                    printf("ɾ���ɹ���\n");
                else
                    printf("ɾ��ʧ�ܣ�\n");
                break;
            case 5:
                printf("����Ԫ��Ϊ��\n");
                TraverseList(list, &printElement);
                printf("\n");
                break;
            case 6:
                printf("������Ҫ���ҵ�Ԫ��ֵ��");
                scanf("%d", &data);
                if (SearchList(list, data) == SUCCESS)
                    printf("Ԫ�� %d �����������У�\n", data);
                else
                    printf("Ԫ�� %d �������������У�\n", data);
                break;
            case 7:
                if (ReverseList(&list) == SUCCESS)
                    printf("�����ѷ�ת��\n");
                else
                    printf("����תʧ�ܣ�\n");
                break;
            case 8:
                if (IsLoopList(list) == SUCCESS)
                    printf("����ɻ���\n");
                else
                    printf("�����ɻ���\n");
                break;
            case 9:
                list = ReverseEvenList(&list);
                printf("��ż����ѷ�ת��\n");
                break;
            case 10:
                printf("�м���Ϊ��\n");
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