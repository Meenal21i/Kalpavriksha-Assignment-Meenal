/*
 Problem Statement: 
Write a program to remove all instances of a specific character from a string. 
Sample Input and Output: 
1. Input: string = "banana", char = 'a' 
Output: "bnn" 
2. Input: string = "hello world", char = 'l' 
Output: "heo word" 
3. Input: string = "abcdef", char = 'x' 
Output: "abcdef"
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
void removeAllOccurenceofChar( char* string, char charToRemove){
    int len=0;
    while(string[len] != '\0') len++;
    
    int strIndex=0, newIndex=0;
    char *newstring = (char*)malloc((len+1) * sizeof(char));
    while(string[strIndex] != '\0') {
        if(string[strIndex] != charToRemove){
            newstring[newIndex++] = string[strIndex];
        }
        strIndex++;
    }
    newstring[newIndex] = '\0';
    printf("%s", newstring); 
    free(newstring);
}

int main(){
    char * string = (char*)malloc(100 * sizeof(char));
    scanf("%[^\n]", string);
    getchar();
    char charToRemove;
    scanf("%c", &charToRemove);
    
    removeAllOccurenceofChar(string, charToRemove);
    
    free(string);
    return 0;
}