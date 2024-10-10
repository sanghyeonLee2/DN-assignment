#include<stdio.h>
#include<stdlib.h>

typedef struct linkedList {
    // ���Ḯ��Ʈ ��� ����ü
    int data;
    struct linkedList* next;
    struct linkedList* pre;
    // ���� ����� �ּҸ� ������ ������         
    // �����͸� ������ ���    
}NODE;
// �������� ũ��: 32bit = 4����Ʈ, 64bit = 8����Ʈ
// ���: ���� ���� ����Ʈ���� �����Ͱ� ����Ǵ� �������
// malloc = �޸𸮸� �Ҵ�, �� ��ȯ �ʼ�

void inputList(NODE** head, int inputData, int* cnt) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    NODE* tmp = *head;

    newNode->data = inputData;
    newNode->next = NULL;
    newNode->pre = NULL;
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
        newNode->pre = tmp;
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

void searchList(NODE* head, int inputData,int *searchCnt) {
    NODE* tmp = head;   
    if (inputData == head->data) {
        (*searchCnt)++;
    }
    else{
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
        if (*head != NULL) {
            (*head)->pre = NULL;
        }
        (*cnt)--; 
        return;
    }    
    else {
        NODE* preTmp = *head;//������� ���� ��� ������ ����
        NODE* nextTmp =*head;//������� ���� ��� ������ ����
        while (tmp->data != inputData) {
            tmp = tmp->next;
        }
        nextTmp = tmp->next;
        while (preTmp->next != tmp) {
            preTmp = preTmp->next;
        }
        if (nextTmp == NULL) {
            preTmp->next = tmp->next;
        }
        else {
            nextTmp->pre = tmp->pre;
            preTmp->next = tmp->next;
        }        
        (*cnt)--;
    }
}

int main() {
    int input, inputData, cnt = 0, searchCnt = 0;
    NODE* head = NULL;

    while (1) {
        printf("1. 입력 2. 출력 3. 검색 4. 삭제 5. 종료\n원하는 프로그램 번호를 입력하세요 : ");
        scanf_s("%d", &input);
        switch (input) {
        case 1:
            printf("저장할 데이터를 입력하세요 :");
            scanf_s("%d", &inputData);
            inputList(&head, inputData, &cnt);
            break;

        case 2:
            if (cnt == 0) {
                printf("저장된 데이터가 없습니다.\n");
                break;
            }
            else {
                printList(head);
            }
            break;

        case 3:
            if (cnt == 0) {
                printf("찾을 데이터가 없습니다.\n");
                break;
            }
            else {
                printf("찾을 데이터를 입력하세요 :");
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
                printf("삭제할 데이터가 없습니다.\n");
                break;
            }
            else {
                printf("삭제할 데이터를 입력하세요 :");
                scanf_s("%d", &inputData);
                searchList(head, inputData, &searchCnt);
                if (searchCnt == 0) {
                    printf("데이터가 없습니다.\n");
                    break;
                }
                deletetList(&head, inputData, &cnt);
                searchCnt = 0;
                break;
            }

        case 5:
            return 0;

        default:
            printf("잘못된 입력입니다.\n");
            break;
        }
    }
    free(head);  // 메모리 해제
}
