// Smallest Window in a String Containing All Characters of Another String
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void smallestWindowStringMatch(char *s1, char *s2) {
    
    int minL=strlen(s1);
    int start=0, end=minL-1, i=0;
    while(s1[i] != '\0') {
        int idx=0;
        int hash[26] = {0};
        while(s2[idx] != '\0') {
            hash[s2[idx]-'a']++;
            idx++;
        }
        int j=i;
        while(s1[j]!='\0') {
            if( hash[s1[j] - 'a'] > 0)
                hash[s1[j] - 'a']--;
            int cnt=0;
            for(int idx=0; idx<26; idx++) {
                if(hash[idx] == 0) {
                    cnt++;
                }
            }
            if(cnt==26) {
                // int st=i, en=j-1;
                int len = j-i+1;
                if(len < minL){
                    start = i;
                    end = j;
                    minL = len;
                }
            } 
            j++;
        }
        i++;
    }
    for(int i=start; i<=end; i++) {
        printf("%c", s1[i]);
    }
}
int main() {
    char *str1 = (char*)malloc(100 * sizeof(char));
    scanf("%s", str1);
    
    getchar();

    char *str2 = (char*)malloc(100 * sizeof(char));
    scanf("%s", str2);

    smallestWindowStringMatch(str1, str2);
    // printf("%s, %s\n", str1, str2);
}