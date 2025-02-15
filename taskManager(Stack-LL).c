//Task manager command system (stack-LL)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10

typedef struct Node {
    char *data;
    struct Node *next;
}Node;

Node* top = NULL;

void add(char* data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    
    if(temp == NULL){
        // printf("Stack overflow");
        return;
    }
    temp->data = (char*)malloc(MAX_SIZE * sizeof(char));
    strcpy(temp->data , data);
    Node*prev = top;
    if(top==NULL){
        top =temp;
    }
    else{
        while(prev->next){
            prev=prev->next;
        }
        prev->next=temp;
    }
    prev=temp;
    temp->next=NULL;
}

void complete(char* data) {
	if(top==NULL){
// 		printf("stack underflow\n");
        return;
	}
	
	Node* temp=top;
	while(strcmp(temp->next->data, data)!=0){
	    temp=temp->next;
	}
	temp->next = temp->next->next;
}
void pending(){
    Node* temp=top;
    while(temp) {
        printf("%s ", temp->data);
        temp=temp->next;
    }
}
int main() 
{
    char choice[10];
    char task[10];
    
    int numOfCmd;
    printf("Enter total num pf commands: ");
    scanf("%d", &numOfCmd);
    
    while(numOfCmd--) {
        printf("\n1.ADD\n2.COMPLETE\n3.PENDING\n");
        scanf("%s", choice);
        
        switch(choice[0]) {
            case 'A':
                scanf("%s", task);
                add(task);
                break;
            case 'C':
                scanf("%s", task);
                complete(task);
                break;
            case 'P':
                pending();
                break;
        }
    }
    return 0; 
}
