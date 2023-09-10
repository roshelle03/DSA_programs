#include <stdio.h>

// Function to count duplicate elements in an array
int countDuplicates(int arr[], int size) {
    int count = 0;

    // Loop through each element in the array
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            // If a duplicate is found
            if (arr[i] == arr[j]) {
                count++;
                break; // Exit the inner loop to avoid counting the same element multiple times
            }
        }
    }

    return count;
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

    int duplicateCount = countDuplicates(array, size);

    printf("Total number of duplicate elements: %d\n", duplicateCount);

    return 0;
}
