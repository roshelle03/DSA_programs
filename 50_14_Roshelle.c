#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Deque {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

// Initialize an empty deque
void initDeque(struct Deque *deque) {
    deque->front = -1;
    deque->rear = -1;
}

// Check if the deque is empty
int isEmpty(struct Deque *deque) {
    return (deque->front == -1);
}

// Check if the deque is full
int isFull(struct Deque *deque) {
    return ((deque->front == 0 && deque->rear == MAX_SIZE - 1) || (deque->front == deque->rear + 1));
}

// Insert an element at the front of the deque
void insertFront(struct Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert at the front.\n");
        return;
    }

    if (deque->front == -1) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = MAX_SIZE - 1;
    } else {
        deque->front--;
    }

    deque->arr[deque->front] = value;
    printf("Inserted %d at the front.\n", value);
}

// Insert an element at the rear of the deque
void insertRear(struct Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert at the rear.\n");
        return;
    }

    if (deque->front == -1) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->rear == MAX_SIZE - 1) {
        deque->rear = 0;
    } else {
        deque->rear++;
    }

    deque->arr[deque->rear] = value;
    printf("Inserted %d at the rear.\n", value);
}

// Remove an element from the front of the deque
void deleteFront(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from the front.\n");
        return;
    }

    printf("Deleted %d from the front.\n", deque->arr[deque->front]);

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->front == MAX_SIZE - 1) {
        deque->front = 0;
    } else {
        deque->front++;
    }
}

// Remove an element from the rear of the deque
void deleteRear(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from the rear.\n");
        return;
    }

    printf("Deleted %d from the rear.\n", deque->arr[deque->rear]);

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->rear == 0) {
        deque->rear = MAX_SIZE - 1;
    } else {
        deque->rear--;
    }
}

// Display the elements of the deque
void display(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    int i = deque->front;

    while (1) {
        printf("%d ", deque->arr[i]);

        if (i == deque->rear)
            break;

        if (i == MAX_SIZE - 1)
            i = 0;
        else
            i++;
    }

    printf("\n");
}

int main() {
    struct Deque deque;
    initDeque(&deque);

    int choice, value;

    while (1) {
        printf("\nDouble-Ended Queue (Deque) Menu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display Deque\n");
        printf("6. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at the front: ");
                scanf("%d", &value);
                insertFront(&deque, value);
                break;
            case 2:
                printf("Enter value to insert at the rear: ");
                scanf("%d", &value);
                insertRear(&deque, value);
                break;
            case 3:
                deleteFront(&deque);
                break;
            case 4:
                deleteRear(&deque);
                break;
            case 5:
                display(&deque);
                break;
            case 6:
                printf("Quitting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
