//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct linkedList {
//     ���Ḯ��Ʈ ��� ����ü
//    int data;
//    struct linkedList* next;
//     ���� ����� �ּҸ� ������ ������         
//     �����͸� ������ ���    
//}NODE;
// �������� ũ��: 32bit = 4����Ʈ, 64bit = 8����Ʈ
// ���: ���� ���� ����Ʈ���� �����Ͱ� ����Ǵ� �������
// ���� �޸�: ���� ��� �� �ݳ�, ex) ���� 
// �Ӹ����: ������ ���� X
// malloc = �޸𸮸� �Ҵ�, �� ��ȯ �ʼ�
//
//void inputList(NODE** head, int inputData, int* cnt) {
//    NODE* newNode = (NODE*)malloc(sizeof(NODE));
//    newNode->data = inputData;
//
//    if (*head == NULL) {
//        *head = newNode;
//        newNode->next = *head;
//    }
//    else {
//        NODE* tmp = *head;
//        while (tmp->next != *head) {
//            tmp = tmp->next;
//        }
//        tmp->next = newNode;
//        newNode->next = *head;
//    }
//    (*cnt)++;
//}
//
//void printList(NODE* head) {
//    NODE* tmp = head;
//    if (head->data != NULL) {
//        printf("%d ", head->data);
//    }
//    while (tmp->next != head) {
//        tmp = tmp->next;
//        printf("%d ", tmp->data);
//    }
//    printf("\n");
//}
//
//void searchList(NODE* head, int inputData) {
//    NODE* tmp = head;
//    int searchCnt = 0;
//    if (inputData == head->data) {
//        printf("%d : (o)\n", inputData);
//        return;
//    }
//    while (tmp->next != head) {
//        tmp = tmp->next;
//        if (tmp->data == inputData) {
//            searchCnt++;
//        }
//    }
//    if (searchCnt > 0) {
//        printf("%d : (o)\n", inputData);
//    }
//    else {
//        printf("%d : (x)\n", inputData);
//    }
//}
//
//void deletetList(NODE** head, int inputData, int* cnt) {
//    NODE* tmp = *head;   //������� ��� ������ ����      
//    NODE* lastTmp = *head;   //������ ��� ������ ����      
//    if ((*head)->data == inputData) {
//        while (lastTmp->next != *head) {
//            lastTmp = lastTmp->next;
//        }
//        *head = (*head)->next;//����� �ּҰ��� ���� ���� �ѱ��.            
//        free(tmp);
//        lastTmp->next = *head;
//        (*cnt)--;
//        return;
//    }
//    else {
//        NODE* preTmp = *head;//������� ���� ��� ������ ����
//        while (tmp->data != inputData) {
//            tmp = tmp->next;
//        }
//        while (preTmp->next != tmp) {
//            preTmp = preTmp->next;
//        }
//        preTmp->next = tmp->next;
//        (*cnt)--;
//    }
//}
//
//int main() {
//    int input, inputData, cnt = 0;
//    NODE* head = (NODE*)malloc(sizeof(NODE));
//    head = NULL;
//
//    while (1) {
//        printf("1. �Է� 2. ��� 3. �˻� 4. ���� 5. ����\n������ ���α׷� ��ȣ�� �Է��ϼ��� : ");
//        scanf_s("%d", &input);
//        switch (input) {
//        case 1:
//            printf("������ ���� �Է��ϼ��� :");
//            scanf_s("%d", &inputData);
//            inputList(&head, inputData, &cnt);
//            break;
//
//        case 2:
//            if (cnt == 0) {
//                printf("����� �����Ͱ� �����ϴ�.\n");
//                break;
//            }
//            else {
//                printList(head);
//            }
//            break;
//
//        case 3:
//            if (cnt == 0) {
//                printf("ã�� �����Ͱ� �����ϴ�.\n");
//                break;
//            }
//            else {
//                printf("ã�� ������ ���� �Է��ϼ��� :");
//                scanf_s("%d", &inputData);
//                searchList(head, inputData);
//                break;
//            }
//
//        case 4:
//            if (cnt == 0) {
//                printf("������ �����Ͱ� �����ϴ�.\n");
//                break;
//            }
//            else {
//                printf("������ ������ ���� �Է��ϼ��� :");
//                scanf_s("%d", &inputData);
//                deletetList(&head, inputData, &cnt);
//                break;
//            }
//
//        case 5:
//            return 0;
//
//        default:
//            printf("�߸��� �Է��Դϴ�.\n");
//            break;
//        }
//    }
//    free(head);
//    �޸� ��� �� free();�� �ݳ�
//}