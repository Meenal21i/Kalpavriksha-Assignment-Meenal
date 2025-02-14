/*
 Problem Statement:
Write a function to check if a given substring exists within a string. Return the starting index of
the substring if it exists; otherwise, return -1.
Sample Input and Output:
1. Input: string = "hello world", substring = "world"
Output: 6
2. Input: string = "programming", substring = "gram"
Output: 3
3. Input: string = "abcdef", substring = "xyz"
Output: -1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int checkSubstring(char *str, char *substr)
{
    int strIndex = 0, substrIndex = 0;
    while (str[strIndex] != '\0' && substr[substrIndex] != '\0')
    {
        if (str[strIndex] == substr[substrIndex])
        {
            strIndex++;
            substrIndex++;
            if (substr[substrIndex] == '\0')
            {
                return strIndex - substrIndex;
            }
        }
        else
        {
            substrIndex = 0;
            strIndex = strIndex - substrIndex + 1;
        }
    }
    return -1;
}
int main()
{
    char *string = (char *)malloc(100 * sizeof(char));
    scanf("%[^\n]", string);
    getchar();
    char *substring = (char *)malloc(100 * sizeof(char));
    scanf("%[^\n]", substring);

    int index = checkSubstring(string, substring);
    printf("%d", index);

    free(string);
    free(substring);
    return 0;
}
