#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Structure to represent the circular queue
struct CircularQueue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to initialize the circular queue
void initialize(struct CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue* queue) {
    return (queue->front == (queue->rear + 1) % MAX_SIZE);
}

// Function to enqueue (insert) an element into the circular queue
void enqueue(struct CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Enqueue operation failed.\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % MAX_SIZE;
        }
        queue->items[queue->rear] = value;
        printf("%d enqueued to the queue.\n", value);
    }
}

// Function to dequeue (remove) an element from the circular queue
int dequeue(struct CircularQueue* queue) {
    int value;
    if (isEmpty(queue)) {
        printf("Queue is empty. Dequeue operation failed.\n");
        return -1;
    } else {
        value = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        return value;
    }
}

// Function to display the elements in the circular queue
void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i;
        for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE) {
            printf("%d ", queue->items[i]);
        }
        printf("%d\n", queue->items[i]);
    }
}

int main() {
    struct CircularQueue queue;
    initialize(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);

    display(&queue);

    int dequeued = dequeue(&queue);
    if (dequeued != -1) {
        printf("Dequeued element: %d\n", dequeued);
    }

    enqueue(&queue, 6);
    display(&queue);

    return 0;
}
