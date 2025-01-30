#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[100];
    struct Node* next;
} Node;

Node* takeInput(Node* head, int* counter) {
    char word[100];
    Node *prev = NULL;
    
    while (scanf("%s", word) == 1) { 
        Node* temp = (Node*)malloc(sizeof(Node));
        if (!temp) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        strcpy(temp->data, word);
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            prev->next = temp;
        }

        prev = temp;
        (*counter)++;

        char ch = getchar();
        if (ch == '\n') {
            break; 
        }
        ungetc(ch, stdin); 
    }

    return head;
}

Node* sortStringLinkedList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* word1;
    Node* word2;
    char temp[100];

    for (word1 = head; word1 != NULL; word1 = word1->next) {
        for (word2 = word1->next; word2 != NULL; word2 = word2->next) {
            if (strcmp(word1->data, word2->data) > 0) {
                strcpy(temp, word1->data);
                strcpy(word1->data, word2->data);
                strcpy(word2->data, temp);
            }
        }
    }

    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int counter = 0;

    head = takeInput(head, &counter);
    head = sortStringLinkedList(head);

    printList(head);

    freeList(head);
    return 0;
}