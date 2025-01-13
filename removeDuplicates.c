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
void removeDuplicates(char *string)
{
    int *hash = (int *)calloc(26, sizeof(int));
    int character = 0;
    while (string[character] != '\0')
    {
        hash[string[character] - 'a']++;
        character++;
    }
    character = 0;
    while (string[character] != '\0')
    {
        if (hash[string[character] - 'a'] != 0)
        {
            printf("%c", string[character]);
            hash[string[character] - 'a'] = 0;
        }
        character++;
    }
    free(hash);
}
int main()
{
    char *string = (char *)malloc(100 * sizeof(char));
    scanf("%[^\n]", string);

    removeDuplicates(string);

    return 0;
}
