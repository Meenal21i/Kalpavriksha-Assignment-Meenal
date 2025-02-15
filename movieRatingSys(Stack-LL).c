//Movie Rating System (Stack-LL)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10
typedef struct Node{
    int rating;
    char movie[MAX_SIZE];
    struct Node *next;
}Node;

Node *top=NULL;

void add(char *mov, int rate) {
    Node* prev = NULL;
    Node* curr = top;

    Node* temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL) return;

    strcpy(temp->movie, mov);
    temp->rating = rate;
    temp->next = NULL;

    if (top==NULL || curr->rating < rate) { //first place
        temp->next = top;
        top=temp;
        return;
    }
    // inserting the new node in a sorted manner (descending)
    while(curr->rating >= rate && curr!=NULL){
        if(strcmp(curr->movie, mov)==0){ //if movie exists, update the rating
            curr->rating = rate;
            return;
        }
        prev=curr;
        curr=curr->next;
    }
    temp->next = curr; //insert node at correct position
    prev->next = temp;
}

void removeMov(char *mov) {
    if(top==NULL) return;

    Node *prev=NULL, *curr=top;
    while(curr!=NULL && strcmp(curr->movie, mov) != 0){
        prev=curr;
        curr=curr->next;
    }
    if(curr==NULL) return;
    if(prev==NULL) {
        top=curr->next; //first element
    } 
    else {
        prev->next = curr->next;
    } 
    free(curr);
}
void topMov() {
    if(top==NULL){
        printf("No movies rated\n");
        return;
    }
    printf("%s\n", top->movie);
}
int main(){
    char choice[10];
    char mov[10];
    int rate;
    int numOfCmd;
    printf("Enter total number of commands: ");
    scanf("%d", &numOfCmd);

    while(numOfCmd--) {
        printf("\n1.ADD\n2.REMOVE\n3.TOP\n");
        scanf("%s", choice);
        switch(choice[0]) {
            case 'A':
                scanf("%s %d", mov, &rate);
                if(rate>=1 && rate<=10)
                    add(mov, rate);
                else
                    printf("Provide rating between 1 and 10\n");
                break;
            case 'R':
                scanf("%s",mov);
                removeMov(mov);
                break;
            case 'T':
                topMov();
                break;
        }
    }
    return 0;
}