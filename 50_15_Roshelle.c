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

// Function to insert a new node at the end of the linked list
void insert(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("Inserted %d into the linked list.\n", data);
}

// Function to delete a node with a given value from the linked list
void delete(struct Node **head, int data) {
    if (*head == NULL) {
        printf("Linked list is empty. Nothing to delete.\n");
        return;
    }

    struct Node *current = *head;
    struct Node *prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("%d not found in the linked list. Cannot delete.\n", data);
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    printf("Deleted %d from the linked list.\n", data);
    free(current);
}

// Function to display the linked list
void display(struct Node *head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    printf("Linked list elements: ");
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to search for a value in the linked list
int search(struct Node *head, int data) {
    struct Node *current = head;
    int position = 1;
    while (current != NULL) {
        if (current->data == data) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1; // Return -1 if the value is not found
}

int main() {
    struct Node *head = NULL;
    int choice, data;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&head, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete(&head, data);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Enter data to search: ");
                scanf("%d", &data);
                int position = search(head, data);
                if (position != -1) {
                    printf("%d found at position %d in the linked list.\n", data, position);
                } else {
                    printf("%d not found in the linked list.\n", data);
                }
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
