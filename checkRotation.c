/*
 Problem Statement:
Write a program to check if one string is a rotation of another string. For example, "abcd" and
"dabc" are rotations of each other.
Sample Input and Output:
1. Input: string1 = "abcd", string2 = "dabc"
Output: true
2. Input: string1 = "rotation", string2 = "ationrot"
Output: true
3. Input: string1 = "hello", string2 = "world"
Output: false
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int stringCompare(char *string1, char*string2){
     int i = 0, flag = 0;    
    while (flag == 0) {
        if (string1[i] != string2[i]) {
            flag = 1;
        } 
        if (string1[i] == '\0')
        {
            break;
        }
        i++;
    }
    return flag;
}
bool checkRotation(char *str1, char *str2)
{
    int len2 = strlen(str2);
    char *str3 = (char *)malloc(100 * sizeof(char));
    int pivot = 0;
    while (pivot < len2)
    {
        int s3index = 0;

        for (int s2index = pivot; s2index < len2; s2index++)
        {
            str3[s3index++] = str2[s2index];
        }
        for (int s2index = 0; s2index < pivot; s2index++)
        {
            str3[s3index++] = str2[s2index];
        }
        str3[s3index] = '\0';
        if (stringCompare(str3, str1) == 0)
        {
            free(str3);
            return true;
        }

        pivot++;
    }
    free(str3);
    return false;
}

int main()
{
    char *string1 = (char *)malloc(100 * sizeof(char));
    scanf("%[^\n]", string1);
    getchar();
    char *string2 = (char *)malloc(100 * sizeof(char));
    scanf("%[^\n]", string2);

    if (strlen(string1) != strlen(string2))
    {
        printf("false");
        return 0;
    }
    if (checkRotation(string1, string2))
    {
        printf("true");
    }
    else
    {
        printf("false");
    }

    free(string1);
    free(string2);
    return 0;
}
