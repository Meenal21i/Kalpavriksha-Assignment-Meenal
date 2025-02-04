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
int firstRepeatingElement(int *arr, int n)
{   
    int *hash = (int*)calloc(n, sizeof(int));
    for(int i=0; i<n; i++)
    {
        hash[arr[i]]++;
    }

    for(int i=0; i<n;i++)
    {
        if(hash[arr[i]]>1)
            return arr[i];
    }
    return arr[0];
}


int main(){
    int *arr = (int*)malloc(100*sizeof(int));
    int size = takeInput(arr);

    printf("%d", firstRepeatingElement(arr, size));

    return 0;
}