#include <stdio.h>

int isPerfectSquare(int n) {
    int x = 0;
    while ((x * x) <= n) {
        if ((x * x) == n) {
            return 1;
        }
        x++;
    }
    return 0;
}

int isFibonacci(int num) {
    // A number 'num' is Fibonacci if and only if one of
    // (5 * num * num + 4) or (5 * num * num - 4) is a perfect square
    return isPerfectSquare(5 * num * num + 4) || isPerfectSquare(5 * num * num - 4);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isFibonacci(num)) {
        printf("%d is part of the Fibonacci series.\n", num);
    } else {
        printf("%d is not part of the Fibonacci series.\n", num);
    }

    return 0;
}