#include<stdio.h>
#include<stdlib.h>

typedef struct linkedList {     // ���Ḯ��Ʈ ��� ����ü
    int data;                   // �����͸� ������ ��� 
    struct linkedList* next;    // ���� ����� �ּҸ� ������ ������                
}NODE;

void inputList(NODE** head, int inputData, int* cnt) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    NODE* tmp = *head;

    newNode->data = inputData;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
    (*cnt)++;
}

void printList(NODE* head) {
        NODE* tmp = head;
        if (head->data != NULL) {
            printf("%d ", head->data);
        }
        while (tmp->next != NULL) {
            tmp = tmp->next;
            printf("%d ", tmp->data);
        }
        printf("\n");    
}

void searchList(NODE* head, int inputData, int *searchCnt) {
    NODE* tmp = head;
    if (inputData == head->data) {
        (*searchCnt)++;
    }
    else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
            if (tmp->data == inputData) {
                (*searchCnt)++;
            }
        }
    }

}

void deletetList(NODE** head, int inputData, int* cnt) {
    NODE* tmp = *head;   //������� ��� ������ ����      
    if ((*head)->data == inputData) {
        *head = (*head)->next; //����� �ּҰ��� ���� ���� �ѱ��.
        free(tmp);
        (*cnt)--;
        return;
    }
    else {
        NODE* preTmp = *head;//������� ���� ��� ������ ����
        while (tmp->data != inputData) {
            tmp = tmp->next;
        }
        while (preTmp->next != tmp) {
            preTmp = preTmp->next;
        }
        preTmp->next = tmp->next;
        (*cnt)--;
    }
}

int main() {
    int input, inputData, cnt = 0, searchCnt = 0;
    NODE* head = NULL;

    while (1) {
        printf("1. �Է� 2. ��� 3. �˻� 4. ���� 5. ����\n������ ���α׷� ��ȣ�� �Է��ϼ��� : ");
        scanf_s("%d", &input);
        switch (input) {
        case 1:
            printf("������ ���� �Է��ϼ��� :");
            scanf_s("%d", &inputData);
            inputList(&head, inputData, &cnt);
            break;

        case 2:
            if (cnt == 0) {
                printf("����� �����Ͱ� �����ϴ�.\n");
                break;
            }
            else {
                printList(head);
            }
            break;

        case 3:
            if (cnt == 0) {
                printf("ã�� �����Ͱ� �����ϴ�.\n");
                break;
            }
            else {
                printf("ã�� ������ ���� �Է��ϼ��� :");
                scanf_s("%d", &inputData);
                if (inputData == head->data) {
                    printf("%d : (o)\n", inputData);
                    break;
                }
                searchList(head, inputData, &searchCnt);
                if (searchCnt > 0) {
                    printf("%d : (o)\n", inputData);
                }
                else {
                    printf("%d : (x)\n", inputData);
                }
                searchCnt = 0;
                break;
            }

        case 4:
            if (cnt == 0) {
                printf("������ �����Ͱ� �����ϴ�.\n");
                break;
            }
            else {
                printf("������ ������ ���� �Է��ϼ��� :");
                scanf_s("%d", &inputData);
                searchList(head, inputData, &searchCnt);
                if (searchCnt == 0) {
                    printf("�����Ͱ� �����ϴ�.\n");
                    break;
                }
                deletetList(&head, inputData, &cnt);
                searchCnt = 0;
                break;
            }

        case 5:
            return 0;

        default:
            printf("�߸��� �Է��Դϴ�.\n");
            break;

        }
    }
    free(head);
    //�޸� ��� �� free();�� �ݳ�
}
