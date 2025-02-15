#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
typedef struct stack {
    int top;
    int *arrQuant;
    char **arrItem;
} stack;

void add(stack *st, char *item, int quant) {
    if(st->top >= MAX_SIZE-1) return;

    for(int i=0; i<=st->top; i++) {
        if(strcmp(st->arrItem[i], item) == 0){
            st->arrQuant[i] += quant;
            return;
        }
    }

    st->top++;
    st->arrItem[st->top] = (char*)malloc(strlen(item)+1);
    strcpy(st->arrItem[st->top], item);
    st->arrQuant[st->top] = quant;
}

void update(stack *st, char *item, int quant) {
    for(int i=0; i<=st->top; i++) {
        if(strcmp(st->arrItem[i], item) == 0){
            st->arrQuant[i] = quant;
            return;
        }
    }
}

void query(stack *st, char *item) {
    for(int i=0; i<=st->top; i++) {
        if(strcmp(st->arrItem[i], item) == 0){
            printf("%d\n", st->arrQuant[i]);
            return;
        }
    }
    printf("Not found\n");

}
int main() {
    stack *st = (stack*)malloc(sizeof(stack));

    st->arrItem = (char**)malloc(MAX_SIZE * sizeof(char*));

    st->arrQuant = (int*)malloc(MAX_SIZE * sizeof(int));

    st->top=-1;

    int quant;
    char choice[10];
    char item[MAX_SIZE];

    int numOfCmd;
    printf("Enter total number of commands: ");
    scanf("%d", &numOfCmd);
    while(numOfCmd--) {
        printf("\n1.ADD\n2.UPDATE\n3.QUERY\n");
        scanf("%s", choice);

        switch(choice[0]) {
            case 'A':
                scanf("%s %d", item, &quant);
                add(st, item, quant);
                break;
            case 'U':
                scanf("%s %d", item, &quant);
                update(st, item, quant);
                break;
            case 'Q':
                scanf("%s", item);
                query(st, item);
                break;
        }
    }
    return 0;
}