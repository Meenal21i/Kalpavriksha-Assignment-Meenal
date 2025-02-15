//Movie Rating System (Stack-Array)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack {
    char **movie;
    int *rating;
    int top;
} stack;

void add(stack *st, char* mov, int rate) {

    for(int i=0; i<=st->top; i++) {
        if(strcmp(st->movie[i], mov) == 0) {
            st->rating[i] = rate; //update if movie exists
            return;
        }
    }
    st->top++;
    strcpy(st->movie[st->top], mov);
    st->rating[st->top] = rate;

    
    
    // for(int i=0; i<top; i++) {
    //     if(st->rating[i] < rate) {
    //         st->top++;
            
    //         for(int j=top-1; j>=i; j--){
    //           strcpy(st->movie[j+1], st->movie[j]);
    //         }
    //         strcpy(st->movie[j], mov);
    //         st->rating = rate;
    //     }
    // }
    
}

void removeMov (stack*st, char *mov) {
//marking movie removed by puting rating 0
    for(int i=0; i<=st->top; i++) {
        if(strcmp(st->movie[i], mov) == 0) {
            st->rating[i] = 0; //update if movie exists
            return;
        }
    }
    
//removing the movie from the stack Array
    // for(int i = 0; i <= st->top; i++) {
    //     if(strcmp(st->movie[i], mov) == 0) {
    //         // Shift elements to the left
    //         for(int j = i; j < st->top; j++) {
    //             strcpy(st->movie[j], st->movie[j + 1]);
    //             st->rating[j] = st->rating[j + 1];
    //         }
    //         st->top--;  // Decrease the top index to remove the last movie
    //         return;
    //     }
    // }
    
}

void top (stack *st) {
    int maxRate=0, maxRateIdx = -1;
    for(int i=0; i<=st->top; i++) {
        if(st->rating[i] > maxRate) {
            maxRate  = st->rating[i];
            maxRateIdx = i;
        }
    }
    if(maxRateIdx == -1){
        printf("No movies rated\n");
        return;
    }
    printf("%s\n", st->movie[maxRateIdx]);
}

int main() {
    stack *st = (stack*)malloc(sizeof(stack));
    st->top = -1;
    st->movie = (char**)malloc(100 * sizeof(char*));
    for(int i=0; i<100; i++) {
        st->movie[i] = (char*)malloc(100 * sizeof(char));
    }
    st->rating = (int*)malloc(100 * sizeof(int));
    
    int numOfCmd;
    printf("Enter total number of commands: ");
    scanf("%d", &numOfCmd);
    
    char choice[10], mov[10];
    int rate;
    
    while(numOfCmd--) {
        printf("\n1.ADD\n2.REMOVE\n3.TOP\n");
        scanf("%s", choice);
        switch(choice[0]) {
            case 'A':
                scanf("%s %d", mov, &rate);
                if(rate>=1 && rate<=10)
                    add(st, mov, rate);
                else
                    printf("Provide rating between 1 and 10\n");
                break;
            case 'R':
                scanf("%s",mov);
                removeMov(st, mov);
                break;
            case 'T':
                top(st);
                break;
        }
    }
    return 0;
}