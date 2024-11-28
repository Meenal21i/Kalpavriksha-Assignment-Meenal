#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;   
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int applyOperation(int a, int b, char op)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/')
    {
        if (b == 0)
        {
            printf("Error: Division by zero.\n");
            exit(1);
        }
        return a / b;
    }
    return 0;
}

void solve(char str[], int n)
{
    int values[MAX], valueTop = -1; // Stack for numbers
    char ops[MAX], opsTop = -1;     // Stack for operators

    for (int i = 0; i < n; i++)
    {
        if (isspace(str[i]))
            continue; // Ignore whitespace

        if (isdigit(str[i]))
        {
            int val = 0;

            // Read multi-digit numbers
            while (i < n && isdigit(str[i]))
            {
                val = val * 10 + (str[i] - '0');
                i++;
            }
            i--;
            values[++valueTop] = val; // Push the number to the stack
        }
        else if (str[i] == '(')
        {
            ops[++opsTop] = str[i]; // Push '(' to the operators stack
        }
        else if (str[i] == ')')
        {
            while (opsTop >= 0 && ops[opsTop] != '(')
            {
                int b = values[valueTop--];
                int a = values[valueTop--];
                char op = ops[opsTop--];
                values[++valueTop] = applyOperation(a, b, op);
            }
            if (opsTop >= 0 && ops[opsTop] == '(')
                opsTop--; // Pop '('
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            while (opsTop >= 0 && precedence(ops[opsTop]) >= precedence(str[i]))
            {
                int b = values[valueTop--];
                int a = values[valueTop--];
                char op = ops[opsTop--];
                values[++valueTop] = applyOperation(a, b, op);
            }
            ops[++opsTop] = str[i]; // Push current operator
        }
        else
        {
            printf("Error: Invalid expression.\n");
            exit(1);
        }
    }

    // Apply remaining operations
    while (opsTop >= 0)
    {
        int b = values[valueTop--];
        int a = values[valueTop--];
        char op = ops[opsTop--];
        values[++valueTop] = applyOperation(a, b, op);
    }

    printf("Result: %d\n", values[valueTop]);
}

// Driver function
int main()
{
    char expression[MAX];
    printf("Enter a mathematical expression: ");
    fgets(expression, MAX, stdin);

    int length = strlen(expression);
    if (expression[length - 1] == '\n')
        expression[length - 1] = '\0'; // Remove newline

    solve(expression, strlen(expression));
    return 0;
}
