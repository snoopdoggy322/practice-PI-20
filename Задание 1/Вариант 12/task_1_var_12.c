#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool checkConsonant(char a){
    char gl[] = "BbCcDdFfGgHhJjKkLlMmNnPpQqRrSsTtVvWwXxYyZz";
    int i, flag = 0;
    for( i = 0; gl[i] != '\0' &&  flag == 0; i++)
    {
        if(a == gl[i]){
            flag = 1;
        }
    }
    if(flag == 1)
        return true;
    else
        return false;
}

int main(){
    int size_t = 123;
    char inputString[size_t];
    int count = 0;

    printf("Enter a multi line string( press ';' to end input)\n");
    scanf("%[^;]s", inputString);

    printf("Input String = %s. \n", inputString);
    printf("%s", "for loop started... \n");

    char firstStrChar = inputString[0];
    for (int i = 0; i < size_t; i++)
    {
        if (inputString[i] == '\n')
        {
            if(checkConsonant(firstStrChar) && checkConsonant(inputString[i-1])){
                count++;
            }
            firstStrChar = inputString[i+1];
        }
    }

    printf("count: %d",  count);

    return 0;
}
