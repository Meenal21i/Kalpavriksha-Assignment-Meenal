// Smart Home Lighting System (Stack)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack {
    int top;
    int *status;
    char **room;
} stack;

void turnON(stack *st, char *rm) {
    
    for (int i=0; i<=st->top; i++) {
        if(strcmp(st->room[i], rm) == 0){ //update if exists
            st->status[i] = 1;
            return;
        }
    }

    st->top++;
    strcpy(st->room[st->top], rm);
    st->status[st->top] = 1;
    
}

void turnOFF(stack *st, char *rm) {
    for (int i=0; i<=st->top; i++) {
        if(strcmp(st->room[i], rm) == 0){ //update if exists
            st->status[i] = 0;
            return;
        }
    }
}

void getStatus(stack *st, char *rm) {
    for (int i=0; i<=st->top; i++) {
        if(strcmp(st->room[i], rm) == 0){ //update if exists
            if(st->status[i] == 1) {
                printf("ON\n");
            }
            else printf("OFF\n");
            return;
        }
    }
    printf("OFF\n");
    return;
}
int main() {
    stack *st = (stack*)malloc(sizeof(stack));
    st->top = -1;
    st->room = (char**)malloc(100 * sizeof(char*)) ;
    for(int i=0; i<100; i++) {
        st->room[i] = (char*)malloc(100 * sizeof(char)) ;
    }
    st->status = (int*)malloc(100 * sizeof(int)) ;

    char choice[10];
    char rm[10];

    int numOfCmd;
    printf("Enter total number of commands: ");
    scanf("%d", &numOfCmd);

    while(numOfCmd--) {
        printf("\n1.TURN_ON\n2.TURN_OFF\n3.TOP\n");
        scanf("%s", choice);
        if(strcmp(choice, "TURN_ON")==0) {
            scanf("%s", rm);
            turnON(st, rm);
        }
        else if(strcmp(choice, "TURN_OFF")==0) {
            scanf("%s", rm);
            turnOFF(st, rm);
        }
        else if(strcmp(choice, "STATUS")==0) {
            scanf("%s", rm);
            getStatus(st, rm);
        }
        else {
            printf("Invalid input\n");
        }
    }
    return 0;

    return 0;
}