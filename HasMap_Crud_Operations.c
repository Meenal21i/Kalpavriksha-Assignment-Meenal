#include <stdio.h>
#include <stdlib.h>
#define tableSize 10

typedef struct Node
{
    int key, value;
    struct Node *next;
} Node;

Node *hashTable[tableSize];

int hashFunction(int key)
{
    return key % tableSize;
}

void insertPut(int key, int val)
{
    int index = hashFunction(key);
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = val;
    newNode->next = NULL;

    if (hashTable[index] == NULL)
    {
        hashTable[index] = newNode;
    }
    else
    {
        Node *temp = hashTable[index];
        while (temp->next != NULL)
        {
            if (temp->key == key)
            {
                temp->value = val;
                free(newNode);
                return;
            }
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int searchGet(int key)
{
    int index = hashFunction(key);
    Node *temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->key == key)
            return temp->value;
        temp = temp->next;
    }
    return -1;
}

void deleteRemove(int key)
{
    int index = hashFunction(key);
    Node *ptr = hashTable[index];
    Node *prev = NULL;
    while (ptr != NULL)
    {
        if (ptr->key == key)
        {
            if (prev == NULL)
                hashTable[index] = ptr->next;
            else
                prev->next = ptr->next;
            printf("Key %d deleted\n", key);
            free(ptr);
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    printf("Key %d not found.\n", key);
}

void displayHash()
{

    printf("Hash Table:\n");
    for (int i = 0; i < tableSize; i++)
    {
        Node *ptr = hashTable[i];
        int flag = 0;
        while (ptr != NULL)
        {
            if (flag == 0)
            {
                printf("Index %d: ", i);
                flag = 1;
            }
            printf("(%d, %d)", ptr->key, ptr->value);
            ptr = ptr->next;
            if (ptr != NULL)
                printf("->");
            if (ptr == NULL)
                printf("\n");
        }
    }
}

int main()
{
    int choice, key, val;
    while (1)
    {
        printf("\nEnter your choice:\n");
        printf("1.Insert(Put)\n2.Search(Get)\n3.Delete(Remove)\n4.Display\n5.Exit\n");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter key: ");
            scanf("%d", &key);
            printf("Enter value: ");
            scanf("%d", &val);
            insertPut(key, val);
            break;

        case 2:
            printf("Enter key: ");
            scanf("%d", &key);
            val = searchGet(key);
            if (val != -1)
                printf("Value:%d\n", val);
            else
                printf("Key %d not found", key);
            break;

        case 3:
            printf("Enter key:");
            scanf("%d", &key);
            deleteRemove(key);
            break;

        case 4:
            displayHash();
            break;

        case 5:
            printf("Exiting Program\n");
            return 0;

        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}