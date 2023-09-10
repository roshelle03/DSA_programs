#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Structure to represent a stack of integers
struct Stack {
    int top;
    int capacity;
    int* array;
};

// Function to create a new stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return -1; // Return -1 if the stack is empty
}

// Function to perform arithmetic operations
int performOperation(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Error: Division by zero\n");
                exit(1);
            }
            return operand1 / operand2;
        default:
            printf("Error: Invalid operator\n");
            exit(1);
    }
}

// Function to evaluate an arithmetic expression
int evaluateExpression(const char* expression) {
    struct Stack* operandStack = createStack(strlen(expression));
    struct Stack* operatorStack = createStack(strlen(expression));

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            int operand = 0;
            while (isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            push(operandStack, operand);
        } else if (expression[i] == '(') {
            push(operatorStack, expression[i]);
        } else if (expression[i] == ')') {
            while (!isEmpty(operatorStack) && operatorStack->array[operatorStack->top] != '(') {
                int operand2 = pop(operandStack);
                int operand1 = pop(operandStack);
                char op = pop(operatorStack);
                int result = performOperation(operand1, operand2, op);
                push(operandStack, result);
            }
            if (!isEmpty(operatorStack) && operatorStack->array[operatorStack->top] == '(') {
                pop(operatorStack); // Pop the '('
            }
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (!isEmpty(operatorStack) && operatorStack->array[operatorStack->top] != '(' &&
                   (expression[i] == '*' || expression[i] == '/') &&
                   (operatorStack->array[operatorStack->top] == '+' || operatorStack->array[operatorStack->top] == '-')) {
                int operand2 = pop(operandStack);
                int operand1 = pop(operandStack);
                char op = pop(operatorStack);
                int result = performOperation(operand1, operand2, op);
                push(operandStack, result);
            }
            push(operatorStack, expression[i]);
        }
    }

    while (!isEmpty(operatorStack)) {
        int operand2 = pop(operandStack);
        int operand1 = pop(operandStack);
        char op = pop(operatorStack);
        int result = performOperation(operand1, operand2, op);
        push(operandStack, result);
    }

    int finalResult = pop(operandStack);
    free(operandStack->array);
    free(operatorStack->array);
    free(operandStack);
    free(operatorStack);
    return finalResult;
}

int main() {
    char expression[100];

    printf("Enter an arithmetic expression: ");
    scanf("%s", expression);

    int result = evaluateExpression(expression);

    printf("Result of the expression: %d\n", result);

    return 0;
}
