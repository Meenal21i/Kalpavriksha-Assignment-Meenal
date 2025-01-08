// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int firstCharVowel(char firstChar) {
    return (firstChar=='a' || firstChar=='i' || firstChar=='e' || firstChar=='o' || firstChar=='u' || firstChar=='A' || firstChar=='I' || firstChar=='E' || firstChar=='O' || firstChar=='U');
}

int main() {
    int rowSize, colSize;
    printf("Enter number of rows: ");
    scanf("%d", &rowSize);
    if (rowSize < 1 || rowSize > 10)
    {
        printf("Constraint: 1 < Row length < 10\n");
        return 1;
    }
    printf("Enter number of columns: ");
    scanf("%d", &colSize);
    if (colSize < 1 || colSize > 101)
    {
        printf("Constraint: 1 < Column length < 101\n");
        return 1;
    }

    char ***matrix = (char ***)malloc(rowSize * sizeof(char **));
    for(int row=0; row<rowSize; row++) {
        matrix[row] = (char **)malloc(colSize * sizeof(char *));
        for(int col=0; col<colSize; col++) {
            matrix[row][col] = (char *)malloc(50 * sizeof(char));
        }
    }
    
    char **longestName = (char **)malloc(rowSize * colSize * sizeof(char *));
    
    // char longestName[100];
    int vowelWordCount = 0, countLongestName=0, currMaxLength=0;
    
    printf("Enter the names:\n");
    for(int row=0; row<rowSize; row++) {
        for(int col=0; col<colSize; col++){
            printf("Name at (%d, %d): ", row,col);
            scanf("%49s", matrix[row][col]);
            if(firstCharVowel(matrix[row][col][0])){
                vowelWordCount++;
            }
            if(strlen(matrix[row][col]) > currMaxLength) {
                currMaxLength = strlen(matrix[row][col]);
                countLongestName=0;
                longestName[countLongestName] = matrix[row][col];
            }
            if(strlen(matrix[row][col]) == currMaxLength){
                longestName[countLongestName] = matrix[row][col];
                countLongestName++;
            }
        }
    }
    
    printf("The 2D array of names is:\n");
    for(int row=0; row<rowSize; row++) {
        for(int col=0; col<colSize; col++){
            printf("%s  ", matrix[row][col]);
        }
        printf("\n");
    }
    
    printf("Number of names starting with a vowel: %d\n", vowelWordCount);
    printf("The longest name: ");
    for(int index=0; index<countLongestName; index++) {
        printf("%s ", longestName[index]);
    }
    
    for(int row=0; row<rowSize; row++) {
        for(int col=0; col<colSize; col++){
            free(matrix[row][col]);
        }
        free(matrix[row]);
    }
    free(matrix);
    return 0;
}
