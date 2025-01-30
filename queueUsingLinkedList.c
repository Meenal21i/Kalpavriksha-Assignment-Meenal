#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node *front=NULL, *rear=NULL;
int currQueueSize=0;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) return NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int isEmpty(){
    return (front == NULL);
}
void enqueue(int data){
    Node* temp = createNode(data);
    if(front == NULL) {
        front = temp;
        rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
    currQueueSize++ ;
}

void dequeue() {
    if(front == NULL){
        printf("Queue is empty.\n");
    }
    else{
        Node* temp = front;
        front = front->next;
        printf("Removed element is %d.\n", temp->data);
        free(temp);
        currQueueSize-- ;
    }
}

void peek(){
    if(front == NULL){
        printf("Queue is empty.\n");
    }
    else{
        printf("Top element is %d.\n", front->data);
    }
}
int sizeOfQueue(){
    return currQueueSize;
}
void displayQueue(){
    if(front == NULL){
        printf("Queue is empty.\n");
        return;
    }
    Node* ptr = front;
    while(ptr){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int main(){
    int choice;
    while(1){
        printf("1. Add an element to the queue.\n");
        printf("2. Remove the front element from the queue.\n");
        printf("3. Retrieve the front element without removing it.\n");
        printf("4. Check if the queue is empty.\n");
        printf("5. Return the number of elements in the queue.\n");
        printf("6. Display elements of Queue.\n");
        printf("7. Exit.\n");

        scanf("%d", &choice);
        int data;
        switch(choice){
            case 1: 
                scanf("%d", &data);
                enqueue(data);
                break;
            
            case 2:
                dequeue();
                break;

            case 3: 
                peek();
                break;
            
            case 4:
                isEmpty() ? printf("Queue is empty\n") : printf("Queue is not empty\n");
                break;
            
            case 5:
                printf("Size of Queue: %d\n", sizeOfQueue());
                break;

            case 6:
                displayQueue();
                break;

            case 7: 
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Inavlid choice.\n");
                break;
        }
    }
    
    return 0;
}