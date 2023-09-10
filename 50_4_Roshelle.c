#include <stdio.h>
#include <string.h>

// Define a structure to represent a student
struct Student {
    int roll_no;
    char name[50];
    float percentage;
};

// Function to swap two Student records
void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform a descending bubble sort based on percentage
void sortStudents(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].percentage < students[j + 1].percentage) {
                swap(&students[j], &students[j + 1]);
            }
        }
    }
}

int main() {
    int n = 5; // Number of students
    struct Student students[n];

    // Input student records
    printf("Enter student details:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        students[i].roll_no = i + 1;
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Percentage: ");
        scanf("%f", &students[i].percentage);
    }

    // Sort students in descending order of percentage
    sortStudents(students, n);

    // Display student records
    printf("\nStudent records in descending order of percentage:\n");
    printf("Roll No\tName\tPercentage\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\n", students[i].roll_no, students[i].name, students[i].percentage);
    }

    return 0;
}
