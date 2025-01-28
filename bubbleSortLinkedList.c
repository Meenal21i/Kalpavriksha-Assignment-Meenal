#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
typedef struct Node{
    int data;
    struct Node* next;
} Node;
Node *takeInput(Node *head, int *counter)
{
    int input;
    Node *prev = head;
    while (scanf("%d", &input) == 1)
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->data = input;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            prev->next = temp;
        }

        prev = temp;
        (*counter)++;

        char ch = getchar();
        if (ch == '\n')
            break;
    }
    return head;
}
Node* bubbleSort(Node* head, int *counter){
    Node*curr=head;
    int index=0;
    bool swapped = false;
    while(index < *counter) {
        Node* temp=head, *prev=head;
        swapped = false;
        while(temp->next){
            Node* nexxt = temp->next;
            if(temp->data > nexxt->data){
                swapped = true;
                temp->next = nexxt->next;
                nexxt->next = temp;
                if(temp == head){
                    prev = nexxt;
                    head = prev;
                }
                else{
                    prev->next = nexxt;
                    prev = nexxt;
                }
                continue;
            }
            prev = temp;
            temp = temp->next;
        }
        if(swapped == false) break;
        index++;
    }
    return head;
}
int main()
{
    Node* head=NULL;
    int counter=0;
    head = takeInput(head, &counter);
    head = bubbleSort(head, &counter);
    Node*temp = head;
    while(temp){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    return 0;
}