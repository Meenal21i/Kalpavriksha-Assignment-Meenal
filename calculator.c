#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

int digitCheck(int digit) {
    if(digit >= '0' && digit <= '9' ) {return 1;}
    return 0;
}
int spaceCheck(int space) {
    if (space == ' ') {return 1;}
    return 0;
}
char * searchChar(const char * str, char ch) {
    for(int i=0; i<strlen(str); i++) {
        if(str[i] == ch) {return (char*)str;}
    }
    return NULL;
}
int operatorCheck(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){return 1;}
    return 0;
}


int applyOperation(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': 
            if (operand2 == 0) { 
                printf("Error: Division by zero.\n"); 
                return -1;
            }
            return operand1 / operand2;
        default: return 0;
    }
}

int solve(char str[], int size) {
    for(int start=size-1, end=0; start>=0, end<size; start--, end++) {
        if(spaceCheck(str[start]) || spaceCheck(str[end])){ continue;}
        else if(operatorCheck(str[start]) || operatorCheck(str[end])) {
            printf("Invalid Expression\n");
            return -1;
        }
        break;
    }
    
    
    int stack[MAX], top = -1, num = 0;
    char operator = '+';

    for (int index = 0; index < size; index++) {
        if (spaceCheck(str[index])) continue; 

        if (digitCheck(str[index])) {
            num = num * 10 + (str[index] - '0');
        } 

        if (str[index] == '-' && (index == 0 || searchChar("+-*/", str[index - 1]))) {
            op = '-'; 
            continue; 
        }
        
        if (!digitCheck(str[index]) && !spaceCheck(str[index]) && !searchChar("+-*/", str[index])) {
            printf("Invalid expression\n");
            return -1;
        }
        
        for(int index=0; index<size-1; index++){
            if((operatorCheck(str[index]) && operatorCheck(str[index+1])) ){
                printf( "Invalid expression\n");
                return -1;
            }
        }

        
        if (!digitCheck(str[index]) || index == size - 1) {
            if (operator == '+') stack[++top] = num;
            else if (operator == '-') stack[++top] = -num;
            else if (operator == '*') stack[top] *= num;
            else if (operator == '/') {
                if (num == 0) {
                    printf("Division by zero Error.\n");
                    return -1;
                }
                stack[top] /= num;
            }
            operator = str[index];
            num = 0;
        }
    }

    int result = 0;
    for (int index = 0; index <= top; index++) result += stack[i];
    printf("Result: %d\n", result);
}

int main() {
    char mathExpression[MAX];
    printf("Enter a mathematical expression: ");
    scanf("%[^\n]%*c", math_exp);
    solve(mathExpression, strlen(mathExpression));
    return 0;
}
