#include <stdio.h>

int main(void) {
    int n;
    printf("Nhap dinh n: ");
    scanf("%d", &n);

    int adj[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ( adj[i][j] == 1) count++;
        }
    }

    printf("So canh: %d", count/2);
    return 0;
}
