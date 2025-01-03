#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Write a program to find the longest word in a given sentence.
// Input : Hi Helo World, I am here.Output : 5
int longestWord(char sentence[])
{
    int index = 0, wordLength = 0, longestLength = 0;
    ;

    for (int index = 0; sentence[index] != '\0'; index++)
    {

        if (sentence[index] != ' ' || sentence[index] != '\n')
        {
            if ((sentence[index] >= 65) && (sentence[index] <= 90) || (sentence[index] >= 97) && (sentence[index] <= 122))
            {
                wordLength++;
            }
        }
        else
        {
            if (wordLength > longestLength)
            {
                longestLength = wordLength;
                printf("%d", longestLength);
            }
            wordLength = 0;
        }
        // index++;
    }
    if (wordLength > longestLength)
    {
        longestLength = wordLength;
    }
    return longestLength;
}

int main()
{
    char sentence[100];
    int length;
    scanf("%[\n]s", sentence);
    printf("%d", longestWord(sentence));
    return 0;
}