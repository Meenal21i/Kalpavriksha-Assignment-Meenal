// Bookmark pages management system
#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
    int top;
    int *arr;
} stack;

void push(stack *s, int val, int *hash) {
    if(s->top <= 100) {
        s->top++;
        s->arr[s->top] = val;
    }
    hash[val]++;
}
void pop(stack *s, int *hash) {
    int val=s->arr[s->top];
    if(s->top > 1) {
        s->top--;
    }
    hash[val]=0;
}
void display(int *hash) {
    for(int i=1; i<=1000; i++) {
        if(hash[i]>0){
            printf("%d ", i);
        }
    }
}
int main(){
    stack *s = (stack*)malloc(101 * sizeof(stack));
    s->top = -1;
    s->arr = (int*)malloc(1000 * sizeof(int));  

    int hash[1001] = {0};

    char choice[10];
    int page;
    while(1) {
        printf("\n1.BOOKMARK\n2.DELETE\n3.LIST\n");
        printf("Enter choice: ");
        scanf("%s", choice);
        switch(choice[0]) {
            case 'B': 
                scanf("%d", &page);
                push(s, page, hash);
                break;
            case 'D':
                pop(s, hash);
                break;
            case 'L':
                display(hash);
                break;
        }
    }
    
    return 0;
}