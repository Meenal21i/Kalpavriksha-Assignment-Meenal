#include<stdio.h>
#include<stdlib.h>

#define maxSize 100

typedef struct Stack {
    int arr[maxSize];
    int currSize;
} Stack;

typedef struct Queue {
    Stack input, output;
    int curSize;
} Queue;

int isEmptyStack(Stack *s){
    if(s->currSize == 0) return 1;
    else return 0;
}

void push(Stack *s, int value){
    if(s->currSize >= maxSize)
    {
        printf("Stack overflow.\n");
    }
    else
    {
        s->arr[s->currSize] = value;
        s->currSize++ ;
    }
}

void pop(Stack *s){
    if(s->currSize <= 0)
    {
        printf("Stack underflow.\n");
    }
    else
    {
        s->currSize--;
    }
}

int top(Stack *s){
    if(s->currSize <= 0) return -1;
    return s->arr[s->currSize -1];
}

void enqueue(Queue *q, int value) {
    push(&q->input, value);
    q->curSize++;
}

void dequeue(Queue *q){
    if (isEmptyStack(&q->input) && isEmptyStack(&q->output))
    {
        printf("Queue is empty.\n");
        return;
    }

    if (isEmptyStack(&q->output))
    {
        while (!isEmptyStack(&q->input))
        {
            push(&q->output, top(&q->input));
            pop(&q->input);
        }
    }

    int value = top(&q->output);
    pop(&q->output);
    q->curSize--;

    printf("Removed value: %d\n", value);
}

int peek(Queue *q) {
    if(!isEmptyStack(&q->output))
    {
        return top(&q->output);
    }

    if (isEmptyStack(&q->input))
    {
        printf("Queue is empty.\n");
        return -1;
    }

    while (!isEmptyStack(&q->input))
    {
        push(&q->output, top(&q->input));
        pop(&q->input);
    }

    return top(&q->output);
}

int sizeOfQueue(Queue *q) {
    return q->curSize;
}

void isEmpty(Queue *q) {
    if(sizeOfQueue(q) == 0) 
    {
        printf("Queue is empty.\n");
    }
    else{
        printf("Queue is not empty.\n");
    }
}

int main(){
    Queue queue;
    queue.input.currSize = 0;
    queue.output.currSize = 0;
    queue.curSize = 0;

    int choice, value;

    while(1){
        printf("\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Size\n");
        printf("5. Empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                scanf("%d", &value);
                enqueue(&queue, value);
                break;

            case 2:
                dequeue(&queue);
                break;
            
            case 3:
                if(peek(&queue) != -1) printf("Top element: %d\n", peek(&queue));
                break;
            
            case 4:
                printf("Size of queue: %d\n", sizeOfQueue(&queue));
                break;

            case 5:
                isEmpty(&queue);
                break;

            case 6:
                printf("Exiting Program.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}