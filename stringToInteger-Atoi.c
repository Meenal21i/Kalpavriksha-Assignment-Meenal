/*
 Problem Statement: 
Write a program to implement the atoi() function, which converts a string to an integer. The 
function should handle negative numbers and return 0 for invalid input. 
Sample Input and Output: 
1. Input: "1234" 
Output: 1234 
2. Input: "-567" 
Output: -567 
3. Input: "abc123" 
Output: 0 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int isCharFoundDgit(char chFound)
{
    return (chFound >= '0' && chFound <= '9');
}
int stringToInt(char *string)
{
    int element = 0, num = 0, sign = 1;
    while (string[element] != '\0')
    {
        if (string[element] == '-' && isCharFoundDgit(string[element + 1]))
        {
            sign = -1;
            element++;
        }
        if (!isCharFoundDgit(string[element]))
            return 0;

        num = num * 10 + (string[element] - '0');
        element++;
    }
    return sign * num;
}

int main()
{
    char *string = (char *)malloc(100 * sizeof(char));
    scanf("%[^\n]", string);

    int num = stringToInt(string);
    printf("%d", num);

    free(string);
    return 0;
}
