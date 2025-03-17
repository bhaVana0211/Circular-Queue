/*WAP in C to implement operations on Circular Queue.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Queue;
void initQueue(Queue *q) {
    q->front = q->rear = -1;
}
int isEmpty(Queue *q) {
    return (q->front == -1);
}
int isFull(Queue *q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);
}
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->data[q->rear] = value;
}
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return value;
}
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int i = q->front;
    do {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (q->rear + 1) % MAX_SIZE);
    printf("\n");
}
int main() {
    Queue q;
    initQueue(&q);
    int choice, value;
    while (1) {
        printf("Circular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
         {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1)
                    printf("Dequeued value: %d\n", value);
                break;
            case 3:
                printf("Queue elements: ");
                display(&q);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}


