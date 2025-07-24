#include <stdio.h>

int n;
void addEdge(int adj[n][n], int u, int v) {
    adj[u][v] = adj[v][u] = 1;
}

int main(void) {
    printf("Nhap dinh: ");
    scanf("%d", &n);
    int adjMatrix[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 3, 2);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 3, 4);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
