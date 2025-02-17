#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void distinctEleInSubarrofSizeK(int *arr, int n, int k) {
    if (k<1 || k>n) {
        printf("Invalid value of K\n");
        return;
    }
    int result[n];
    int idx=0;
    for(int i=0; i<n-k+1; i++) {
        int j=i;
        int cnt=0;
        int hash[100] = {0};
        while(j-i+1 <= k) {
            
            if(hash[arr[j]] == 0)
                cnt++;

            hash[arr[j]]++;
            j++;
        }
        result[idx++] = cnt;
    }
    for(int i=0; i<idx; i++) {
        printf("%d ", result[i]);
    }
}
int main() {
    int *arr = (int*)malloc(100 * sizeof(int));
    int n=0;
    while(scanf("%d", &arr[n]) == 1) {
        n++;
        char ch = getchar();
        if(ch == '\n') break;
    }
    int k;
    scanf("%d", &k);

    distinctEleInSubarrofSizeK (arr, n, k);
}