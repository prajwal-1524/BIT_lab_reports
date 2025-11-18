#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to push an element onto the stack
void push(struct Node** top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d\n", data);
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    struct Node* temp = *top;
    int data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

// Function to peek at the top element
int peek(struct Node* top) {
    if (top == NULL) return -1;
    return top->data;
}

// Function to display the stack
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct Node* stack = NULL;

    // Properly using push functions
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Display the stack
    display(stack);

    // Pop elements
    printf("Popped: %d\n", pop(&stack));
    printf("Top element: %d\n", peek(stack));

    // Display the stack after pop
    display(stack);

    return 0; // Ensure a proper return value
}
