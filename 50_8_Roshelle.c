#include <stdio.h>

// Function to compare two arrays
int compareArrays(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return 0; // Arrays are not identical
        }
    }
    return 1; // Arrays are identical
}

int main() {
    int size;

    printf("Enter the size of the arrays: ");
    scanf("%d", &size);

    int array1[size];
    int array2[size];

    printf("Enter elements for the first array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array1[i]);
    }

    printf("Enter elements for the second array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array2[i]);
    }

    int result = compareArrays(array1, array2, size);

    if (result) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
