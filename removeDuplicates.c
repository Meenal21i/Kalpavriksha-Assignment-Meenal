/*
 Problem Statement:
Write a program to remove all duplicate characters from a given string. The resulting string
should retain the order of first appearance of characters and should not contain any duplicate
letters.
Sample Input and Output:
1. Input: "programming"
Output: "progamin"
2. Input: "banana"
Output: "ban"
3. Input: "abacabad"
Output: "abcd"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void removeDuplicates(char *str)
{
    int hash[26] = {0};
    int i = 0;
    while (str[i] != '\0')
    {
        hash[str[i] - 'a']++;
        i++;
    }
    i = 0;
    while (str[i] != '\0')
    {
        if (hash[str[i] - 'a'] != 0)
        {
            printf("%c", str[i]);
            hash[str[i] - 'a'] = 0;
        }
        i++;
    }
}
int main()
{
    // char string[100];
    // scanf("%[^\n]", string);

    char *string = (char *)malloc(100 * sizeof(char));
    scanf("%[^\n]", string);

    removeDuplicates(string);

    return 0;
}