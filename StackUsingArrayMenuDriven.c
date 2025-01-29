#include<stdio.h>
#include<stdlib.h>


typedef struct stack{
    int top;
    int maxSize;
    int *arr;
    
} stack;

int isFull(stack* ptr){
    if(ptr->top >= ptr->maxSize-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(stack *s){
    return (s->top==-1);
}
void push(stack *s, int val){
    if(isFull(s)){
        printf("Stack overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = val;
}

void pop(stack *s){
    if(isEmpty(s)){
        printf("Stack underflow\n");
    }
    else{
        int value = s->arr[s->top];
        s->top--;
    }
}
int peek(stack *s){
    if(isEmpty(s)) {
        printf("stack is empty\n");
        return -1;
    }    
    return s->arr[s->top];
}
void display(stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return;
    }
    for(int i=s->top; i>=0; i--){
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}
int sizeOfStack(stack *s){
    return (s->top + 1);
}
int main(){
    stack *s = (stack*)malloc(sizeof(stack));
    printf("Enter maximum size of stack: ");
    scanf("%d", &(s->maxSize));
    
    s->arr = (int*)malloc(sizeof(int) * s->maxSize);
    s->top=-1;
    
    int choice, value;
    
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. check if empty\n");
        printf("5. Size of stack\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter choice: \n");
        scanf("%d", &choice);
        
        switch(choice){
            case 1: // enter value to push
                scanf("%d", &value);
                push(s, value);
                break;
                
            case 2: 
                pop(s);
                break;
                
            case 3:
                printf("%d\n", peek(s));
                break;
                
            case 4:
                if(isEmpty(s)) printf("Stack is empty");
                else printf("Stack is not empty");
                break;
                
            case 5:
                printf("Size of Stack: %d\n", sizeOfStack(s));
                break;
                
            case 6:
                display(s);
                break;
                
            case 7:
                printf("Exiting menu\n");
                free(s->arr);
                free(s);
                return 0;
                
            default:
                printf("Invalid choice");
                
        }
    }
    return 0;
}