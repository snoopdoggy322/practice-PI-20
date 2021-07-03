#include <stdio.h>

///Вариант 1 - Задание 1
///Написать программу, которая считывает текст из файла и определяет количество символов Х в каждой строке

void cntLines(const char *path, const char *searchedSymbol) {

    int any;    //'cause EOF has type int
    int signsCount = 0;
    int linesCount = 1;

    FILE *f = fopen(path, "r");
    if (f == NULL) {
        printf( "Не удалось открыть файл\n");
        return;
    }
    do {
        any = fgetc(f);
        if (any == searchedSymbol){
            signsCount++;
        }
        if (any == '\n') {
            printf( "Строка %i содержит %i символа %c \n", linesCount, signsCount, searchedSymbol);
            linesCount++;
            signsCount = 0;
        }
    } while(any != EOF);
    fclose(f);
}

int main() {
    char path[]="file.txt";

    printf( "Введите символ поиска: ");
    char c = getchar( );
    cntLines (path, c);
    return 0;
}