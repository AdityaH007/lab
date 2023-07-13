#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define STACK_SIZE 100

typedef struct {
    char data[STACK_SIZE];
    int top;
} Stack;

void push(Stack *stack, char value) {
    if (stack->top < STACK_SIZE)
        stack->data[++(stack->top)] = value;
    else
        printf("Stack overflow!\n");
}

char pop(Stack *stack) {
    if (stack->top >= 0)
        return stack->data[(stack->top)--];
    else {
        printf("Stack underflow!\n");
        return '\0'; // Assuming '\0' represents an error value
    }
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrecedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0;
}

void infixToPrefix(char *infix, char *prefix) {
    Stack operatorStack;
    operatorStack.top = -1;

    int infixLength = strlen(infix);
    int prefixIndex = 0;

    for (int i = infixLength - 1; i >= 0; i--) {
        if (infix[i] == ' ')
            continue;

        if (isOperator(infix[i])) {
            while (operatorStack.top >= 0 && getPrecedence(operatorStack.data[operatorStack.top]) > getPrecedence(infix[i])) {
                prefix[prefixIndex++] = pop(&operatorStack);
                prefix[prefixIndex++] = ' ';
            }
            push(&operatorStack, infix[i]);
        } else if (infix[i] == ')') {
            push(&operatorStack, infix[i]);
        } else if (infix[i] == '(') {
            while (operatorStack.top >= 0 && operatorStack.data[operatorStack.top] != ')') {
                prefix[prefixIndex++] = pop(&operatorStack);
                prefix[prefixIndex++] = ' ';
            }
            if (operatorStack.top >= 0 && operatorStack.data[operatorStack.top] == ')')
                pop(&operatorStack); // Discard the '('
        } else {
            while (i >= 0 && isdigit(infix[i])) {
                prefix[prefixIndex++] = infix[i--];
            }
            prefix[prefixIndex++] = ' ';
            i++; // Adjust the index after the digit sequence
        }
    }

    while (operatorStack.top >= 0) {
        prefix[prefixIndex++] = pop(&operatorStack);
        prefix[prefixIndex++] = ' ';
    }

    prefix[prefixIndex] = '\0';

    // Reverse the prefix expression
    int start = 0;
    int end = prefixIndex - 2;
    while (start < end) {
        char temp = prefix[start];
        prefix[start] = prefix[end];
        prefix[end] = temp;
        start++;
        end--;
    }
}

int evaluatePrefixExpression(char *expression) {
    Stack stack;
    stack.top = -1;
    int i;

    for (i = strlen(expression) - 1; i >= 0; i--) {
        if (expression[i] == ' ')
            continue;

        if (isdigit(expression[i])) {
            int operand = 0;
            while (isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                i--;
            }
            push(&stack, operand);
        } else {
            int operand1 = pop(&stack);
            int operand2 = pop(&stack);
            int result;

            switch (expression[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %c\n", expression[i]);
                    return -1; // Assuming -1 represents an error value
            }

            push(&stack, result);
        }
    }

    return pop(&stack);
}

int main() {
    char infixExpression[] = "-+7*4 5+2 0";
    printf("Infix Expression: %s\n", infixExpression);

    char prefixExpression[STACK_SIZE];
    infixToPrefix(infixExpression, prefixExpression);
    printf("Prefix Expression: %s\n", prefixExpression);

    int result = evaluatePrefixExpression(prefixExpression);
    printf("Result: %d\n", result);

    return 0;
}
