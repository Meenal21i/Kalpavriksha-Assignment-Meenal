#include<stdio.h>
#include<stdlib.h>
int takeInput(int*arr){
    int input, index=0;
    while(scanf("%d", &input )== 1){
        arr[index++] = input;
        char ch = getchar();
        if(ch == '\n') break;
    }
    return index;
}
int binarySearch(int *arr, int size, int key){
    int start=0, end=size-1;
    while(start<=end){
    int mid = start + (end-start)/2;
    if (arr[mid] == key) return mid;
    if (arr[mid] >= arr[start]) {
            if (key >= arr[start] && key < arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        else {
            if (key > arr[mid] && key <= arr[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1; 
}
int main(){
    int *arr = (int*)malloc(100*sizeof(int));
    int size = takeInput(arr);
    int key;
    scanf("%d", &key);
    int elementIdx = binarySearch(arr,size, key);
    if(elementIdx != -1) printf("true");
    else printf("false");
    return 0;
}