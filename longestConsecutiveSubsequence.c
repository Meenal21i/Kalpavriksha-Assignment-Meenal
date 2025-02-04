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

int longestConsecutive(int *arr, int n) {

    insertionSortArray(arr, n);

    int result = 1, count = 1;
    for (int i = 1; i < n; i++) {

        if (arr[i] == arr[i - 1]) 
            continue;
        if (arr[i] == arr[i - 1] + 1) {
            count++;
        } 
        else {
            count = 1;
        }
        if (count > result) {
            result = count;
        }
        
    }
    return result;
}

int main(){
    int *arr = (int*)malloc(sizeof(int));
    int size = takeInput(arr);

    printf("%d", longestConsecutive(arr, size));
    // printf("%d", size);
    return 0;
}