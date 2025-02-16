#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void subarrWithKDistinctInt(int *a, int n, int k) {
    int subarr=0;
    for(int i=0; i<=n-k; i++) {
        int cnt=0;
        int hash[1000] = {0};
        for(int j=i; j<n; j++) {
            if(hash[a[j]] == 0){
                cnt++;
            }
            hash[a[j]]++;

            if(cnt == k) {
                subarr++;
            }
        }
    }
    printf("%d", subarr);
}
int main() {
//static input
    // int n;
    // printf("Enter n: ");
    // scanf("%d", &n);
    // int arr[n];
    // for(int i=0; i<n; i++) {
    //     scanf("%d", &arr[i]);
    // }

//dynamic input
    int *arr = (int*)malloc(sizeof(int) * 100);
    int n=0;
    while(scanf("%d", &arr[n]) == 1) {
        n++;
        char ch = getchar();
        if(ch == '\n') break;
    }

    int k;
    scanf("%d", &k);

    subarrWithKDistinctInt(arr, n, k);

    return 0;
}