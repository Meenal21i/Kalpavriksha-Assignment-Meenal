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
char * search_char(const char * str, char ch) {
    for(int i=0; i<strlen(str); i++) {
        if(str[i] == ch) {return (char*)str;}
    }
    return NULL;
}
int operatorCheck(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){return 1;}
    return 0;
}


int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) { 
                printf("Error: Division by zero.\n"); 
                return -1;
            }
            return a / b;
        default: return 0;
    }
}

int solve(char str[], int n) {
    for(int i=n-1, j=0; i>=0, j<n; i--, j++) {
        if(spaceCheck(str[i]) || spaceCheck(str[j])){ continue;}
        else if(operatorCheck(str[i]) || operatorCheck(str[j])) {
            printf("Invalid Expression\n");
            return -1;
        }
        break;
    }
    
    
    int stack[MAX], top = -1, num = 0;
    char op = '+';

    for (int i = 0; i < n; i++) {
        if (spaceCheck(str[i])) continue; 

        if (digitCheck(str[i])) {
            num = num * 10 + (str[i] - '0');
        } 

        if (str[i] == '-' && (i == 0 || search_char("+-*/", str[i - 1]))) {
            op = '-'; 
            continue; 
        }
        
        if (!digitCheck(str[i]) && !spaceCheck(str[i]) && !search_char("+-*/", str[i])) {
            printf("Invalid expression\n");
            return -1;
        }
        
        for(int i=0; i<n-1; i++){
            if((operatorCheck(str[i]) && operatorCheck(str[i+1])) ){
                printf( "Invalid expression\n");
                return -1;
            }
        }

        
        if (!digitCheck(str[i]) || i == n - 1) {
            if (op == '+') stack[++top] = num;
            else if (op == '-') stack[++top] = -num;
            else if (op == '*') stack[top] *= num;
            else if (op == '/') {
                if (num == 0) {
                    printf("Division by zero Error.\n");
                    return -1;
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
    char math_exp[MAX];
    printf("Enter a mathematical expression: ");
    scanf("%[^\n]%*c", math_exp);
    solve(math_exp, strlen(math_exp));
    return 0;
}
