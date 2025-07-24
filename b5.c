#include <stdio.h>

int n, v, k, count = 0;
void addEdge(int arr[n][n], int v1, int v2) {
    arr[v1][v2] = arr[v2][v1] = 1;
}

int main(void) {
    printf("Nhap dinh, canh: ");
    scanf("%d %d", &n, &v);
    int adj[n][n];

    for ( int i = 0; i< v; i++) {
        int v1, v2;
        printf("Nhap canh: ");
        scanf("%d %d", &v1, &v2);
        addEdge(adj,v1, v2);
    }

    printf("Nhap dinh k: ");
    scanf("%d", &k);

    for (int i = 0; i < n; i++) {
        if (adj[i][k] == 1) count++;
    }

    printf("So dinh ke voi %d la: %d", k, count);
    return 0;
}
