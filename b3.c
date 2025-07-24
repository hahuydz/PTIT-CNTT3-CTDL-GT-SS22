#include <stdio.h>
#include <stdlib.h>

int n;
typedef struct Node {
    int vertex;
    struct Node* next;
}Node;

Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addLast(Node** head, int vertex) {
    Node* temp = *head;
    if ( temp == NULL) {
        temp = createNode(vertex);
        *head = temp;
    }else {
        while ( temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = createNode(vertex);
    }
}

void convert(int arr[n][n], Node* adjNode[n]) {
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            if ( arr[i][j] == 1) addLast(&adjNode[i], j);
        }
    }
}

int main(void) {
    printf("Nhap n: ");
    scanf("%d", &n);

    int adj[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     printf("%d : ", i);
    //     for (int j = 0; j < n; ++j) {
    //         if (adj[i][j] == 1) {
    //             printf("%d -> ", j);
    //         }
    //     }
    //     printf("NULL \n");
    // }

    Node* adjNode[n];
    for (int i = 0; i < n; i++) {
        adjNode[i] = NULL;
    }
    convert(adj, adjNode);

    for (int i = 0; i < n; i++) {
        Node* temp = adjNode[i];
        printf("%d: ", i);
        while ( temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}
