#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct Node{
    int data;
    struct Node* next;
} Node;
Node* takeInput(Node* head){
    int input;
    Node* prev=head;
    while(scanf("%d", &input) == 1){
        Node*temp = (Node*)malloc(sizeof(Node));
        temp->data = input;
        temp->next = NULL;
        if(head == NULL){
            head=temp;
        }
        else{
            prev->next = temp;
        }
        prev = temp;
        char ch = getchar();
        if(ch == '\n') break;

    }
    return head;
}
void swap(int* num1, int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
Node* selectionSort(Node* head){
    if(head==NULL) return head;
    Node* curr=head;
    while(curr){
        Node* temp = curr, *minNode = temp;
        while(temp){
            if(temp->data < minNode->data)
                minNode = temp;
            temp = temp->next;
        }
        swap(&(curr->data), &(minNode->data));
        curr=curr->next;
    }
    return head;
}
int main(){
    Node* head= NULL;
    int counter=0;
    head = takeInput(head);
    head = selectionSort(head);
    while(head){
        printf("%d ", head->data);
        head= head->next;
    }
    return 0;
}