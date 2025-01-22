#include <stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createList(Node* head){
    int input;
    Node* prev=head;
    while(scanf("%d",&input)==1){
        Node* temp=(Node*)malloc(sizeof(Node));
        temp->data=input;
        temp->next=NULL;
        if(head==NULL){
            head=temp;
        }
        else{
            prev->next=temp;
        }
        prev=temp;
        char ch=getchar();
        if(ch=='\n') break;
    }
    return head;
    
}
int main()
{
    Node* head=NULL;
    head = createList(head);

    int k;
    scanf("%d", &k);
    
    Node* temp=head;
    int len=0;
    while(temp){
        len++;
        temp=temp->next;
    }
    
    if(k > len){printf("Invalid input for k\n"); return 0;}
    int index=len-k+1;
    temp=head;
    Node*prev=NULL;
    for(int i=1; i<index; i++) {
        prev=temp;
        temp=temp->next;
    }
    if(prev==NULL){
        head=head->next;
    }
    else{
        prev->next=temp->next;
    }
    //printing the list
    while(head){
        printf("%d ",head->data );
        head=head->next;
    }
    return 0;
}