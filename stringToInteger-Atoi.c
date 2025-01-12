#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int isCharFoundDgit(char chFound)
{
    return (chFound >= '0' && chFound <= '9');
}
int stringToInt(char *str)
{
    int i = 0, num = 0, sign = 1;
    while (str[i] != '\0')
    {
        if (str[i] == '-' && isCharFoundDgit(str[i + 1]))
        {
            sign = -1;
            i++;
        }
        if (!isCharFoundDgit(str[i]))
            return 0;

        num = num * 10 + (str[i] - '0');
        i++;
    }
    return sign * num;
}

int main()
{
    // char string[100];
    // scanf("%[^\n]", string);

    char *string = (char *)malloc(100 * sizeof(char));
    scanf("%[^\n]", string);

    int num = stringToInt(string);
    printf("%d", num);

    free(string);
    return 0;
}