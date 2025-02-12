#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int charInStr(char ch, char* word)
{
    for(int letter=0; letter<strlen(word); letter++)
    {
        if(ch == word[letter]) return 1;
    }
    return 0;
}
int maxLen(char** string, int numOfWords)
{
    int len=0, maxl=0;
    for(int word1=0; word1<numOfWords-1; word1++)
    {
        for(int word2=word1+1; word2<numOfWords; word2++)
        {
            int found = 0;

            for(int letter=0; letter<strlen(string[word1]); letter++)
            {
                if(charInStr(string[word1][letter], string[word2])==1){
                    found = 1;
                    break;
                }
                
            }
            if(found==0){
                len = (strlen(string[word1]) * strlen(string[word2]));
                if(maxl < len) maxl = len;
            }
        }
    }
    return maxl;
}
int main()
{
    int n;
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    // getchar();
    char **string = (char **)malloc(n * sizeof(char *));

    for (int words = 0; words < n; words++)
    {
        string[words] = (char *)malloc(10 * sizeof(char));
        scanf("%s", string[words]);
    }
  
    printf("%d", maxLen(string, n));
    return 0;
}
