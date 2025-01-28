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
void insertionSortArray (int *arr, int size) {
    int temp, i, j;
    for( i=1; i<size; i++){
        temp=arr[i];
        for( j=i-1; j>=0; j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}

int main(){
    int *arr = (int*)malloc(sizeof(int)*100);
    int size = takeInput(arr);
    insertionSortArray(arr, size);
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}