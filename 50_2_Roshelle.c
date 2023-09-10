#include <stdio.h>

// Function to calculate factorial of a number
unsigned long long factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// Function to generate Pascal's Triangle and store it in an array
void generatePascalsTriangle(int numRows, unsigned long long triangle[][numRows]) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            // Calculate the binomial coefficient using the factorial function
            triangle[i][j] = factorial(i) / (factorial(j) * factorial(i - j));
        }
    }
}

int main() {
    int numRows;

    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &numRows);

    if (numRows <= 0) {
        printf("Number of rows should be greater than 0.\n");
        return 1;
    }

    unsigned long long triangle[numRows][numRows];

    // Generate and print Pascal's Triangle
    generatePascalsTriangle(numRows, triangle);

    printf("Pascal's Triangle:\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%llu ", triangle[i][j]);
        }
        printf("\n");
    }

    return 0;
}

