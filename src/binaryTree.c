#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode { // ����Ʈ�� ��� ����ü
    int data;
    struct treeNode* left;
    struct treeNode* right;
}NODE;

int noPrint = 1; //��¹��� �����ϱ� ���� ����

NODE* new_node(int inputData, NODE** root) { //��� ���� �Լ�
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = inputData;
    return newNode;
}

NODE* inputTree(NODE** root, int inputData) { //��� ���� �Լ�, ���� �������� �޸� �ּҴ� ���� �����Ϳ� ����       
    NODE* tmp = *root;
    if (*root == NULL) {
        return *root = new_node(inputData, &(*root));
    }
    if (tmp->data == inputData) {
        return tmp;
    }
    if (tmp->data < inputData) {
        return inputTree(&tmp->right, inputData);
    }
    else {
        return inputTree(&tmp->left, inputData);
    }
    if (tmp->data < inputData) {
        tmp->right = new_node(inputData, &tmp);
    }
    else {
        tmp->left = new_node(inputData, &tmp);
    }
}

void preorder(NODE** root) { //���� ��� �Լ�
    if (*root) {
        NODE* tmp = (*root);
        printf("%d  ", tmp->data);
        preorder(&tmp->left);
        preorder(&tmp->right);
    }
}

void inorder(NODE** root, NODE** largestTmp) { //���� ��� �Լ�
    if (*root) {                                           
        NODE* tmp = (*root);                                 
        inorder(&tmp->left, largestTmp);
        if (noPrint == 1) {                    //noPrint ���� 1(��)�̸� ��� �Ѵ�.�ƴϸ� �н�
            printf("%d  ", tmp->data);
        }
        *largestTmp = tmp;                     //���� ��ȸ�� ��� �ٷ� ������ ������ ������ ���� ����
        inorder(&tmp->right, largestTmp);
    }
}

void postorder(NODE** root) { //���� ��� �Լ�
    if (*root) {
        NODE* tmp = (*root);
        postorder(&tmp->left);
        postorder(&tmp->right);
        printf("%d  ", tmp->data);
    }
}

NODE* searchTree(NODE** root, int inputData, NODE** preTmp) { //�˻� �Լ�
    NODE* tmp = *root;
    if (tmp == NULL) {
        return NULL;
    }
    if (tmp->data == inputData) {
        return tmp;
    }
    if (tmp->data < inputData) {
        *preTmp = tmp;
        return searchTree(&tmp->right, inputData, preTmp);
    }
    else {
        *preTmp = tmp;
        return searchTree(&tmp->left, inputData, preTmp);
    }
}

void deleteTree(NODE** root, int inputData, NODE** preTmp, NODE** largestTmp) { //���� �Լ�
    NODE* tmp = searchTree(root, inputData, preTmp); //���� ��� ��带 �˻� �Լ� ������ ���� 
    if (tmp->right == NULL && tmp->left == NULL) {  //������� ����� �ڽĳ�尡 ������
        if ((*root)->left == NULL && (*root)->right == NULL) {
            (*root) = NULL;
            return;
        }
        if (tmp->data > (*preTmp)->data) {
            (*preTmp)->right = NULL;
        }
        else {
            (*preTmp)->left = NULL;
        }
    }

    if (inputData == (*root)->data) { //������� ����� �ڽĳ�尡 �Ѱ��� �� 
        if (tmp->right != NULL && tmp->left == NULL) {
            *root = tmp->right;
        }
        if (tmp->right == NULL && tmp->left != NULL) {
            *root = tmp->left;
        }
    }
    else {
        if (tmp->right != NULL && tmp->left == NULL) {
            if ((*preTmp)->data > tmp->data) {
                (*preTmp)->left = tmp->right;
            }
            else {
                (*preTmp)->right = tmp->right;
            }
        }
        if (tmp->right == NULL && tmp->left != NULL) {
            if ((*preTmp)->data < tmp->data) {
                (*preTmp)->right = tmp->left;
            }
            else {
                (*preTmp)->left = tmp->left;
            }
        }
    }

    if (tmp->right != NULL && tmp->left != NULL) { //���� ��� ����� �ڽĳ�尡 2�� �϶�
        noPrint = 0;
        inorder(&tmp->left, largestTmp); //���� ��� ����� ���� ����Ʈ�� �� ���� ū ��� ã��
        searchTree(root, (*largestTmp)->data, preTmp); //������ ã�� ����� ���� ��� ã��
        tmp->data = (*largestTmp)->data;
        if ((*preTmp)->right == (*largestTmp)) {
            (*preTmp)->right = (*largestTmp)->right;
        }
        else {
            (*preTmp)->left = (*largestTmp)->left;
        }
        noPrint = 1;
    }
}


int main() {
    int input, inputData; //프로그램 번호와 입력받을 데이터를 저장하는 변수   
    NODE* root = NULL; // 초기 트리 루트는 NULL로 초기화
    NODE* preTmp; //이전 노드를 저장하는 변수
    NODE* largestTmp; //중위 순회를 통해 가장 큰 데이터를 저장하는 변수

    while (1) {
        printf("---------------------------------------\n1. 입력 2. 출력 3. 검색 4. 삭제 5. 종료\n---------------------------------------\n원하는 프로그램 번호를 입력하세요 : ");
        scanf_s("%d", &input);
        switch (input) {
        case 1:
            printf("---------------------------------------\n저장할 데이터를 입력하세요: ");
            scanf_s("%d", &inputData);
            inputTree(&root, inputData); //&root 주소를 매개변수로 전달   
            printf("---------------------------------------\n입력 완료!\n");
            break;
        case 2:
            if (root == NULL) {
                printf("---------------------------------------\n트리가 비어있습니다.\n");
                break;
            }
            else {
                printf("---------------------------------------\n전위 순회: ");
                preorder(&root);
                printf("\n\n중위 순회: ");
                inorder(&root, &largestTmp);                
                printf("\n\n후위 순회: ");
                postorder(&root);
                printf("\n");
                break;
            }
        case 3:
            if (root == NULL) {
                printf("---------------------------------------\n트리가 비어있습니다.\n");
                break;
            }
            else {
                printf("---------------------------------------\n찾을 데이터를 입력하세요: ");
                scanf_s("%d", &inputData);
                if (searchTree(&root, inputData, &preTmp) == NULL) {
                    printf("\n%d: (x)\n", inputData);
                }
                else {
                    printf("\n%d: (o)\n", inputData);
                }
            }
            break;
        case 4:
            if (root == NULL) {
                printf("---------------------------------------\n트리가 비어있습니다.\n");
                break;
            }
            else {
                printf("---------------------------------------\n삭제할 데이터를 입력하세요: ");
                scanf_s("%d", &inputData);
                deleteTree(&root, inputData, &preTmp, &largestTmp);
                printf("---------------------------------------\n삭제 완료!\n");
            }
            break;
        case 5:
            printf("---------------------------------------\n종료");
            return 0;
        default:
            printf("---------------------------------------\n잘못된 입력입니다.\n");
            break;
        }
    }
    free(root); //메모리 해제
}
