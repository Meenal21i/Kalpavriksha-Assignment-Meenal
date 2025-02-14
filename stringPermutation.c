/*
String Permutations
Problem Statement:
Generate and print all permutations of a given string. Assume all characters in the string are
unique.
Sample Input and Output:
1. Input: "abc"
Output: ["abc", "acb", "bac", "bca", "cab", "cba"]
Explanation: All possible permutations of the string "abc".
2. Input: "ab"
Output: ["ab", "ba"]
Explanation: Two permutations exist for "ab".
3. Input: "a"
Output: ["a"]
Explanation: A single character string has only one permutation.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char *first, char *second)
{
    char temp = *first;
    *first = *second;
    *second = temp;
}
void printPermutations(char *string, int low, int high)
{
    if (low == high)
    {
        printf("%s\n", string);
    }
    else
    {
        for (int i = low; i <= high; i++)
        {
            swap((string + low), (string + i));
            printPermutations(string, low + 1, high);
            swap((string + low), (string + i));
        }
    }
}
int main()
{
    char *string = (char *)malloc(50 * sizeof(int));
    scanf("%[^\n]", string);

    int len = 0;
    while (string[len] != '\0')
        len++;

    printf("All permuations of string %s are :\n", string);
    printPermutations(string, 0, len - 1);

    free(string);

    return 0;
}