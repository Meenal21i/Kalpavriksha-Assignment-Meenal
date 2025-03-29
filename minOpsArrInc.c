#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void minOps(int *arr, int n) {
    int op=0;
    for(int i=1; i<n; i++) {
        if(arr[i] <= arr[i-1]) {
            int diff = arr[i-1]-arr[i]+1;
            op += diff;
            arr[i] += diff;
        }
    }
    printf("%d", op);
}

int main() {
    int *arr = (int *)malloc(100 * sizeof(int));
    int n=0;
    while(scanf("%d", &arr[n]) == 1){
        n++;
        char ch = getchar();
        if (ch=='\n') break;
    }

    minOps(arr, n);
}