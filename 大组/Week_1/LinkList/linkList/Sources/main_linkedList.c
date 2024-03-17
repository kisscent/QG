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
        fflush(stdin); // ������뻺����
        switch (input) {
            case 1:
                status = InitList(&list);
                if (status == SUCCESS)
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
                status = InsertList(list, newNode(data));
                if (status == SUCCESS)
                    printf("����ɹ���\n");
                else
                    printf("����ʧ�ܣ�\n");
                break;
            case 4:
                printf("������Ҫɾ����Ԫ��ֵ��");
                scanf("%d", &data);
                status = DeleteList(list, &data);
                if (status == SUCCESS)
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
                status = SearchList(list, data);
                if (status == SUCCESS)
                    printf("Ԫ�� %d �����������У�\n", data);
                else
                    printf("Ԫ�� %d �������������У�\n", data);
                break;
            case 7:
                status = ReverseList(&list);
                if (status == SUCCESS)
                    printf("�����ѷ�ת��\n");
                else
                    printf("����תʧ�ܣ�\n");
                break;
            case 8:
                status = IsLoopList(list);
                if (status == SUCCESS)
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