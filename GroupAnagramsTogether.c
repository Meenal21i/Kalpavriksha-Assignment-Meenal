#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MaxSize 100


bool isAnagram(char s1[], char s2[])
{
    int hash[26] = {0};

    for (int i = 0; s1[i] != '\0'; i++)
    {
        hash[s1[i] - 'a']++;
    }
    for (int i = 0; s2[i] != '\0'; i++)
    {
        hash[s2[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] != 0)
        {
            return false;
        }
    }
    return true; 
}


void groupAnagrams(char **arr, int size)
{
    bool *grouped = (bool *)calloc(size, sizeof(bool));
    bool firstGroup = true;

    printf("[");
    for (int i = 0; i < size; i++)
    {
        if (!grouped[i])
        {
            if (!firstGroup)
            {
                printf(", ");
            }
            printf("[\"%s\"", arr[i]);
            grouped[i] = true;
            for (int j = i + 1; j < size; j++)
            {
                if (isAnagram(arr[i], arr[j]))
                {
                    printf(", \"%s\"", arr[j]);
                    grouped[j] = true;
                }
            }
            printf("]");
            firstGroup = false; 
        }
    }
    printf("]\n");

    free(grouped); 
}

int main()
{
    int size;
    scanf("%d", &size);

    char **str = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++)
    {
        str[i] = (char *)malloc(MaxSize * sizeof(char));
    }
    for (int i = 0; i < size; i++)
    {
        scanf("%s", str[i]);
    }

    groupAnagrams(str, size);

    for (int i = 0; i < size; i++)
    {
        free(str[i]); 
    }
    free(str);

    return 0;
}
