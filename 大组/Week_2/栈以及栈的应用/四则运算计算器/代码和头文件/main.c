#include "../../栈/代码和头文件/head/LinkStack.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    LinkStack stack;
    initLStack(&stack);
    int i = 0, j = 0;
    while (infix[i]) {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i++];
            while (isdigit(infix[i]))
                postfix[j++] = infix[i++];
            postfix[j++] = ' ';
        } else if (isOperator(infix[i])) {
            while (!isEmptyLStack(&stack) && precedence(getTopLStack(&stack, NULL)) >= precedence(infix[i])) {
                char op;
                popLStack(&stack, &op);
                postfix[j++] = op;
                postfix[j++] = ' ';
            }
            pushLStack(&stack, infix[i++]);
        } else if (infix[i] == '(') {
            pushLStack(&stack, infix[i++]);
        } else if (infix[i] == ')') {
            char op;
            while (!isEmptyLStack(&stack) && getTopLStack(&stack, &op) != '(') {
                popLStack(&stack, &op);
                postfix[j++] = op;
                postfix[j++] = ' ';
            }
            popLStack(&stack, &op); // Pop '('
            i++;
        } else {
            i++; // Skip whitespace or other characters
        }
    }
    while (!isEmptyLStack(&stack)) {
        char op;
        popLStack(&stack, &op);
        postfix[j++] = op;
        postfix[j++] = ' ';
    }
    postfix[j] = '\0';
}

int evaluatePostfix(char* postfix) {
    LinkStack stack;
    initLStack(&stack);
    int i = 0;
    while (postfix[i]) {
        if (isdigit(postfix[i])) {
            int num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            pushLStack(&stack, num);
        } else if (isOperator(postfix[i])) {
            int operand2, operand1;
            popLStack(&stack, &operand2);
            popLStack(&stack, &operand1);
            switch (postfix[i]) {
                case '+':
                    pushLStack(&stack, operand1 + operand2);
                    break;
                case '-':
                    pushLStack(&stack, operand1 - operand2);
                    break;
                case '*':
                    pushLStack(&stack, operand1 * operand2);
                    break;
                case '/':
                    pushLStack(&stack, operand1 / operand2);
                    break;
            }
            i++;
        } else {
            i++; // Skip whitespace or other characters
        }
    }
    int result;
    popLStack(&stack, &result);
    return result;
}

int main() {
    char infix[100];
    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove newline character from input
    char postfix[100];
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}