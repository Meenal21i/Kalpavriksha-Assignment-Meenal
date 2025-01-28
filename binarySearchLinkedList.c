#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
} Node;
Node* takeInput(Node* head){
    int input;
    Node* prev=head;
    while(scanf("%d", &input) == 1){
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data=input;
        temp->next=NULL;
        if(head==NULL) head=temp;
        else prev->next=temp;
        prev=temp;
        char ch=getchar();
        if(ch == '\n') break;
    }
    return head;
}
Node* middleNode(Node* start, Node* last){
    if(start==NULL) return NULL;
    Node*slow=start, *fast=start->next;
    while(fast != last){
        fast=fast->next;
        if(fast != last){
            slow=slow->next;
            fast=fast->next;
        }
    }
    return slow;
}
Node* binarySearch(Node* head, int key){
    Node* start=head, *last=NULL;
do{
    Node* mid = middleNode(start, last);
    if(mid == NULL) return NULL;
    if(mid->data == key) return mid;
    else if(mid->data < key) start = mid->next;
    else last = mid;

} while(last == NULL || last != start);

return NULL;
}
int main(){
    Node* head=NULL;
    head = takeInput(head);
    int key;
    scanf("%d", &key);
    if(binarySearch(head, key)!=NULL){
        printf("key %d present", key);
    }
    else{printf("Not present");}
    return 0;
}