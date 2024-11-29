#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) { 
                printf("Error: Division by zero.\n"); 
                exit(1); 
            }
            return a / b;
        default: return 0;
    }
}

void solve(char str[], int n) {
    int stack[MAX], top = -1, num = 0;
    char op = '+';

    for (int i = 0; i < n; i++) {
        if (isspace(str[i])) continue; 

        if (isdigit(str[i])) {
            num = num * 10 + (str[i] - '0');
        } 

        if (str[i] == '-' && (i == 0 || strchr("+-*/", str[i - 1]))) {
            op = '-'; 
            continue; 
        }
        
        if (!isdigit(str[i]) && !isspace(str[i]) && !strchr("+-*/", str[i])) {
            printf("Invalid character Error\n", str[i]);
            exit(1);
        }

        
        if (!isdigit(str[i]) || i == n - 1) {
            if (op == '+') stack[++top] = num;
            else if (op == '-') stack[++top] = -num;
            else if (op == '*') stack[top] *= num;
            else if (op == '/') {
                if (num == 0) {
                    printf("Error: Division by zero.\n");
                    exit(1);
                }
                stack[top] /= num;
            }
            op = str[i];
            num = 0;
        }
    }

    int result = 0;
    for (int i = 0; i <= top; i++) result += stack[i];
    printf("Result: %d\n", result);
}

int main() {
    char expression[MAX];
    printf("Enter a mathematical expression: ");
    fgets(expression, MAX, stdin);

    int length = strlen(expression);
    if (expression[length - 1] == '\n') expression[length - 1] = '\0';

    solve(expression, strlen(expression));
    return 0;
}
