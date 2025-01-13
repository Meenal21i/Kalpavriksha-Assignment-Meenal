/*
 Problem Statement: 
Write a program to find the longest word in a given sentence. Assume words are separated by 
spaces. 
Sample Input and Output: 
1. Input: "The quick brown fox jumps" 
Output: "jumps" 
2. Input: "Hello world" 
Output: "Hello" 
3. Input: "a abc abcd" 
Output: "abcd"
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
char* longestWord(char *str){
    int i=0, maxCount = 0, longestWordIndex=0;
    char *longestWord = (char *)malloc(100 * sizeof(char));
    while( str[i] != '\0'){
        int count=0;
        while((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
            count++;
            i++;
        }
        if(maxCount < count){
            maxCount = count;
            longestWordIndex = i-maxCount;
        } 
        while(str[i] == ' '){
            i++;
        }
    }
    for(int i=0; i<maxCount; i++) {
        longestWord[i] = str[longestWordIndex+i];
    }
    longestWord[maxCount] = '\0';
    // free(longestWord);
    return longestWord;
}
int main()
{
    char *string = (char *)malloc(100 * sizeof(char));
    scanf("%[^\n]", string);
    
    char* longestWordFinal = longestWord(string);
    printf("%s", longestWordFinal);
    
    free(longestWordFinal);
    free(string);
    return 0;
}