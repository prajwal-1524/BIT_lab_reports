#include <stdio.h>
#include <ctype.h>

char stack[50];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

int main() {
    char infix[50], postfix[50];
    int i, j = 0;
    
    printf("Enter infix: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {         // Operand
            postfix[j++] = c;
        }
        else {                    // Operator
            while (top != -1 && priority(stack[top]) >= priority(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    while (top != -1)             // Pop remaining operators
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix: %s\n", postfix);

    return 0;
}
