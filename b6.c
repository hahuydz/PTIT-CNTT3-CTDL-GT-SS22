#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Node {
    int  vertex;
    struct Node* next;
} Node;

Node* adjList[MAX];
int visited[MAX];
int n;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node* nodeV = createNode(v);
    nodeV->next = adjList[u];
    adjList[u] = nodeV;

    Node* nodeU = createNode(u);
    nodeU->next = adjList[v];
    adjList[v] = nodeU;
}

void dfs(int u, int depth) {
    visited[u] = 1;
    printf("%d\t", u);

    Node* temp = adjList[u];
    while (temp != NULL) {
        int v = temp->vertex;
        if (!visited[v]) {
            dfs(v, depth + 1);
        }
        temp = temp->next;
    }
}

int main() {
    int edges;
    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &n, &edges);

    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }
    printf("Nhap cac canh (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int start;
    printf("Nhap dinh bat dau DFS: ");
    scanf("%d", &start);

    printf("Cac dinh dc duyet theo DFS tu %d: ", start);
    dfs(start, 0);
    return 0;
}
