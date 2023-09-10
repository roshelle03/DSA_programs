#include <stdio.h>
#include <string.h>

// Define a structure to represent a student
struct Student {
    int roll_no;
    char name[50];
    float percentage;
};

int main() {
    // Declare an array of structures to store 5 students' records
    struct Student students[5];

    // Input student records
    printf("Enter details of 5 students:\n");
    for (int i = 0; i < 5; i++) {
        printf("Student %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Percentage: ");
        scanf("%f", &students[i].percentage);
    }

    // Sort the students' records based on roll numbers in ascending order
    struct Student temp;
    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (students[j].roll_no > students[j + 1].roll_no) {
                // Swap the records
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    // Display the sorted records
    printf("\nStudent Records in Ascending Order of Roll No:\n");
    printf("Roll No\tName\tPercentage\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\t%s\t%.2f\n", students[i].roll_no, students[i].name, students[i].percentage);
    }

    return 0;
}
