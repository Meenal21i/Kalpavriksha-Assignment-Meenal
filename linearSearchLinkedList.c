#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
} Node;
Node* takeInput(Node* head, int *count){
    int input;
    Node* prev=head;
    while(scanf("%d", &input) == 1){
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data=input;
        temp->next=NULL;
        if(head==NULL) head=temp;
        else prev->next=temp;
        prev=temp;
        (*count)++;
        char ch=getchar();
        if(ch == '\n') break;
    }
    return head;
}
int linearSearch(Node* head, int count, int key){
    if(head==NULL) return -1;
    int idx=0;
    Node* temp=head;
    while(idx < count){
        if(temp->data == key){return idx;}
        else{temp=temp->next;
        idx++;}
    }
    return -1;
}
int main(){
    Node* head=NULL;
    int count=0;
    head = takeInput(head, &count);
    int key;
    scanf("%d", &key);
    int idx = linearSearch(head, count, key);
    printf("%d", idx);
    return 0;
}