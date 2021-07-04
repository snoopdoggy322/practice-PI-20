
#include <stdio.h>

int main(){
    int size_t = 123;
    char inputString[size_t];
    int count = 0;
   printf("Enter a multi line string( press ';' to end input)\n");
   scanf("%[^;]s", inputString);

   printf("Input String = %s. \n", inputString);
   printf("%s", "for loop started... \n");

   for (int i = 0; i < size_t; i++)
   {
       if (inputString[i] == '\n' && inputString[i+1] == ' ')
       {
           count++;
       }
   }
   printf("count: %d",  count);

   return 0;
}
