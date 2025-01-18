#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int lengthofList(struct Node *head)
{
    struct Node *ptr = head;
    int cnt = 0;
    while (ptr != NULL)
    {
        cnt++;
        ptr = ptr->next;
    }
    return cnt;
}

void display(){
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insertAtEnd(int value)
{
    struct Node* newNode = createNode(value);
    if(head==NULL){
        head=newNode;
        return;
    }
    struct Node* ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void insertAtBeginning(int value){
    struct Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertAtPosition(int position, int value){
    int len = lengthofList(head);
    if (position > len + 1)
    {
        printf("Invalid position\n");
        return;
    }
    if (position < 1)
    {
        printf("Invalid position\n");
        return;
    }
    if (position == 1)
    {
        insertAtBeginning(value);
        return;
    }
    struct Node *newNode = createNode(value);
    struct Node *ptr = head;
    int i = 0;
    while(i != position-1){
        ptr=ptr->next;
        i++;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void updateAtPosition(int position, int newValue){
    if (position < 1 || position > lengthofList(head)){
        printf("Invalid position\n");
        return;
    }
    struct Node *ptr = head;
    int i=0;
    while (i != position - 1)
    {
        ptr = ptr->next;
        i++;
    }
    ptr->data = newValue;
}

void deleteAtBeginning(){
    if (head == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    struct Node *ptr = head;
    head=head->next;
    free(ptr);
}

void deleteAtEnd(){
    if (head == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    struct Node *ptr = head;
    struct Node *q = head->next;
    while(q->next != NULL){
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = NULL;
    free(q);

}

void deleteAtPosition(int position){
    if (position < 1 || position > lengthofList(head)){
        printf("Invalid position\n");
    }
    if (position == 1)
    {
        deleteAtBeginning();
        return;
    }
    struct Node *ptr = head;
    struct Node *q = head->next;
    int i = 1; // 1-based indexing
    while (i != position - 1)
    {
        ptr = ptr->next;
        q = q->next;
        i++;
    }
    ptr->next = q->next;
    free(q);
}
int main()
{
    int n;
    scanf("%d", &n);

    int operation, x, pos;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            scanf("%d", &x);
            insertAtEnd(x);
            break;
        case 2:
            scanf("%d", &x);
            insertAtBeginning(x);
            break;
        case 3:
            scanf("%d %d", &pos, &x);
            insertAtPosition(pos, x);
            break;
        case 4:
            display();
            break;
        case 5:
            scanf("%d %d", &pos, &x);
            updateAtPosition(pos, x);
            break;
        case 6:
            deleteAtBeginning();
            break;
        case 7:
            deleteAtEnd();
            break;
        case 8:
            scanf("%d", &pos);
            deleteAtPosition(pos);
            break;
        default:
            printf("Invalid operation\n");
            break;
        }
    }

    return 0;
}