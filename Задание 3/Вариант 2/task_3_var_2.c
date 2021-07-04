#include <stdio.h>
#include <stdlib.h>
//#include <caca_conio.h>
#include "string.h"
#define STR_LEN 30

struct list
{
    int number;
    char* lastname;
    int physics;
    int history;
    int math;
    struct list *ptr;
};

struct list *init(int number, char *lastname, int physics, int history, int math) // а- значение первого узла
{
    struct list *lst;

    lst = (struct list *)malloc(sizeof(struct list));
    lst->number = number;
    lst->lastname = strdup(lastname);
    lst->physics = physics;
    lst->history = history;
    lst->math = math;
    lst->ptr = NULL; // это последний узел списка
    return (lst);
}

struct list *addItem(struct list *oldLst, int number, char *lastname, int physics, int history, int math)
{
    struct list *newLst;
    newLst = (struct list *)malloc(sizeof(struct list));

    oldLst->ptr = newLst;
    newLst->number = number;
    newLst->lastname = strdup(lastname);
    newLst->physics = physics;
    newLst->history = history;
    newLst->math = math;

    return (newLst);
}

struct list *deleteItem(struct list *lst, struct list *root)
{
    struct list *temp;
    temp = root;
    while (temp->ptr != lst) // просматриваем список начиная с корня
    {                        // пока не найдем узел, предшествующий lst
        temp = temp->ptr;
    }
    temp->ptr = lst->ptr; // переставляем указатель
    free(lst);            // освобождаем память удаляемого узла
    return (temp);
}

struct list *deletehead(struct list *root)
{
    struct list *temp;
    temp = root->ptr;
    free(root);    // освобождение памяти текущего корня
    return (temp); // новый корень списка
}

void printItems(struct list *listHead){
    if(listHead->ptr == NULL){
        printf("Table is empty");
        return;
    }
    printf("+--------------+-----------------------+-----------------+-----------------+------------------+\n");
    printf("|    number    |        surname        |      physics    |      history    |        math      |\n");
    printf("+--------------+-----------------------+-----------------+-----------------+------------------+\n");
    struct list *lst = listHead->ptr;
    do {
        int number = lst->number;
        char *lastname = lst->lastname;
        int physics = lst->physics;
        int history = lst->history;
        int math = lst->math;
        printf("| %-12d | %-21s | %-15d | %-15d | %-16d |\n", number, lastname, physics, history, math);
        lst = lst->ptr;
    } while (lst->ptr != NULL);
}


void printItem(struct list *listSearch, int number, int index){
    if (index == 0){
        printf("Not found");
    }
    if (listSearch->number != index && listSearch->ptr != NULL){
        printItem(listSearch->ptr, number, index);
    }
    if (listSearch->number == index){
        char *lastname = listSearch->lastname;
        int physics = listSearch->physics;
        int history = listSearch->history;
        int math = listSearch->math;
        printf("+--------------+-----------------------+-----------------+-----------------+------------------+\n");
        printf("|    number    |        surname        |      physics    |      history    |        math      |\n");
        printf("+--------------+-----------------------+-----------------+-----------------+------------------+\n");
        printf("| %-12d | %-21s | %-15d | %-15d | %-16d |\n", index, lastname, physics, history, math);
        return;
    } else {
        printf("Not found");
        return;
    }
}

struct list *getLastItem(struct list *lst){
    if (lst->ptr != NULL) {
        lst = getLastItem(lst->ptr);
    }
    return lst;
}

void deleteLists(struct list *listHead){
    struct list *lst = listHead->ptr;
    struct list *next;
    struct list *prev;
    do {
        next = lst->ptr;
        free(lst);
        memset(lst, 0, sizeof(struct list));
        lst = next;
    } while (next->ptr != NULL);
    free(next);
}

void print_menu()
{
    system("cls"); // очищаем экран
    printf("What do you want to do?\n");
    printf("1. Print all items in list\n");
    printf("2. Print selected item\n");
    printf("3. Add new item\n");
    printf("4. Delete selected item\n");
    printf("5. Exit\n");
    printf("> ");
}

int get_variant(int count)
{
    int variant;
    char s[100];    // строка для считывания введённых данных
    scanf("%d", &variant); // считываем строку

    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while ( variant < 1 || variant > count)
    {
        printf("Incorrect input. Try again: "); // выводим сообщение об ошибке
        scanf("%s", s);                         // считываем строку повторно
    }

    return variant;
}

int main()
{
    int variant;
    int count = 0;
    int *pCount = &count;
    struct list *lstInit = init(0, "initname", 0, 0, 0);
    ++count;
    struct list *lstHead = lstInit;
    do
    {
        print_menu(); // выводим меню на экран

        variant = get_variant(6); // получаем номер выбранного пункта меню

        switch (variant)
        {
            case 1:
                printItems(lstHead);
                break;

            case 2:
                printf("Write number \n > ");
                int index;
                scanf("%d", &index);
                printItem(lstHead, count, index);
                break;

            case 3:
                printf("");
                int physics;
                int history;
                int math;
                char lastname[STR_LEN];
                printf("Write student lastname \n > ");
                scanf("%30s", lastname);
                printf("\n Write physics rate \n > ");
                scanf("%d", &physics);
                printf("\n Write history rate \n > ");
                scanf("%d", &history);
                printf("\n Write math rate \n > ");
                scanf("%d", &math);
                addItem(getLastItem(lstHead), count, lastname, physics, history, math);
                ++count;
                break;
            case 4:
                deleteLists(lstHead);
                break;
        }

//        clrscr();
    } while (variant != 6);

    return 0;
}