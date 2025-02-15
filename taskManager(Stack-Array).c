//Task manager command system (stack-Array)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct stack {
    int top;
    char **arr;
}stack;

void add(stack *st, char* task) {
    st->top++;
    st->arr[st->top] = (char*)malloc(MAX_SIZE * sizeof(char));
    strcpy(st->arr[st->top], task);
}
void complete(stack *st, char *task) {
    for(int i=0;i<=st->top;i++) {
        if(strcmp(st->arr[i], task)==0){
            strcpy(st->arr[i], "Completed");
            return;
        }
    }
}
void pending(stack *st) {
    int flag=0;
    for(int i=0; i<=st->top; i++) {
        if(strcmp(st->arr[i], "Completed")==0)
            {continue;}
        else
        {
            flag=1;
            printf("%s\n", st->arr[i]);
        }
    }
    if(flag==0)
        printf("All tasks completed\n");
}
int main() {
    stack *st = (stack*)malloc(sizeof(stack));
    st->top=-1;
    st->arr = (char**)malloc(MAX_SIZE * sizeof(char*));
    
    int numOfCmd;
    printf("Enter total num of commands: ");
    scanf("%d", &numOfCmd);

    char choice[10];
    char task[MAX_SIZE-1];
    while(numOfCmd--) {
        printf("\n1.ADD\n2.COMPLETE\n3.PENDING\n");
        scanf("%s", choice);
        switch(choice[0]) {
            case 'A':
                scanf("%s", task);
                add(st,task);
                break;
            case 'C':
                scanf("%s", task);
                complete(st,task);
                break;
            case 'P':
                pending(st);
                break;
        }
    }
    return 0;
}
