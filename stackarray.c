#include <stdio.h>
#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        return;
    }
    stack->top++;
    stack->items[stack->top] = value;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    int poppedItem = stack->items[stack->top];
    stack->top--;
    return poppedItem;
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->items[stack->top];
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    int topElement = peek(&stack);
    printf("Top element: %d\n", topElement);

    while (!isEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");

    return 0;
}
