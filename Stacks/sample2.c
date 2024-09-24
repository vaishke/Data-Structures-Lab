#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int priority(char);
char infix[100];       // Input array to hold the infix expression
char operators[100];   // Stack to hold operators
int stack_top = -1;    // Stack pointer for the top of the operators stack

int main() {
    printf("Enter an infix expression: ");
    gets(infix); // Get the infix expression

    // Use a for loop to iterate through the infix expression
    for (int infix_index = 0; infix_index < strlen(infix); infix_index++) {
        // If the current character is an operand (number), print it directly
        if (isdigit(infix[infix_index])) {
            printf("%c", infix[infix_index]);
        }
        // If it's an opening parenthesis, push it onto the operators stack
        else if (infix[infix_index] == '(') {
            stack_top++;
            operators[stack_top] = '(';
        }
        // If it's a closing parenthesis, pop and print operators until '(' is found
        else if (infix[infix_index] == ')') {
            while (operators[stack_top] != '(') {
                printf("%c", operators[stack_top]);
                stack_top--;
            }
            stack_top--; // Remove the '(' from the stack
        }
        // If it's an operator
        else {
            // If the current operator has higher precedence, push it onto the stack
            if (priority(operators[stack_top]) < priority(infix[infix_index])) {
                stack_top++;
                operators[stack_top] = infix[infix_index];
            }
            // If the current operator has lower or equal precedence, pop operators
            else if (priority(operators[stack_top]) >= priority(infix[infix_index])) {
                if (priority(operators[stack_top]) == 3 && priority(infix[infix_index]) == 3) {
                    stack_top++;
                    operators[stack_top] = '^'; // Handle exponentiation separately
                } else {
                    while (priority(operators[stack_top]) >= priority(infix[infix_index])) {
                        printf("%c", operators[stack_top]);
                        stack_top--;
                    }
                    stack_top++;
                    operators[stack_top] = infix[infix_index];
                }
            }
        }
    }

    // After processing the entire infix expression, pop and print all remaining operators
    while (stack_top >= 0) {
        printf("%c", operators[stack_top]);
        stack_top--;
    }

    return 0;
}

// Function to determine operator precedence
int priority(char d) {
    if (d == '+') return 1;
    if (d == '-') return 1;
    if (d == '*') return 2;
    if (d == '/') return 2;
    if (d == '%') return 2;
    if (d == '^') return 3; // Higher precedence for exponentiation
    if (d == '(') return 0; // Lowest precedence for opening parenthesis
    return -1; // Return -1 for unknown operators
}
