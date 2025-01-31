#include <stdio.h>
#include <stdlib.h>

#define maxSize 100

typedef struct Stack
{
    int arr[maxSize];
    int currSize;
} Stack;

typedef struct Queue
{
    Stack stack;
    int front;
} Queue;

int isEmptyStack(Stack *s)
{
    if (s->currSize == 0)
        return 1;
    else
        return 0;
}

int top(Stack *s)
{
    if (s->currSize <= 0)
        return -1;
    return s->arr[s->currSize - 1];
}

void push(Stack *s, int value)
{
    if (s->currSize >= maxSize)
    {
        printf("Queue overflow.\n");
    }
    else
    {
        s->arr[s->currSize] = value;
        s->currSize++;
    }
}

int pop(Stack *s)
{
    if (s->currSize == 1)
    {
        s->currSize--;
        return s->arr[0];
    }

    int temp = top(s);
    s->currSize--;

    int frontElement = pop(s);

    push(s, temp); 
    return frontElement;
}

void enqueue(Queue *q, int value)
{
    if(q->stack.currSize == 0) 
    {
        q->front = value;
    }
    push(&q->stack, value);
}

void dequeue(Queue *q)
{
    int poppedElement = pop(&q->stack);
    printf("Removed Element: %d\n", poppedElement);
    if(!isEmptyStack(&q->stack)) 
    {
        q->front = q->stack.arr[0];
    }
}

int peek(Queue *q)
{
    if (isEmptyStack(&q->stack))
    {
        printf("Queue is empty.\n");
        return -1;
    }

    return q->front;
}

int sizeOfQueue(Queue *q)
{
    return q->stack.currSize;
}

void isEmpty(Queue *q)
{
    if (sizeOfQueue(q) == 0)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue is not empty.\n");
    }
}

int main()
{
    Queue queue;
    queue.stack.currSize = 0;
    queue.front = 0;

    int choice, value;

    while (1)
    {
        printf("\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Size\n");
        printf("5. Empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d", &value);
            enqueue(&queue, value);
            break;

        case 2:
            dequeue(&queue);
            break;

        case 3:
            if (peek(&queue) != -1)
                printf("Top element: %d\n", peek(&queue));
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