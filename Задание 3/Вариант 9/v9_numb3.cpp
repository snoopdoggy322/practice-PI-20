#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
typedef struct vedomost {
    struct information {
        struct mark {
            int math, phys, history;
        } marks;
        char fam[15];
        int num;
    } inf;
    struct vedomost* next;
} infvedom;
const long size_str = sizeof(struct vedomost);
infvedom create() {
    infvedom temp;
    printf("Введите номер или <-1> для выхода\n");
    scanf_s("%d", &temp.inf.num);
    if (temp.inf.num == -1) return temp;
    printf("Введите фамилию или * для выхода\n");
    scanf_s("%15s", &temp.inf.fam);
    printf("Введите оценку по математике\n");
    scanf_s("%d", &temp.inf.marks.math);
    printf("Введите оценку по физике\n");
    scanf_s("%d", &temp.inf.marks.phys);
    printf("Введите оценку по истории\n");
    scanf_s("%d", &temp.inf.marks.history);
    return temp;
}

infvedom* add(infvedom* head, infvedom temp) {
    if (temp.inf.num == -1) return head;
    if (!head) {
        head = (infvedom*)malloc(size_str);
        head->inf = temp.inf;
        head->next = NULL;
    }
    else {
        infvedom* temp1 = (infvedom*)malloc(size_str);
        temp1->inf = temp.inf;
        temp1->next = head->next;
        head->next = temp1;
    }
    return head;
}

void show(infvedom* left) {
    if (!left) {
        printf("Список пуст\n");
        return;
    }
    else {
        while (left) {
            printf("|%d|%-15s", left->inf.num, left->inf.fam);
            printf("|%-d|%-d|%-d|\n", left->inf.marks.math, left->inf.marks.phys, left->inf.marks.history);
            left = left->next;
        };
    }
}

void writefile(infvedom* left) {
    FILE* filename = fopen("doc.txt", "w+b");
    rewind(filename);
    if (!filename) {
        printf("Не удалось открыть файл\n");
        return;
    }
    else {
        while (left) {
            fprintf(filename, "%d", left->inf.num);
            fprintf(filename, "\n");
            fprintf(filename, "%-15s", left->inf.fam);
            fprintf(filename, "\n");
            fprintf(filename, "%d", left->inf.marks.math);
            fprintf(filename, "\n");
            fprintf(filename, "%d", left->inf.marks.phys);
            fprintf(filename, "\n");
            fprintf(filename, "%d", left->inf.marks.history);
            fprintf(filename, "\n");
            left = left->next;
        }
    }
    fclose(filename);
    printf("Данные записаны в файл\n");
}

infvedom* readfile(infvedom* head) {
    FILE* filename = fopen("doc.txt", "r+b");
    rewind(filename);
    infvedom temp1;
    while (!feof(filename)) {
        fscanf(filename, "%d", &temp1.inf.num);
        fscanf(filename, "%s", temp1.inf.fam);
        fscanf(filename, "%d", &temp1.inf.marks.math);
        fscanf(filename, "%d", &temp1.inf.marks.phys);
        fscanf(filename, "%d", &temp1.inf.marks.history);
        head = add(head, temp1);
        temp1.inf.num = -1;
    }
    fclose(filename);
    printf("Данные считаны из файла\n");
    return head;
}

infvedom* clean(infvedom* head) {
    infvedom* temp1 = head->next;
    while (temp1) {
        infvedom* temp = temp1;
        temp1 = temp1->next;
        free(temp);
    }
    free(head);
    head = NULL;
    return head;
}

infvedom* transposition(infvedom* head) {
    infvedom* temp, * temp1;
    infvedom newE;
    temp = head;
    if (!temp) {
        printf("список пуст");
        _getch();
        return head;
    }
    while (temp->next->next->next != NULL)
        temp = temp->next;
    temp1 = temp->next;
    newE.inf = temp1->inf;
    temp->next = temp1->next;
    free(temp1);
    head = add(head, newE);
    printf("Перестановка завершена");
    _getch();
    return head;
}

int main() {
    setlocale(LC_ALL, "rus");
    int k = 0;
    infvedom* head = NULL;
    while (1) {
        system("cls");
        printf("--------------------------------------\n");
        printf("1 - Создание списка || дополнение существующего \n");
        printf("2 - Просмотр списка\n");
        printf("3 - Удаление спиcка\n");
        printf("4 - Запись в файл\n");
        printf("5 - Чтение из файла\n");
        printf("6 - Вариант 9\n");
        printf("0 - Выход\n");
        printf("--------------------------------------\n");
        printf("Введите номер выбранного пункта меню\n");
        scanf_s("%d", &k);
        switch (k) {
        case 1: {
            head = add(head, create());
        }
              break;
        case 2: {
            show(head);
            printf("tap <enter>");
            _getch();
        }
              break;
        case 3: {
            if (head) {
                head = clean(head);
                printf("Память очищена\n");
            }
            else
                printf("Список пуст\n");

            _getch;
        }
              break;
        case 4: {
            if (head)
                writefile(head);
            else
                printf("Список пуст\n");
        }
              break;
        case 5: {
            if (!head)
                head = readfile(head);
            else
                printf("Список не пустой\n");
        }
              break;
        case 6: {
                transposition(head);
        }
              break;
        }
    }
}