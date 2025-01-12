/*
 Problem Statement:
Write a program to count the number of words in a given string. Assume words are separated
by one or more spaces, and the string may contain leading or trailing spaces.
Sample Input and Output:
1. Input: "Hello World"
Output: 2
2. Input: " The quick brown fox"
Output: 4
3. Input: "This is a test "
Output: 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int countWords(char *s)
{
    int i = 0, wordCount = 0;
    while (s[i] != '\0')
    {
        int flag = 0;
        while ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            flag = 1;
            i++;
        }
        if (flag == 1)
            wordCount++;

        while (s[i] != '\0' && !((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
        {
            i++;
        }
    }
    return wordCount;
}
int main()
{
    // char string[100];
    // scanf("%[^\n]", string);

    char *string = (char *)malloc(100 * sizeof(char));
    scanf("%[^\n]", string);

    int result = countWords(string);
    printf("%d", result);

    free(string);

    return 0;
}