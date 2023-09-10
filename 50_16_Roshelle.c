#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly linked list node
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Define a structure for the stack
struct Stack {
    struct Node *top;
};

// Function to initialize an empty stack
void initStack(struct Stack *stack) {
    stack->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return (stack->top == NULL);
}

// Function to push an element onto the stack
void push(struct Stack *stack, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d onto the stack.\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        exit(1);
    }
    struct Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Function to get the top element of the stack without removing it
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        exit(1);
    }
    return stack->top->data;
}

// Function to display the elements of the stack
void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    struct Node *current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initStack(&stack);
    int choice, data;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                if (!isEmpty(&stack)) {
                    printf("Popped %d from the stack.\n", pop(&stack));
                } else {
                    printf("Stack is empty. Cannot pop.\n");
                }
                break;
            case 3:
                if (!isEmpty(&stack)) {
                    printf("Top element of the stack: %d\n", peek(&stack));
                } else {
                    printf("Stack is empty. Cannot peek.\n");
                }
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                printf("Quitting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
