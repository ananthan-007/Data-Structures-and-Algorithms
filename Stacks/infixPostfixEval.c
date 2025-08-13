#include <stdio.h>    // for printf, scanf
#include <string.h>   // for strlen
#include <math.h>     // for pow()
#define MAX 100       // maximum stack size

char infix[MAX], postfix[MAX], stack[MAX]; 
int top = -1; // stack top index, -1 means empty

// Push a value onto the stack
void push(char value) {
    if (top == MAX - 1) {
        printf("Stack overflow!");
        return;
    }
    stack[++top] = value; // increment top and store value
}

// Pop a value from the stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow!");
        return '\0'; // return null char if stack is empty
    }
    return stack[top--]; // return top element and decrement top
}

// Peek at the top value of the stack without removing it
char peek() {
    if (top == -1) {
        printf("Stack Underflow!");
        return '\0';
    }
    return stack[top];
}

// Determine precedence of operators
int precedence(char symbol) {
    switch (symbol) {
        case '^': return 3; // highest precedence
        case '*':
        case '/': return 2; // multiplication/division
        case '+':
        case '-': return 1; // addition/subtraction
        default: return 0;  // for non-operators
    }
}

// Convert infix expression to postfix
void intopost(char infix[]) {
    int i, j = 0; // i = position in infix, j = position in postfix
    for (i = 0; i < strlen(infix); i++) {
        char symbol = infix[i]; // current character

        switch (symbol) {
            case '(':
                push('('); // push opening parenthesis
                break;

            case ')':
                // Pop until '(' is found
                while (peek() != '(' && top != -1) {
                    postfix[j++] = pop();
                }
                pop(); // remove '(' from stack
                break;

            // Operators
            case '^':
            case '*':
            case '/':
            case '+':
            case '-':
                // While stack has higher/equal precedence operator, pop it
                while (top != -1 &&
                      (precedence(peek()) > precedence(symbol) ||
                      (precedence(peek()) == precedence(symbol) && symbol != '^'))) {
                    postfix[j++] = pop();
                }
                push(symbol); // push the current operator
                break;

            // Operands (numbers/variables) go directly to postfix
            default:
                postfix[j++] = symbol;
                break;
        }
    }

    // Pop remaining operators from stack
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // null-terminate postfix string
}

// Evaluate the postfix expression
int postEval() {
    int i;
    char symbol;

    for (i = 0; i < strlen(postfix); i++) {
        symbol = postfix[i];

        // If symbol is a digit, push its integer value
        if (symbol >= '0' && symbol <= '9') {
            push(symbol - '0'); // convert char digit to integer
        } else {
            // Pop top two values (a = first popped, b = second popped)
            int a = pop();
            int b = pop();

            // Perform operation based on symbol
            switch (symbol) {
                case '^': push(pow(b, a)); break;
                case '*': push(b * a); break;
                case '/': push(b / a); break;
                case '+': push(b + a); break;
                case '-': push(b - a); break;
            }
        }
    }
    return pop(); // Final result
}

// Display postfix expression
void displayPost() {
    printf("Postfix expression: %s", postfix);
}

int main() {
    printf("Enter the Infix expression: ");
    scanf("%s", infix); // read input (no spaces allowed)

    intopost(infix);     // convert to postfix
    displayPost();       // print postfix
    int result = postEval(); // evaluate postfix
    printf("\nEvaluated Postfix: %d", result); // print result

    return 0;
}
