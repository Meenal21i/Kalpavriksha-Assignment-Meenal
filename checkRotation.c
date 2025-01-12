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
// APPROACH 1:
bool checkRotation(char *str1, char *str2)
{
    int n = strlen(str2);
    char *str3 = (char *)malloc(100 * sizeof(char));
    int d = 0;
    while (d < n)
    {
        int s3index = 0;

        for (int i = d; i < n; i++)
        {
            str3[s3index++] = str2[i];
        }
        for (int i = 0; i < d; i++)
        {
            str3[s3index++] = str2[i];
        }
        str3[s3index] = '\0';
        if (strcmp(str3, str1) == 0)
        {
            free(str3);
            return true;
        }

        d++;
    }
    free(str3);
    return false;
}

int main()
{
    // char string[100];
    // scanf("%[^\n]", string);

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


// APPROACH 2:
// void stringCopy(char dest[], const char source[])
// {
//     int i = 0;
//     while (1)
//     {
//         dest[i] = source[i];
//         if (dest[i] == '\0')
//         {
//             break;
//         }
//         i++;
//     }
// }
// char *stringConcat(char *dest, const char *src)
// {
//     size_t i, j;
//     for (i = 0; dest[i] != '\0'; i++)
//         ;
//     for (j = 0; src[j] != '\0'; j++)
//         dest[i + j] = src[j];
//     dest[i + j] = '\0';
//     return dest;
// }
// int checkSubstring(char *str, char *substr)
// {
//     int i = 0, j = 0;
//     while (str[i] != '\0' && substr[j] != '\0')
//     {
//         if (str[i] == substr[j])
//         {
//             i++;
//             j++;
//             if (substr[j] == '\0')
//             {
//                 return i - j;
//             }
//         }
//         else
//         {
//             j = 0;
//             i = i - j + 1;
//         }
//     }
//     return -1;
// }
// bool checkRotation(char *str1, char *str2)
// {

//     int len2 = strlen(str2);
//     char *str3 = (char *)malloc(2 * len2 * sizeof(char));

//     stringCopy(str3, str2);
//     stringConcat(str3, str2);

//     if (checkSubstring(str3, str1) != -1)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
// int main()
// {
//     // char string[100];
//     // scanf("%[^\n]", string);

//     char *string1 = (char *)malloc(100 * sizeof(char));
//     scanf("%[^\n]", string1);
//     getchar();
//     char *string2 = (char *)malloc(100 * sizeof(char));
//     scanf("%[^\n]", string2);

//     if (strlen(string1) != strlen(string2))
//         printf("false");
//     return 0;

//     if (checkRotation(string1, string2))
//     {
//         printf("true");
//     }
//     else
//     {
//         printf("false");
//     }

//     free(string1);
//     free(string2);
//     return 0;
// }