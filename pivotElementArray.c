#include<stdio.h>
#include<stdlib.h>

int takeInput(int *arr){
    int input, index=0;
    while(scanf("%d", &input) == 1){
        arr[index++] = input;
        char ch = getchar();
        if(ch == '\n') break;
    }
    return index;
}
int pivotInArray(int *arr, int size){
    int start=0, end=size-1;
    while(start < end){
        int mid = start + (end-start)/2;
        if(arr[mid] > arr[start]) start = mid;
        else end = mid;
    }
    return start;
}
int main(){
    int *arr = (int*)malloc(100*sizeof(int));
    int size = takeInput(arr);
    int pivotIndex = pivotInArray(arr, size);
    printf("Pivot element Index: %d\n", pivotIndex);
    printf("Pivot element: %d\n", arr[pivotIndex]);
    printf("Number of rotations: %d\n", pivotIndex+1);
    return 0;
}
