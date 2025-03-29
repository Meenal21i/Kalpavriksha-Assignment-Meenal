#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestSubarrWithEqual01 (int *arr, int n) {

    if(n==1) return 0;

    int hash[2] = {0};
    for(int idx=0; idx<n; idx++) {
        hash[arr[idx]]++;
    }

    if(hash[0] == hash[1]) return n;

    int res = (hash[0] < hash[1]) ? hash[0] : hash[1];
    return res*2;
}

int main() {
    int *arr = (int *)malloc(100 * sizeof(int));
    int n=0;
    while(scanf("%d", &arr[n]) == 1) {
        n++;
        char ch = getchar();
        if (ch=='\n') break;
    }

    printf("%d", longestSubarrWithEqual01(arr, n));
}