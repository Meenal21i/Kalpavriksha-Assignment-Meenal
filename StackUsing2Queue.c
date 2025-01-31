#include <stdio.h>
#define maxSize 100

typedef struct Queue
{
    int arr[maxSize];
    int front;
    int rear;
} Queue;

typedef struct Stack
{
    struct Queue Q1, Q2;
    int cursize;
} Stack;

int isEmptyQueue(Queue *q)
{
    if (q->front == -1)
    {
        return 1;
    }
    return 0;
}

void enqueue( Queue *q, int value)
{
    if (q->rear == maxSize - 1)
    {
        printf("Queue overflow!\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = value;
}

void dequeue( Queue *q)
{
    if (isEmptyQueue(q))
    {
        printf("Queue underflow!\n");
    }
    int data = q->arr[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front++;
    }
    printf("The removed value is %d.\n", data);
}

int front( Queue *q)
{
    return q->arr[q->front];
}

void push( Stack *stack, int value)
{
    stack->cursize++;
    enqueue(&stack->Q2, value);
    while (!isEmptyQueue(&stack->Q1))
    {
        enqueue(&stack->Q2, front(&stack->Q1));
        dequeue(&stack->Q1);
    }

    struct Queue temp = stack->Q1;
    stack->Q1 = stack->Q2;
    stack->Q2 = temp;
}

void pop( Stack *stack)
{

    if (isEmptyQueue(&stack->Q1))
    {
        printf("Stack underflow!\n");
        return;
    }
    stack->cursize--;
    dequeue(&stack->Q1);
}

int peek( Stack *stack)
{
    if (isEmptyQueue(&stack->Q1))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return front(&stack->Q1);
}

int sizeOfStack( Stack stack)
{
    return stack.cursize;
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
    stack.Q1.front = -1;
    stack.Q1.rear = -1;
    stack.Q2.front = -1;
    stack.Q2.rear = -1;
    stack.cursize = 0;

    int choice;
    int value;
    while (1)
    {
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