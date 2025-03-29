#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int range(int *arr, int maxfreqEle, int n, int *st, int *ls) {
    int flag=0;
    for(int idx=0; idx<n; idx++) {
        if(arr[idx] == maxfreqEle) {
            *ls = idx;
            if(flag==0) {
                *st = idx;
                flag=1;
            } 
        }
    }
}
void subarrMaxFreqEle(int *arr, int n) {
    int freq[1000] = {0};
    //freq of each element of given array
    for(int idx=0; idx<n; idx++) {
        freq[arr[idx]]++ ;
    }
    //highest freq from freq array
    int maxArr[n], max=-100, indx=0;
    for(int idx=0; idx<1000; idx++) {
        if(freq[idx] > max) {
           max = freq[idx]; //maxfreq only
        }   
    }
    for(int idx=0; idx<1000; idx++) {
        if(freq[idx] == max) {
            maxArr[indx++] = idx; //array of multiple maxFreq ele (if any)
        }
    }

    //track start & end index of max freq element
    int start=0, end=n, st=0, ls=0;
    for(int ele=0; ele<indx; ele++) {
        range(arr, maxArr[ele], n, &st, &ls);
        if(ls-st+1 <= end-start+1)
        {   start=st;
            end=ls;
        }
    }

    printf("[%d, %d]", start, end);
}
int main() {
    int *arr = (int*)malloc(100 * sizeof(int)) ;
    int n=0;
    while(scanf("%d", &arr[n]) == 1) {
        n++;
        char ch = getchar();
        if(ch == '\n') break;
    }

    subarrMaxFreqEle(arr, n);
}