#include <stdio.h>
#include <stdbool.h>
bool isAnagram(char s1[], char s2[])
{
    int hash1[26] = {0};
    int hash2[26] = {0};

    for (int i = 0; s1[i] != '\0'; i++)
    {
        hash1[s1[i] - 'a']++;
    }
    for (int i = 0; s2[i] != '\0'; i++)
    {
        hash2[s2[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (hash1[i] != hash2[i])
            return false;
    }
    return true;
}
int main()
{
    char s1[10], s2[10];
    scanf("%s", s1);
    scanf("%s", s2);
    if (isAnagram(s1, s2))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    return 0;
}