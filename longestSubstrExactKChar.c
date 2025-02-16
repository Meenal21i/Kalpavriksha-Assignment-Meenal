#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int longestSubstrExactKChar(char *str, int n, int k) {
    int hash[26] = {0};
    int i=0, cnt=0, len=0, maxLen=0;
    while(str[i]!='\0' && cnt<=k) {
        for(int j=i; j<=n; j++)
        {
            if(hash[str[j]-'a'] == 0){
            cnt++;
            }
            hash[str[j]-'a']++;
            if(cnt > k) break;
            len++;
        }
        maxLen = (len>maxLen) ? len : maxLen;
        cnt=0;
        len=0;
        for(int i=0; i<26; i++) {
            hash[i] = 0;
        }
        i++;
    }

    return maxLen;
}
int main() {
    char *string = (char*)malloc(100*sizeof(char));
    scanf("%s", string);
    int len=0;
    while(string[len]!='\0') len++;

    getchar();

    int k;
    scanf("%d", &k);

    printf("%d", longestSubstrExactKChar(string, len,k));
    return 0;
}