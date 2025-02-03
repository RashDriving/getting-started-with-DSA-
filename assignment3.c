#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_SIZE 5
#define DEQUE_SIZE 4

// Structure for a student
typedef struct {
    int id;
    char name[50];
} Student;

// Queue for normal students (FIFO)
typedef struct {
    Student students[QUEUE_SIZE];
    int front, rear;
} Queue;

// Deque for priority students
typedef struct {
    Student students[DEQUE_SIZE];
    int front, rear;
} Deque;

// Queue Functions
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueFull(Queue *q) {
    return (q->rear == QUEUE_SIZE - 1);
}

int isQueueEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(Queue *q, int id, char name[]) {
    if (isQueueFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->students[q->rear].id = id;
    strcpy(q->students[q->rear].name, name);
}

void dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued: %d, %s\n", q->students[q->front].id, q->students[q->front].name);
    q->front++;
}

void displayQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("(%d, %s) ", q->students[i].id, q->students[i].name);
    }
    printf("\n");
}


void initDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isDequeFull(Deque *dq) {
    return ((dq->rear + 1) % DEQUE_SIZE == dq->front);
}

int isDequeEmpty(Deque *dq) {
    return (dq->front == -1);
}

void insertFront(Deque *dq, int id, char name[]) {
    if (isDequeFull(dq)) {
        printf("Deque Overflow\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + DEQUE_SIZE) % DEQUE_SIZE;
    }
    dq->students[dq->front].id = id;
    strcpy(dq->students[dq->front].name, name);
}

void insertRear(Deque *dq, int id, char name[]) {
    if (isDequeFull(dq)) {
        printf("Deque Overflow\n");
        return;
    }
    if (dq->rear == -1) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % DEQUE_SIZE;
    }
    dq->students[dq->rear].id = id;
    strcpy(dq->students[dq->rear].name, name);
}

void deleteFront(Deque *dq) {
    if (isDequeEmpty(dq)) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted Front: %d, %s\n", dq->students[dq->front].id, dq->students[dq->front].name);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % DEQUE_SIZE;
    }
}

void deleteRear(Deque *dq) {
    if (isDequeEmpty(dq)) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted Rear: %d, %s\n", dq->students[dq->rear].id, dq->students[dq->rear].name);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + DEQUE_SIZE) % DEQUE_SIZE;
    }
}

void displayDeque(Deque *dq) {
    if (isDequeEmpty(dq)) {
        printf("Deque is Empty\n");
        return;
    }
    printf("Deque: ");
    int i = dq->front;
    while (1) {
        printf("(%d, %s) ", dq->students[i].id, dq->students[i].name);
        if (i == dq->rear) break;
        i = (i + 1) % DEQUE_SIZE;
    }
    printf("\n");
}


int main() {
    Queue q;
    Deque dq;
    
    initQueue(&q);
    initDeque(&dq);

    
    printf("\nQueue Test Cases:\n");
    enqueue(&q, 101, "Alice");
    enqueue(&q, 102, "Bob");
    enqueue(&q, 103, "Charlie");
    dequeue(&q);
    dequeue(&q);
    displayQueue(&q);

    enqueue(&q, 104, "David");
    enqueue(&q, 105, "Emma");
    enqueue(&q, 106, "Frank"); 
    displayQueue(&q);

    dequeue(&q);
    enqueue(&q, 107, "Grace");
    enqueue(&q, 108, "Hank");
    displayQueue(&q);

    while (!isQueueEmpty(&q)) dequeue(&q);
    dequeue(&q); 
    displayQueue(&q);

 
    printf("\nDeque Test Cases:\n");
    insertFront(&dq, 201, "Xavier");
    insertRear(&dq, 202, "Yvonne");
    insertRear(&dq, 203, "Zack");
    deleteFront(&dq);
    displayDeque(&dq);

    insertFront(&dq, 301, "Amy");
    insertRear(&dq, 302, "Brian");
    insertRear(&dq, 303, "Clara");
    deleteRear(&dq);
    deleteFront(&dq);
    displayDeque(&dq);

    insertRear(&dq, 401, "Oliver");
    insertRear(&dq, 402, "Sophia");
    insertRear(&dq, 403, "Liam");
    insertFront(&dq, 404, "Emma");
    insertRear(&dq, 405, "Jake"); 
    deleteFront(&dq);
    deleteRear(&dq);
    displayDeque(&dq);

    while (!isDequeEmpty(&dq)) deleteFront(&dq);
    deleteFront(&dq); 
    displayDeque(&dq);

    return 0;
}
