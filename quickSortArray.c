#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
int partitioning(int *arr,int low,int high){
    int pivot = arr[high];
    int pivotIndex=low;
    for(int i=low; i<high; i++){
        if(arr[i] <= pivot) {
            swap(&arr[i], &arr[pivotIndex]);
            pivotIndex++;
        }
    }
    swap(&arr[pivotIndex], &arr[high]);
    return pivotIndex;

}

void quickSort(int *arr, int low, int high){
    if(low >= high) return;
    int pivotIndex = partitioning(arr, low, high);
    quickSort(arr, low, pivotIndex-1);
    quickSort(arr, pivotIndex+1, high);

}
int takeInput(int *arr){
    int input, index=0;
    while(scanf("%d", &input) == 1){
        arr[index++] = input;
        char ch=getchar();
        if(ch=='\n') break;
    }
    return index;
}

int main(){
    int *arr=(int*)malloc(sizeof(int)*100);
    int size=takeInput(arr);
    quickSort(arr, 0, size-1);
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}