#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///Вариант 10 Задание 1
///Написать программу, которая считывает текст из файла и заменяет любую последовательность точек одним символом *.
/// Например исходный текст: "9.00…1……27.3.4…"; результат: "9*00*1*27*3*4*".
char* replacer(char *str, const char *replaceable, const char *substitute) {

    //erase all asterisks except the last one
    for(int i=0;str[i];i++){
        if((const char *) str[i] == replaceable){
            if (str[i] == str[i+1]){
                str[i] = ' ';
            }
            else{
                str[i]=substitute;
            }
        }
    }

    //delete all spaces
    int end = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != ' ') {
            if (i != end) {
                str[end] = str[i];
            }
            end++;
        }
    }

    str[end] = '\0';
    return str;
}

void replaceDotsToAsterisk(const char *path){
    FILE *file;
    char *line;
    int i, c, maxLine = 512;
    file=fopen(path,"r");

    if (file == NULL) {
        printf( "Не удалось открыть файл\n");
        return;
    }

    line = (char *) malloc(maxLine);

    for(i = 0; (c = getc(file)) != EOF; i++) {
        if(i >= maxLine-1) {
            maxLine *= 2;
            line = (char *) realloc(line, maxLine);
        }
        line[i] = c;
    }
    line[i] = '\0';
    fclose(file);

    printf( "-Было: \n%s", line );
    line =  replacer(line, '.', '*');
    printf( "\n-Стало: \n%s", line );
}


int main() {
    char path[]="file.txt";

    replaceDotsToAsterisk(path);

    return 0;
}
