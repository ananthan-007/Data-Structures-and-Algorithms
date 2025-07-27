#include <stdio.h>
#include <string.h>
#define MAX 100  // Maximum size of stack and expression arrays

// Global declarations
char stack[MAX], infix[MAX], postfix[MAX];
int top = -1;

// Check if the stack is full
int isFull() {
    if (top == MAX - 1) { 
        return 1; 
    }
    return 0;
}

// Check if the stack is empty
int isEmpty() {
    if (top == -1) { 
        return 1; 
    }
    return 0;
}

// Push an element onto the stack
void push(char value) {
    if (!isFull()) {
        stack[++top] = value;
    } else {
        printf("Stack Overflow!\n");
    }
}

// Pop an element from the stack
int pop() {
    if (!isEmpty()) {
        return stack[top--];
    } else {
        printf("Stack Underflow!\n");
        return -1;  // Return an invalid value on underflow
    }
}

// Peek at the top element of the stack
int peek() {
    if (!isEmpty()) {
        return stack[top];
    } else {
        printf("Stack is Empty\n");
        return -1;
    }
}

// Return precedence of operators
int precedence(char operator) {
    switch (operator) {
        case '^': return 3;   // Highest precedence
        case '*':
        case '/': return 2;   // Medium precedence
        case '+':
        case '-': return 1;   // Lowest precedence
        default : return 0;   // Not an operator
    }
}

// Function to convert infix to postfix
void intoPost() {
    int i, j = 0;
    char symbol;

    for(i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        switch (symbol) {
            case '(':  // If opening parenthesis, push to stack
                push(symbol);
                break;

            case ')':  // If closing parenthesis, pop till '(' is found
                while (peek() != '(' && peek() != '\0') {
                    postfix[j++] = pop();
                }
                pop();  // Pop the '('
                break;

            // If operator
            case '-':
            case '+':
            case '*':
            case '/':
            case '^':
                // Pop operators from stack with higher or equal precedence
                while (!isEmpty() && precedence(peek()) >= precedence(symbol)) {
                    postfix[j++] = pop();
                }
                push(symbol);  // Push current operator
                break;

            default:
                // If operand, add to postfix directly
                postfix[j++] = symbol;
                break;
        }
    }

    // Pop any remaining operators in the stack
    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression
}

// Function to display the postfix expression
void displayPost() {
    printf("Postfix expression: %s", postfix);
}

int main() {
    // Input infix expression from user
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    // Convert to postfix
    intoPost();

    // Display result
    displayPost();
}
