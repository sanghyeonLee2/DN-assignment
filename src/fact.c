#include<stdio.h>
#define size 100

int main() {

    int input;

    scanf_s("%d", &input);

    int fact[size];

    fact[size - 1] = 1;


    for (int j = 0; j < size - 1; j++) {
        fact[j] = 0;
    }

    for (int k = 1; k <= input; k++) {

        for (int j = 1; j <= size - 1; j++) {
            fact[size - j] *= k;
        }

        for (int i = size - 1; i >= 0; i--) {
            if (fact[i] >= 10) {
                fact[i - 1] += fact[i] / 10;
                fact[i] = fact[i] % 10;
            }
        }
    }
    int i = 0;
    while (fact[i] == 0) {
        i++;
    }
    for (i-1; i < size; i++) {
        printf("%d", fact[i]);
    }
    
  /*  for (int j = 0; j <= size - 1; j++) {
        if (fact[j] != 0) {
            for (int i = j; i <= size - 1; i++) {
                printf("%d", fact[i]);
            }
            break;
        }
    }*/


    return 0;
}
/*
int fact1(int arr[], int n)
{
    if (n <= 1)
        return 1;
    else
    {
        for (int i = 1; i <= 50;i++) {
            arr[size-1] *= i;

        }
        for (int i = 99; i >= 0; i--) {//�ڸ��� 10 �ִ� �κ� ����
            if (arr[i] >= 10) {
                arr[i - 1] += arr[i] / 10;
                arr[i] = arr[i] % 10;
            }
        }
        return (n * fact1(arr,n - 1));
    }
}*/
