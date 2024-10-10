#include <stdio.h>
int main()
{
    while (1)
    {
        int star, cnt = 0;
        printf("갯수 입력 :");
        scanf_s("%d", &star);
        if (star % 2 == 0) { //�Է��� ���� ¦�� �϶�
            cnt = star / 2 - 1;
            for (int i = 2; i <= star; i += 2) {
                for (int k = cnt; 1 <= k; k--) {
                    printf(" ");
                }
                for (int j = 1; j <= i; j++) {
                    printf("*");
                }
                {
                    cnt--;
                    printf("\n");
                }
            }
            for (int n = 4; n <= star; n += 2) {
                for (int l = cnt; 0 <= l + 1; l--) {
                    printf(" ");
                }
                for (int m = star; n <= m + 1; m--) {
                    printf("*");
                }
                {
                    cnt++;
                    printf("\n");
                }
            }

        }
        else { //�Է��� ���� Ȧ�� �϶�
            cnt = (star + 1) / 2 - 1;
            for (int i = 1; i <= star; i += 2) {
                for (int k = cnt; 1 <= k; k--) {
                    printf(" ");
                }
                for (int j = 1; j <= i; j++) {
                    printf("*");
                }
                {
                    cnt--;
                    printf("\n");
                }
            }
            for (int n = 3; n <= star; n += 2) {
                for (int l = cnt; 0 <= l + 1; l--) {
                    printf(" ");
                }
                for (int m = star - 1; n <= m + 1; m--) {
                    printf("*");
                }
                {
                    cnt++;
                    printf("\n");
                }
            }
        }
    }
    return 0;
}
