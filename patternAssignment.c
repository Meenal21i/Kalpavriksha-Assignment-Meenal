#include <stdio.h>
#include <stdlib.h>

void printPattern(int n){

    for (int curRow = 1; curRow <= 2 * n - 1; curRow++){
        int totalcols;
        if (curRow <= n){
            totalcols = curRow;
        }
        else{
            totalcols = 2 * n - curRow;
        }

        for (int col = 1; col <= totalcols; col++){
            printf("%d", col);
        }

        int totalSpaces = 2 * (n - totalcols);
        for (int count = 0; count < totalSpaces; count++){
            printf(" ");
        }

        for (int col = totalcols; col >= 1; col--){
            printf("%d", col);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printPattern(n);
    return 0;
}