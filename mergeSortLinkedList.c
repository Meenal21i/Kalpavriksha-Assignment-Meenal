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
Node* middleNode(Node* head){
    Node*slow=head, *fast=head->next;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* mid = slow->next;
    slow->next = NULL;
    return mid;
}
Node* merge(Node* l1, Node* l2){
    if(!l1) return l2;
    if(!l2) return l1;
    Node*result;
    if(l1->data < l2->data){
        result = l1;
        result->next = merge(result->next, l2);
    }
    else{
        result = l2;
        result->next = merge(l1, result->next);
    }
    return result;
}
Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* mid = middleNode(head);
    Node* leftList = mergeSort(head);
    Node* rightList = mergeSort(mid);
    return merge(leftList, rightList);
}
int main(){
    Node* head= NULL;
    int counter=0;
    head = takeInput(head);
    head = mergeSort(head);
    while(head){
        printf("%d ", head->data);
        head= head->next;
    }
    return 0;
}