#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* top=NULL;

int isEmpty(){
    if(top == NULL) return 1;
    return 0;
}
int isFull(){
    Node* ptr = (Node*)malloc(sizeof(Node));
    if(ptr==NULL) 
        return 1;
    free(ptr);
    return 0;
}
void push(int value){ // inserting node at index 0 i.e. start of linked list
    
    if(isFull()) {
        printf("Stack Overflow\n");
    }
    else{
        Node* ptr = (Node*)malloc(sizeof(Node));
        if(ptr==NULL){
            printf("Stack overflow.\n");
        }
        ptr->data=value;
        ptr->next=top;
        top=ptr;
    }
    return;
}
void pop(){
    if(isEmpty())
        printf("Stack Underflow\n");
    else{
        Node* ptr = top;
        top = (top)->next;
        // int val = ptr->data;
        free(ptr);
    }
    return;
}

int peek(){
    if(isEmpty()){
        printf("Stack is empty\n");
        return -1;
    } 
    
    return top->data;

}
void display(){
    if(isEmpty()){
        printf("Stack is empty\n");
        return;
    } 
    Node* ptr=top;
    while(ptr){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int sizeOfStack(){
    int size=0;
    Node* ptr=top;
    while(ptr){
        size++;
        ptr=ptr->next;
    }
    return size;
}
int main(){
    
    int choice, value;
    
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. check if empty\n");
        printf("5. Size of stack\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1: // enter value to push
                scanf("%d", &value);
                push(value);
                break;
                
            case 2: 
                pop();
                break;
                
            case 3:
                printf("%d\n", peek());
                break;
                
            case 4:
                if(isEmpty()) printf("Stack is empty\n");
                else printf("Stack is not empty\n");
                break;
                
            case 5:
                printf("Size of Stack: %d\n", sizeOfStack());
                break;
                
            case 6:
                display();
                break;
                
            case 7:
                printf("Exiting menu\n");
                return 0;
                
            default:
                printf("Invalid choice");
                
        }
    }
    return 0;
}