#include<stdio.h>
#include<stdlib.h>
#define maxSize 100

typedef struct Queue{
    int queue[maxSize];
    int front;
    int rear;
    int currSize;
} Queue;

int isEmpty(Queue *q){
    if(q->currSize == 0) return 1;
    else return 0;  
}

void enqueue(Queue *q, int data){
    if(q->currSize >= maxSize) {
        printf("Queue is full.\n");
        return;
    }
    else if(q->currSize == 0){
        q->front=0;
        q->rear=0;
    }
    else{
        q->rear = (q->rear+1) % maxSize;
    }
    q->queue[q->rear] = data;
    q->currSize++;
    return;
}

void dequeue(Queue *q){
    if(q->currSize == 0){
        printf("Queue is Empty.\n");
        return;     
    }
    int poppedElement = q->queue[q->front];
    if(q->currSize == 1){
        q->front=-1;
        q->rear=-1;
    }
    else{
        q->front = (q->front+1) % maxSize;
    }
    q->currSize--;
    printf("Removed item: %d\n", poppedElement);

}
int peek(Queue *q){
    if(q->currSize == 0){
        printf("Queue is Empty.\n");   
    }
    else{
        printf("Front element: %d\n", q->queue[q->front]);
    }
}
int sizOfQueue(Queue *q){
    return q->currSize;
}

void displayQueue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return;
    }
    while(q->front != q->rear){
        printf("%d ", q->queue[q->front]);
        q->front++;
    }
}
int main(){
    Queue q;
    q.currSize = 0;
    q.front = -1;
    q.rear = -1;
    
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
                enqueue(&q, data);
                break;
            
            case 2:
                dequeue(&q);
                break;

            case 3: 
                peek(&q);
                break;
            
            case 4:
                isEmpty(&q) ? printf("Stack is empty\n") : printf("Stack is not empty\n");
                break;
            
            case 5:
                printf("Size of Queue: %d\n", sizOfQueue(&q));
                break;

            case 6:
                displayQueue(&q);
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