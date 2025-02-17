#include <stdio.h>
#include <stdlib.h>

// Structure for singly linked list node
struct SinglyNode {
    int data;
    struct SinglyNode* next;
};


struct DoublyNode {
    int data;
    struct DoublyNode* prev;
    struct DoublyNode* next;
};


void createAndDisplaySinglyList() {
    struct SinglyNode *head = NULL, *temp = NULL;
    int i;

    printf("Singly Linked List:\n");

    for (i = 1; i <= 5; i++) {
        struct SinglyNode* newNode = (struct SinglyNode*)malloc(sizeof(struct SinglyNode));
        newNode->data = i * 10;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to create and display doubly linked list
void createAndDisplayDoublyList() {
    struct DoublyNode *head = NULL, *temp = NULL;
    int i;

    printf("Doubly Linked List:\n");

    for (i = 1; i <= 5; i++) {
        struct DoublyNode* newNode = (struct DoublyNode*)malloc(sizeof(struct DoublyNode));
        newNode->data = i * 10;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    createAndDisplaySinglyList();
    createAndDisplayDoublyList();
    return 0;
}
