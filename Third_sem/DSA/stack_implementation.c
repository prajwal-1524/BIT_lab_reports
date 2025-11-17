#include <stdio.h>

#define MAX 100

// ---------- Prototypes ----------
void init();
int isFull();
int isEmpty();
void push(int x);
int pop();
int peek();

// ---------- Global Stack ----------
int stack[MAX];
int top = -1;

// ---------- Functions ----------
void init() {
    top = -1;
}

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int x) {
    if (isFull())
        printf("Overflow\n");
    else
        stack[++top] = x;
}




// ---------- Main ----------
int main() {
    init();
    push(10);
    push(20);
    push(30);

    printf("Top: %d\n", peek());
    printf("Popped: %d\n", pop());
    printf("Top now: %d\n", peek());

    return 0;
}
