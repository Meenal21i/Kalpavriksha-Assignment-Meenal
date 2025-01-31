#include <stdio.h>
#include <stdlib.h>
#define maxSize 10

typedef struct Queue
{
    int arr[maxSize];
    int front;
    int rear;
    int currSize;
} Queue;

typedef struct Stack
{
    Queue Q;
} Stack;

int isEmptyQueue( Queue *q)
{
    return q->currSize == 0;
}

int isFullQueue( Queue *q)
{
    return q->currSize == maxSize;
}

void enqueue( Queue *q, int value)
{
    if (isFullQueue(q))
    {
        printf("Queue overflow!\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % maxSize;
    q->arr[q->rear] = value;
    q->currSize++;
}

void dequeue( Queue *q)
{
    if (isEmptyQueue(q))
    {
        printf("Queue underflow!\n");
        return;
    }
    q->front = (q->front + 1) % maxSize;
    q->currSize--;
    if (q->currSize == 0)
    {
        q->front = q->rear = -1;
    }
}

int front( Queue *q)
{
    if (isEmptyQueue(q))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->arr[q->front];
}

void push( Stack *stack, int value)
{
    if (isFullQueue(&stack->Q))
    {
        printf("Stack overflow!");
        return;
    }

    enqueue(&stack->Q, value);
    int originalSize = stack->Q.currSize - 1;

    for (int i = 0; i < originalSize; i++)
    {
        int temp = front(&stack->Q);
        dequeue(&stack->Q);
        enqueue(&stack->Q, temp);
    }
}

int peek( Stack *stack)
{
    if (isEmptyQueue(&stack->Q))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return front(&stack->Q);
}

void pop( Stack *stack)
{

    if (isEmptyQueue(&stack->Q))
    {
        printf("Stack underflow!\n");
        return;
    }

    printf("Removed element: %d.\n", peek(stack));
    dequeue(&stack->Q);
}

int sizeOfStack( Stack stack)
{
    return stack.Q.currSize;
}

void isStackEmpty( Stack stack)
{
    if (sizeOfStack(stack) == 0)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack is not empty.\n");
}

int main()
{
    struct Stack stack;
    stack.Q.front = -1;
    stack.Q.rear = -1;
    stack.Q.currSize = 0;

    int choice;
    int value;
    while (1)
    {   printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. check if empty\n");
        printf("5. Size of stack\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d", &value);
            push(&stack, value);
            break;

        case 2:
            pop(&stack);
            break;

        case 3:
            printf("Top element of stack: %d.\n", peek(&stack));
            break;

        case 4:
            isStackEmpty(stack);
            break;

        case 5:
            printf("Size of the stack: %d.\n", sizeOfStack(stack));
            break;

        case 6:
            printf("Exiting Program.");
            return 0;

        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    return 0;
}