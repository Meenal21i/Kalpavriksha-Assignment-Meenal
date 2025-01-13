/*
 Problem Statement:
Write a program to compress a string by replacing consecutive occurrences of the same
character with the character followed by the count. If the compressed string is not smaller
than the original, return the original string.
Sample Input and Output:
1. Input: "aaabbc"
Output: "a3b2c1"
2. Input: "abcd"
Output: "abcd"
3. Input: "aabbcc"
Output: "a2b2c2"
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
char *stringCompression(char *str)
{

    int strIndex = 0, index = 0;
    int len = 0;
    while (str[len] != '\0')
        len++;
    char *str2 = (char *)malloc((2 * len + 1) * sizeof(char));
    while (strIndex < len)
    {
        int count = 1;
        while (strIndex + 1 < len && (str[strIndex] == str[strIndex + 1]))
        {
            count++;
            strIndex++;
        }
        str2[index++] = str[strIndex];
        char countStr = count + '0';
        str2[index++] = countStr;
        strIndex++;
    }
    str2[index] = '\0';

    if (strlen(str2) <= strlen(str))
    {
        return str2;
    }
    else
    {
        return str;
    }
}
int main()
{
    char *string = (char *)malloc(100 * sizeof(char));
    scanf("%[^\n]", string);

    char *compressedString = stringCompression(string);
    printf("%s", stringCompression(string));

    free(string);
    return 0;
}