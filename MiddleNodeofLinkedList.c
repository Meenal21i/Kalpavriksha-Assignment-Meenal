
#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node* next;
};

int is_digit(int num){
    return num>=-9 && num<=9;
}
struct Node* insertAtEnd(struct Node *head, int data) {
    struct Node* newNodePtr = (struct Node *)malloc(sizeof(struct Node));
    struct Node* p=head;
    while(p->next != NULL){
        p=p->next;
    }
    newNodePtr->next=NULL;
    newNodePtr->data=data;
    p->next=newNodePtr;
    return head;
}

//find the middle node and return it, if they are two, return the second middle node
int middleNode(struct Node* head, int len){
    struct Node* ptr=head;
    int index=0;
    if(len%2==0){
        index = len/2 +1;
    }
    else{
        index=len/2 +1;
    }
    int i=0;
        while(i != index){
            ptr=ptr->next;
            i++;
        }
        return ptr->data;
}

void printLL(struct Node * ptr){
    while( ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
int lengthofLL(struct Node* head){
    
        struct Node*ptr=head;
        int cnt=0;
        while(ptr != NULL) {
            cnt++;
            ptr=ptr->next;
        }
        return cnt;
    
}

int main(){
    struct Node  *head;
     int x;
    int* array = (int *)malloc(sizeof(int)*100);

    for(int i=0;i<100;i++){
        scanf("%d", &array[i]);
        
        if(array[i] != -1) {
            insertAtEnd(head, array[i]);
        }
        if( array[i]==-1) {break;}
        else if(!is_digit(array[i])) {printf("Invalid input"); return 0;}
        
    }
    
    
    int len = lengthofLL(head);
    int d = middleNode(head,len -1);
    printf("%d", d);
    return 0;
}


