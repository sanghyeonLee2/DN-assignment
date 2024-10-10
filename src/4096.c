# include <stdio.h>


int main() {
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {
            for (int u = 0; u <= 7; u++) {
                for (int k = 1; k <= 8; k++) {
                    printf("%4d", (u * 64) + (j * 8) + k + (i * 512));
                    printf("");
                }

           }printf("\n");
        }
    }
    return 0;
}
