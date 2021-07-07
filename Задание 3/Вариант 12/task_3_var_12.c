#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define STR_LEN 30

typedef struct List List;
struct List {
    int number;
    char *lastname;
    int physics;
    int history;
    int math;
    struct List *ptr;
};

List *addItem(List *oldLst, int *pCount, char *lastname, int physics, int history, int math) {
    if (*pCount == 0) {
//        oldLst = (List *) malloc(sizeof(List));
        ++*pCount;
        oldLst->number = *pCount;
        oldLst->lastname = strdup(lastname);
        oldLst->physics = physics;
        oldLst->history = history;
        oldLst->math = math;
        oldLst->ptr = NULL;
        return(oldLst);
    }

    List *newLst;
    newLst = (List *) malloc(sizeof(List));
    ++*pCount;
    oldLst->ptr = newLst;
    newLst->number = *pCount;
    newLst->lastname = strdup(lastname);
    newLst->physics = physics;
    newLst->history = history;
    newLst->math = math;
    newLst->ptr = NULL;

    return (oldLst);
}


void printItems(List *lst, int *pCount) {
    if (*pCount == 0) {
        printf("Table is empty");
        return;
    }
    printf("+--------------+-----------------------+-----------------+-----------------+------------------+\n");
    printf("|    number    |        surname        |      physics    |      history    |        math      |\n");
    printf("+--------------+-----------------------+-----------------+-----------------+------------------+\n");

    do {
        int number = lst->number;
        char *lastname = lst->lastname;
        int physics = lst->physics;
        int history = lst->history;
        int math = lst->math;
        printf("| %-12d | %-21s | %-15d | %-15d | %-16d |\n", number, lastname, physics, history, math);
        lst = lst->ptr;
    } while (lst != NULL);
}


void printItem(List *listSearch, int *pCount, int index) {
    if (index == 0) {
        printf("Not found");
    }
    if (listSearch->number != index && listSearch->ptr != NULL) {
        printItem(listSearch->ptr, pCount, index);
    }
    if (listSearch->number == index) {
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

List *getLastItem(List *lst, int *pCount) {
    if(*pCount == 0) {
       return lst;
    }
    if (lst->ptr != NULL) {
        lst = getLastItem(lst->ptr, pCount);
    }
    return lst;
}

void updateList(List *pList, int *pCount, int index, char *lastname, int physics, int history, int math) {
    if (index == 0) {
        printf("Not found");
    }
    while (pList->number != index) {
        if(pList->ptr == NULL){
            printf("Not found");
            return;
        }
        pList = pList->ptr;
    }
    pList->lastname = strdup(lastname);
    pList->physics = physics;
    pList->history = history;
    pList->math = math;
}

void deleteLists(List *lst) {
    List *next;
    do {
        next = lst->ptr;
        free(lst);
        memset(lst, 0, sizeof(List));
        lst = next;
    } while (next->ptr != NULL);
    free(next);
    memset(next, 0, sizeof(List));
}

void print_menu() {
    printf("\n");
    printf("What do you want to do?\n");
    printf("1. Print all items in list\n");
    printf("2. Print selected item\n");
    printf("3. Add new item\n");
    printf("4. Update selected item\n");
    printf("5. Delete lists\n");
    printf("6. Exit\n");
    printf("> ");
}

int get_variant(int count) {
    int variant;
    scanf("%d", &variant);

    while (variant < 1 || variant > count) {
        printf("Incorrect input. Try again: ");
        scanf("%d", &variant);
    }
    return variant;
}

int main() {
    int variant;
    int count = 0;
    int *pCount = &count;
    List *lstHead = (List *) malloc(sizeof(List));
//    List *lstHead;
    do {
        print_menu(); // выводим меню на экран

        variant = get_variant(6); // получаем номер выбранного пункта меню

        switch (variant) {
            case 1:
                printItems(lstHead, pCount);
                break;

            case 2:
                printf("Write number \n > ");
                int index;
                scanf("%d", &index);
                printItem(lstHead, pCount, index);
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
                lstHead = addItem(getLastItem(lstHead, pCount), pCount, lastname, physics, history, math);
                break;

            case 4:
                printf("Write number \n > ");
                scanf("%d", &index);
                printf("Write student lastname \n > ");
                scanf("%30s", lastname);
                printf("\n Write physics rate \n > ");
                scanf("%d", &physics);
                printf("\n Write history rate \n > ");
                scanf("%d", &history);
                printf("\n Write math rate \n > ");
                scanf("%d", &math);
                updateList(lstHead, pCount, index, lastname, physics, history, math);
                break;

            case 5:
                deleteLists(lstHead);
                break;
        }
    } while (variant != 6);

    return 0;
}


