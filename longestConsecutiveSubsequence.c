//longest consecutive subsequence
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void longestConsecutiveSubseq (int *a, int n) {
    int hash[1000] = {0};
    for(int i=0; i<n; i++) {
        hash[a[i]]++;
    }
    int result=1;
    int cnt=0;
    for(int i=0; i<1000; i++) {
        
        if(hash[i] != 0) cnt++;
        else cnt=0;
        result = (result > cnt) ? result : cnt;
    }

    printf("%d", result);
}
int main() {
    int *arr = (int*)malloc(100 * sizeof(int));
    int n=0;
    while(scanf("%d", &arr[n]) == 1) {
        n++;
        char ch = getchar();
        if(ch == '\n' ) break;
    }

    longestConsecutiveSubseq(arr, n);
}