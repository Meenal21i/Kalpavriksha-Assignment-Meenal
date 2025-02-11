#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int charInStr(char ch, char*str)
{
    for(int i=0; i<strlen(str); i++)
    {
        if(ch == str[i]) return 1;
    }
    return 0;
}
int maxLen(char** string, int n)
{
    int len=0, maxl=0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int found = 0;

            for(int k=0; k<strlen(string[i]); k++)
            {
                if(charInStr(string[i][k], string[j])==1){
                    found = 1;
                    break;
                }
                
            }
            if(found==0){
                len = (strlen(string[i]) * strlen(string[j]));
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