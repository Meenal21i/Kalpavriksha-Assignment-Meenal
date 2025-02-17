#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int allPairSumDivisibleByK(int *arr, int n, int k) {
    if(n % 2 != 0) return 0;
    for(int i=0; i<n-1; i++) {
        if (arr[i] == -1) continue;
        int flag=0;
        for(int j=i+1; j<n; j++) {
            
            if (arr[j] == -1) continue;
            int sum = arr[i] + arr[j];
            if(sum%k == 0){
                flag=1;
                arr[i]=-1;
                arr[j]=-1;
                if(i+1 < n) break;
            } 
        }
        if (flag == 0)return 0;
    }
    int i=0;
    while(i<n){
        if(arr[i] == -1)
            i++;
    }
    if(i==n) return 1;
    return 0;
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

    if (allPairSumDivisibleByK(arr, n, k))
        printf("True");
    else 
        printf("False");

    return 0;
}