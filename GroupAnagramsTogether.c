#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MaxSize 100

bool isAnagram(char *str1, char *str2) {
    
    int len1=0, len2=0;
    while(str1[len1] != '\0') len1++;
    while(str2[len2] != '\0') len2++;
    
    if(len1 != len2) return false;
    
    int *hash = (int *)calloc(26, sizeof(int));
    for(int index=0; str1[index] != '\0'; index++) {
        hash[str1[index] - 'a']++;
        hash[str2[index] - 'a']--;
    }
    for(int index=0; index<26; index++) {
        if(hash[index] != 0 ) return false;
    }
    free(hash);
    return true;
}


void groupAnagrams(char **arr, int size)
{
    bool *grouped = (bool *)calloc(size, sizeof(bool));
    bool firstGroup = true;

    printf("[");
    for (int word = 0; word < size; word++)
    {
        if (!grouped[word])
        {
            if (!firstGroup)
            {
                printf(", ");
            }
            printf("[\"%s\"", arr[word]);
            grouped[word] = true;
            for (int secondWord = word + 1; secondWord < size; secondWord++)
            {
                if (isAnagram(arr[word], arr[secondWord]))
                {
                    printf(", \"%s\"", arr[secondWord]);
                    grouped[secondWord] = true;
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

    char **string = (char **)malloc(size * sizeof(char *));
    for (int words = 0; words < size; words++)
    {
        string[words] = (char *)malloc(MaxSize * sizeof(char));
    }
    for (int words = 0; words < size; words++)
    {
        scanf("%s", string[words]);
    }

    groupAnagrams(string, size);

    for (int words = 0; words < size; words++)
    {
        free(string[words]); 
    }
    free(string);

    return 0;
}
