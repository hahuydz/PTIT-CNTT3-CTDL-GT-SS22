#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
}Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = value;
    newNode->next = NULL;
    return newNode;
}
Node* adjacentNode[100];
void addEgde (int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjacentNode[u];
    adjacentNode[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjacentNode[v];
    adjacentNode[v] = newNode;
}

void printMatrix (int n) {
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        Node* temp = adjacentNode[i];
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n,u,v;
    printf("Nhap so dinh: ");
    scanf("%d", &n);
    for (int i = 0; i < 6; i++) {
        printf("nhap 2 dinh: ");
        scanf("%d %d", &u,&v);
        addEgde(u, v);
    }
    printf("\n");
    printMatrix(n);

}
