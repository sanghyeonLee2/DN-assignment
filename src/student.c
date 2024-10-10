#define _crt_secure_no_warnings
#include<stdio.h>
#pragma warning(disable:4996)
#include<string.h>
#include<stdlib.h>
void fuction_input(struct student[], int* cnt);
void fuction_output(struct student[], int* cnt);
void fuction_search(struct student[], int* cnt);
void fuction_del(struct student[], int* cnt);
void fuction_save(struct student[], int* cnt);
void fuction_load(struct student[], int* cnt);
struct student {
	int num, korean, math, english, sum, avr; //�й�, ��������, ��������, ��������, �հ�, ���
	char name[10]; // �̸� : �迭 ���� �ʼ�
};

int main() {
	int input, cnt = 0; // cnt = ���� �л��� ��
	struct student p[6];
	while (1) {
		printf("------------------------------------------------\n1.입력 2.출력 3.검색 4.삭제 5.저장 6.로드 7.종료\n------------------------------------------------\n");
		printf("입력할 번호를 입력하세요 : ");
		scanf_s("%d", &input);
		printf("------------------------------------------------\n");
		switch (input) {
		case 1://�Է�
			fuction_input(p, &cnt);
			break;

		case 2://���
			fuction_output(p, &cnt);
			if (cnt == 0) {
				printf("출력할 학생 정보가 없습니다.\n");
			}
			break;

		case 3://�˻�
			if (cnt >= 1) {
				fuction_search(p, &cnt);
				break;
			}
			else {
				printf("검색한 정보를 찾을 수 없습니다.\n");
				break;
			}

		case 4://����            
			if (cnt >= 1) {
				fuction_del(p, &cnt);
				break;
			}
			else {
				printf("검색한 정보를 찾을 수 없습니다.\n");
				break;
			}

		case 5://����
			fuction_save(p, &cnt);
			break;

		case 6://�ε�
			fuction_load(p, &cnt);
			break;

		case 7://����
			printf("종료.\n");
			return 0;

		default:
			printf("1 ~7 의 숫자만 입력하시오.\n");
			break;

		}
	}
}
void fuction_input(struct student p[6], int* cnt) {
	int temp;
	char nametemp[10];
	printf("학번을 입력하세요 : ");
	scanf("%d", &p[*cnt].num);
	printf("------------------------------------------------\n");
	for (int i = 0; i < *cnt; i++) {
		if (p[i].num == p[*cnt].num) {
			printf("입력이 완료 되었습니다. \n------------------------------------------------\n");
			return;
		}
	}
	printf("이름을 입력하세요 : ");
	scanf("%s", p[*cnt].name);
	printf("------------------------------------------------\n");
	printf("국어 점수를 입력하세요 : ");
	scanf("%d", &p[*cnt].korean);
	printf("------------------------------------------------\n");
	printf("수학 점수를 입력하세요 : ");
	scanf("%d", &p[*cnt].math);
	printf("------------------------------------------------\n");
	printf("영어 점수를 입력하세요 : ");
	scanf("%d", &p[*cnt].english);
	p[*cnt].sum = p[*cnt].korean + p[*cnt].math + p[*cnt].english;
	p[*cnt].avr = (p[*cnt].korean + p[*cnt].math + p[*cnt].english) / 3;
	(*cnt)++;
	for (int i = 0; i < *cnt - 1; i++)
	{
		for (int j = 0; j < *cnt - 1 - i; j++)
		{
			if (p[j].avr < p[j + 1].avr) {
				temp = p[j].num;
				p[j].num = p[j + 1].num;
				p[j + 1].num = temp;
				temp = p[j].korean;
				p[j].korean = p[j + 1].korean;
				p[j + 1].korean = temp;
				temp = p[j].math;
				p[j].math = p[j + 1].math;
				p[j + 1].math = temp;
				temp = p[j].english;
				p[j].english = p[j + 1].english;
				p[j + 1].english = temp;
				temp = p[j].sum;
				p[j].sum = p[j + 1].sum;
				p[j + 1].sum = temp;
				temp = p[j].avr;
				p[j].avr = p[j + 1].avr;
				p[j + 1].avr = temp;
				for (int k = 0; k <= 10; k++) {
					nametemp[k] = p[j].name[k];
					p[j].name[k] = p[j + 1].name[k];
					p[j + 1].name[k] = nametemp[k];
				}
			}
		}

	}   //���� �� ���
}



void fuction_output(struct student p[6], int* cnt) {
	for (int i = 0; i < *cnt; i++) {
		printf("학번 : %d 이름 : %s 국어 : %d 수학 : %d 영어 : %d 총합 : %d 평균 : %d\n", p[i].num, p[i].name, p[i].korean, p[i].math, p[i].english, p[i].sum, p[i].avr);
	}
}
void fuction_search(struct student p[6], int* cnt) {
	int search;
	int searchcnt = 0;//ã�� �л� ��
	printf("검색할 학생의 학번을 입력하세요 : ");
	scanf("%d", &search);
	printf("------------------------------------------------\n");
	for (int i = 0; i < *cnt; i++) {
		if (p[i].num == search) {
			printf("학번 : %d 이름 : %s 국어 : %d 수학 : %d 영어 : %d 총합 : %d 평균 : %d\n", p[i].num, p[i].name, p[i].korean, p[i].math, p[i].english, p[i].sum, p[i].avr);
			searchcnt++;
		}
	}
	if (searchcnt == 0) {
		printf("검색한 정보를 찾을 수 없습니다.\n");
	}
}
void fuction_del(struct student p[6], int* cnt) {
	int del;
	int delcnt = 0;//������ �л� ��
	printf("삭제할 학생의 학번을 입력하세요 : ");
	scanf("%d", &del);
	printf("------------------------------------------------\n");
	for (int i = 0; i < *cnt; i++) {
		if (p[i].num == del) {
			delcnt++;
			for (int j = i; j < *cnt; j++) {
				p[j].num = p[j + 1].num;
				for (int k = 0; k <= 10; k++) {
					p[j].name[k] = p[j + 1].name[k];
				}
				p[j].korean = p[j + 1].korean;
				p[j].math = p[j + 1].math;
				p[j].english = p[j + 1].english;
				p[j].sum = p[j + 1].sum;
				p[j].avr = p[j + 1].avr;
			}
		}
	}
	if (delcnt == 0) {
		printf("찾을 수 없습니다.\n");
		return;//������ �л��� ������ ��� �� ��ȯ
	}
	else {
		printf("삭제 되었습니다.\n------------------------------------------------\n");
		(*cnt)--;
	}
}
void fuction_save(struct student p[6], int* cnt) {
	FILE* fp = fopen("student.txt", "w");
	for (int i = 0; i < *cnt; i++) {
		fprintf(fp, "%d %s %d %d %d %d %d\n", p[i].num, p[i].name, p[i].korean, p[i].math, p[i].english, p[i].sum, p[i].avr);
	}
	fclose(fp);
	printf("저장되었습니다\n");
}

void fuction_load(struct student p[6], int* cnt) {
	FILE* fp = fopen("student.txt", "r"); //���� �б� ���� ���� 
	int line = 0; //���� ��
	char textCopy; //���� ���� ����
	while (fscanf(fp, "%c", &textCopy) != EOF) { //������ �� ���ڸ� �ϳ��� ����, ������ ���ڰ� eof�� ���� ��� �ݺ��� Ż��
		if (textCopy == '\n') {
			line++; //����� ��ŭ line ���� ����
		}
	}
	fseek(fp, 0l, SEEK_SET);//���� �����͸� ó�� ��ġ���� 0����Ʈ ������ ��ġ�� �̵�
	*cnt = line; //���� �� = �л� ��
	for (int i = 0; i < *cnt; i++) {
		fscanf(fp, "%d %s %d %d %d %d %d \n", &p[i].num, p[i].name, &p[i].korean, &p[i].math, &p[i].english, &p[i].sum, &p[i].avr);
	}
	fclose(fp);
	printf("�ε� �Ǿ����ϴ�.\n");
}
