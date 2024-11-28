#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void expression_conversion();
int check_space_tabs(char character);
void push(char character);
char pop();
int priority(char character);
int isEmpty();

int top;
char stack[50];
char infix_expression[50], postfix_expression[50];

int main() {
    top = -1;
    printf("Enter an expression in infix format: ");
    fgets(infix_expression, sizeof(infix_expression), stdin);
    
    // Remove newline character from fgets
    infix_expression[strcspn(infix_expression, "\n")] = '\0';
    
    expression_conversion();
    printf("Expression in Postfix format: \t%s\n", postfix_expression);
    return 0;
}

void expression_conversion() {
    int count, temp = 0;
    char next;
    char character;

    for (count = 0; count < strlen(infix_expression); count++) {
        character = infix_expression[count];
        if (!check_space_tabs(character)) {
            switch (character) {
                case '(':
                    push(character);
                    break;
                case ')':
                    while ((next = pop()) != '(') {
                        postfix_expression[temp++] = next;
                    }
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
                    while (!isEmpty() && priority(stack[top]) >= priority(character)) {
                        postfix_expression[temp++] = pop();
                    }
                    push(character);
                    break;
                default:
                    postfix_expression[temp++] = character;
            }
        }
    }

    while (!isEmpty()) {
        postfix_expression[temp++] = pop();
    }
    postfix_expression[temp] = '\0';
}

int priority(char character) {
    switch (character) {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void push(char character) {
    if (top >= 49) { // Updated condition to reflect stack size
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = character;
}

int check_space_tabs(char character) {
    return (character == ' ' || character == '\t');
}

char pop() {
    if (isEmpty()) {
        printf("Stack is Empty\n");
        exit(1);
    }
    return stack[top--];
}

int isEmpty() {
    return (top == -1);
}