#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int takeInput(int *arr){
    int input, index=0;
    while(scanf("%d", &input) == 1){
        arr[index++] = input;
        char ch = getchar();
        if(ch == '\n') break;
    }
    return index;
}
void swap(int* num1, int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void selectionSortArray (int *arr, int size) {
    int minIdx=0;
    for(int i=0; i<size-1; i++){
        minIdx = i;
        for(int j=i+1; j<size; j++){
            if(arr[minIdx] > arr[j]){
                minIdx = j;
            }
        }swap(&arr[minIdx], &arr[i]);
    }
}

int main(){
    int *arr = (int*)malloc(sizeof(int)*100);
    int size = takeInput(arr);
    selectionSortArray(arr, size);
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}