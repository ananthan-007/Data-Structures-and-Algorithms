#include <stdio.h>
#include <stdbool.h> 
#define MAX 5  // Maximum size of the stack

int Stack[MAX];  // Array to store stack elements
int top = -1;    // Top points to the top element in the stack

// Function to check if the stack is full
bool isFull() {
    if (top == MAX - 1) { 
        return true; 
    }
    return false;
}

// Function to check if the stack is empty
bool isEmpty() {
    if (top == -1) { 
        return true; 
    }
    return false;
}

// Function to push an element onto the stack
void push(int value) {
    if (!isFull()) {
        Stack[++top] = value;  // Increment top and add value
    } else {
        printf("Stack Overflow!\n");
    }
}

// Function to pop the top element from the stack
int pop() {
    if (!isEmpty()) {
        return Stack[top--];  // Return top element and decrement top
    } else {
        printf("Stack Underflow!\n");
        return -1;
    }
}

// Function to get the top element without removing it
int peek() {
    if (!isEmpty()) {
        return Stack[top];
    } else {
        printf("Stack is Empty\n");
        return -1;
    }
}

// Function to display all elements in the stack
void display() {
    if (isEmpty()) {
        printf("Stack is Empty!\n");
    } else {
        printf("Stack elements : ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", Stack[i]);  // Print from top to bottom
        }
    }
    printf("\n");
}

// Main function to demonstrate stack operations
int main() {
    // Push 6 elements (last push will trigger overflow)
    push(10), push(20), push(30), push(40), push(50), push(60);

    display();  // Show current stack

    // Pop two elements and display them
    printf("Popped: %d\n", pop());
    printf("Popped: %d\n", pop());

    // Peek at the current top element
    printf("Stack (Peek)top: %d\n", peek());

    // Push one more element
    push(60);

    display();  // Show stack after push

    // Pop all remaining elements (last pop will trigger underflow)
    pop(), pop(), pop(), pop(), pop();
    
    return 0;
}
