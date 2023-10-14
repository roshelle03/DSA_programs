#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the priority queue
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data, int priority) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}

// Function to insert an element into the priority queue
void enqueue(struct Node** front, int data, int priority) {
    struct Node* newNode = newNode(data, priority);
    if (*front == NULL || priority < (*front)->priority) {
        newNode->next = *front;
        *front = newNode;
    } else {
        struct Node* current = *front;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to remove and return the element with the highest priority
int dequeue(struct Node** front) {
    if (*front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    struct Node* temp = *front;
    int data = temp->data;
    *front = temp->next;
    free(temp);
    return data;
}

// Function to check if the priority queue is empty
int isEmpty(struct Node* front) {
    return (front == NULL);
}

// Function to display the elements in the priority queue
void display(struct Node* front) {
    struct Node* current = front;
    while (current != NULL) {
        printf("(%d, %d) ", current->data, current->priority);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* front = NULL;

    enqueue(&front, 10, 2);
    enqueue(&front, 20, 1);
    enqueue(&front, 30, 3);
    enqueue(&front, 40, 2);

    printf("Priority Queue: ");
    display(front);

    printf("Dequeue: %d\n", dequeue(&front));

    printf("Priority Queue after dequeue: ");
    display(front);

    return 0;
}
