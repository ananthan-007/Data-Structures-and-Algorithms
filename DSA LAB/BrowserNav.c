#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[100];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;

struct Node* createNode(char *url) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void visitNewPage(char *url) {
    struct Node *newNode = createNode(url);

    if (head == NULL) {
        head = newNode;
        current = newNode;
        return;
    }

    struct Node *temp = current->next;
    while (temp != NULL) {
        struct Node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    current->next = NULL;

    current->next = newNode;
    newNode->prev = current;
    current = newNode;
}

void goBack() {
    if (current == NULL || current->prev == NULL)
        printf("No previous page!\n");
    else {
        current = current->prev;
        printf("Moved back to: %s\n", current->url);
    }
}

void goForward() {
    if (current == NULL || current->next == NULL)
        printf("No forward page!\n");
    else {
        current = current->next;
        printf("Moved forward to: %s\n", current->url);
    }
}


void displayHistory() {
    if (head == NULL) {
        printf("No browsing history.\n");
        return;
    }
    struct Node *temp = head;
    printf("Browsing history:\n");
    while (temp != NULL) {
        if (temp == current)
            printf("-> %s (current)\n", temp->url);
        else
            printf("   %s\n", temp->url);
        temp = temp->next;
    }
}

int main() {
    int choice;
    char url[100];

    while (1) {
        printf("\n--- Web Browser Navigation ---\n");
        printf("1. Visit new page\n");
        printf("2. Go back\n");
        printf("3. Go forward\n");
        printf("4. Show browsing history\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter URL: ");
            scanf("%s", url);
            visitNewPage(url);
            break;
        case 2:
            goBack();
            break;
        case 3:
            goForward();
            break;
        case 4:
            displayHistory();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}