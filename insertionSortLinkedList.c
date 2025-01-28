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
        // (*counter)++;
        prev = temp;
        char ch = getchar();
        if(ch == '\n') break;

    }
    return head;
}
Node* insertionSort(Node* head){
    Node* dummy = (Node*)malloc(sizeof(Node));
    dummy->data=-1;
    dummy->next = NULL;
    Node* curr=head;
    while(curr){
        Node*temp = curr->next, *prev=dummy, *nxt = dummy->next;

        while(nxt){
            if(nxt->data > curr->data) break;
            prev = nxt;
            nxt = nxt->next;
        }
        curr->next = nxt;
        prev->next = curr;
        curr=temp;
    }
    return dummy->next;
}
int main(){
    Node* head= NULL;
    int counter=0;
    head = takeInput(head);
    head = insertionSort(head);
    while(head){
        printf("%d ", head->data);
        head= head->next;
    }
    return 0;
}