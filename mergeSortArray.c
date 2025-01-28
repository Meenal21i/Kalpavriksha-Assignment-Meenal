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
void merge(int*arr, int start, int mid, int end){
    int len1 = mid-start+1;
    int len2 = end-mid;
    int leftArr[len1], rightArr[len2];
    for(int i=0; i<len1; i++){
        leftArr[i] = arr[start+i];
    }

    for(int i=0; i<len2; i++){
        rightArr[i] = arr[mid+1+i];
    }
    int i=0, j=0, k=start;
    while (i<len1 && j<len2)
    {
        if(leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        }
        else{
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while(i<len1){
        arr[k++]=leftArr[i++];
    }
    while(j<len2){
        arr[k++]=rightArr[j++];
    }
}
void mergeSortArray(int* arr, int start, int end){
    
    if(start < end){
        int mid = start + (end-start)/2;

        mergeSortArray(arr, start, mid);
        mergeSortArray(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}
int main(){
    int *arr = (int*)malloc(sizeof(int)*100);
    int size = takeInput(arr);
    mergeSortArray(arr, 0, size-1);
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}