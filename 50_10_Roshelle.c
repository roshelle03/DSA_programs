#include <stdio.h>

// Function to print unique elements in an array
void printUniqueElements(int arr[], int size) {
    printf("Unique elements in the array: ");
    
    for (int i = 0; i < size; i++) {
        int isUnique = 1; // Flag to check uniqueness
        
        // Check if arr[i] is unique by comparing with previous elements
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isUnique = 0;
                break; // Exit the loop if a duplicate is found
            }
        }
        
        // If arr[i] is unique, print it
        if (isUnique) {
            printf("%d ", arr[i]);
        }
    }
    
    printf("\n");
}
int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];

    printf("Enter elements for the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printUniqueElements(array, size);

    return 0;
}
