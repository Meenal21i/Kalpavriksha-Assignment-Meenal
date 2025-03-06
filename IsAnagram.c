/*
 Problem Statement: 
Write a program to check if two strings are anagrams of each other. Two strings are anagrams 
if they contain the same characters in the same frequency. 
Sample Input and Output: 
1. Input: "listen", "silent" 
Output: true 
2. Input: "triangle", "integral" 
Output: true 
3. Input: "apple", "pale" 
Output: false
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isAnagram(char *str1, char *str2) {
    int *hash = (int *)calloc(26, sizeof(int));
    for(int index=0; str1[index] != '\0'; index++) {
        hash[str1[index] - 'a']++;
        hash[str2[index] - 'a']--;
    }
    for(int index=0; index<26; index++) {
        if(hash[index] != 0 ) return false;
    }
    return true;
}
int main()
{
    char *string1 = (char *)malloc(100 * sizeof(char));
    scanf("%[^\n]", string1);
    getchar();
    char *string2 = (char *)malloc(100 * sizeof(char));
    scanf("%[^\n]", string2);
    
    if(isAnagram(string1, string2)){
        printf("true");
    }
    else{
        printf("false");
    }

    return 0;
}
