#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 100  
typedef struct Node {
    int user;
    struct Node* next;
} Node;


Node* adjList[MAX_USERS];  
int visited[MAX_USERS]; 



Node* createNode(int user) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->user = user;
    newNode->next = NULL;
    return newNode;
}


void addEdge(int user1, int user2) {
    
    Node* newNode = createNode(user2);
    newNode->next = adjList[user1];
    adjList[user1] = newNode;

   
    newNode = createNode(user1);
    newNode->next = adjList[user2];
    adjList[user2] = newNode;
}

void dfsTraversal(int startUser) {
    printf("%d ", startUser);
    visited[startUser] = 1;

    Node* temp = adjList[startUser];
    while (temp != NULL) {
        if (!visited[temp->user]) {
            dfsTraversal(temp->user);
        }
        temp = temp->next;
    }
}


int main() {
    int users = 5;  
    
    
    for (int i = 0; i < MAX_USERS; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

   
    addEdge(1, 2);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(4, 5);

    printf("DFS Traversal starting from user 1:\n");
    dfsTraversal(1);

    return 0;
}
