#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 100  // Maximum size for stack and expression

// Global variables
char postfix[MAX];   // To store the postfix expression
int stack[MAX];      // Stack for integer operands
int top = -1;        // Top of the stack

// Function to check if the stack is full
int isFull() {
    if (top == MAX - 1) {
        return 1;
    }
    return 0;
}

// Function to check if the stack is empty
int isEmpty() {
    if (top == -1) {
        return 1;
    }
    return 0;
}

// Push an integer value onto the stack
void push(int value) {
    if (!isFull()) {
        stack[++top] = value;
    } else {
        printf("Stack Overflow!\n");
    }
}

// Pop an integer value from the stack
int pop() {
    if (!isEmpty()) {
        return stack[top--];
    } else {
        printf("Stack Underflow!\n");
        return -1;  // Return invalid value on underflow
    }
}

// Function to evaluate a postfix expression
int postfix_eval() {
    int i = 0;
    char symbol;

    // Loop through each character in the postfix expression
    for (i = 0; i < strlen(postfix); i++) {
        symbol = postfix[i];

        // If it's a digit (operand), convert from char to int and push
        if (symbol >= '0' && symbol <= '9') {
            push(symbol - '0');  // '3' -> 3
        } else {
            // Operator: pop two operands from stack
            int a = pop();  // Right operand
            int b = pop();  // Left operand

            // Perform the operation based on the operator
            switch (symbol) {
                case '*':
                    push(b * a);
                    break;
                case '/':
                    push(b / a);
                    break;
                case '+':
                    push(b + a);
                    break;
                case '-':
                    push(b - a);
                    break;
                case '^':
                    push((int)pow(b, a));  // Use pow for exponentiation
                    break;
            }
        }
    }

    // The final result will be the only value left in the stack
    return pop();
}

// Main function
int main() {
    printf("Enter the Postfix notation: ");
    scanf("%s", postfix);  // Read postfix expression

    int result = postfix_eval();  // Evaluate the postfix expression

    printf("Result: %d\n", result);  // Print the result

    return 0;
}
