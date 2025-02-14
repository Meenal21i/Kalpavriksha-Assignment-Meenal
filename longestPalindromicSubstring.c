/*
Longest Palindromic Substring 
Problem Statement: 
Write a program to find the longest palindromic substring in a given string. A palindrome reads 
the same forward and backward. If there are multiple longest palindromic substrings of the 
same length, return any one of them. 
Sample Input and Output: 
1. Input: "babad" 
Output: "bab" or "aba" 
Explanation: Both "bab" and "aba" are palindromic substrings of length 3. 
2. Input: "cbbd" 
Output: "bb" 
Explanation: The longest palindromic substring is "bb" with length 2. 
3. Input: "a" 
Output: "a" 
Explanation: A single character is always a palindrome. 
4. Input: "forgeeksskeegfor" 
Output: "geeksskeeg" 
Explanation: The longest palindromic substring is "geeksskeeg" with length 10.
*/

#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isPallindrome(char *string, int low, int high){
    while (low < high) {
        if (string[low] != string[high])
            return false;
        low++;
        high--;
    }
    return true;
}

char* longestPalindromicSubstr(char *string, int size) {
    char *substr = (char*)malloc((size+1) * sizeof(char));
    
    int start=0, maxLen=1;
    for(int startIndex=0; startIndex < size; startIndex++) {
        for(int endIndex=startIndex; endIndex < size; endIndex++){
            if (isPallindrome(string, startIndex, endIndex)){
                    int len = endIndex - startIndex +1;
                    if (len > maxLen) {
                    maxLen = len;
                    start = startIndex;
                }
            }
        }
    }
    int index=0;
    for(int idx=start; idx < start+maxLen; idx++){
        substr[index++] = string[idx];
    }
    substr[index] = '\0';
    // free(substr);
    return substr;
}

int main()
{
    char *string = (char*)malloc(100 * sizeof(char));
    scanf("%[^\n]", string);
    int len=0;
    while(string[len] != '\0') len++;
    
    char* result = longestPalindromicSubstr(string, len);
    printf("%s\n", result);

    free(result); 
    free(string);

    return 0;
}