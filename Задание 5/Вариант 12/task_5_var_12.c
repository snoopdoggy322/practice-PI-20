#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 7

typedef struct ListNode ListNode;
typedef struct Student Student;

struct Student {
    int number;
    char lastname[30];
    int physics;
    int history;
    int math;
};

struct ListNode {
    Student *data;
    ListNode *left;
    ListNode *right;
};

ListNode *addItem(ListNode *rootNode, int *count, Student *data) {
    if (*count == 0) {
        rootNode->data = data;
        rootNode->left = NULL;
        rootNode->right = NULL;
        return rootNode;
    }

    if (strcmp(rootNode->data->lastname, data->lastname) > 0) {
        // then left
        if (rootNode->left != NULL) {
            addItem(rootNode->left, count, data);
        } else {
            ListNode *newNode = (ListNode *) malloc(sizeof(ListNode));
            rootNode->left = newNode;
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
        }
        return rootNode;
    } else {
        //then right
        if (rootNode->right != NULL) {
            addItem(rootNode->right, count, data);
        } else {
            ListNode *newNode = (ListNode *) malloc(sizeof(ListNode));
            rootNode->right = newNode;
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
        }
        return rootNode;
    }
}

void print2DUtil(ListNode *root, int space, char *symbol) {
    // Base case
    if (root == NULL || root->data == NULL) return;

    space += COUNT;

    print2DUtil(root->right, space, "┌────");

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%s", symbol);
    printf("%s\n", root->data->lastname);

    // Process left child
    print2DUtil(root->left, space, "└────");
}

void printList(ListNode *root) {
    if (root == NULL || root->data == NULL) {
        return;
    }

    printList(root->right);

    printf("| %-21s | %-15d | %-15d | %-16d |\n", root->data->lastname, root->data->physics, root->data->history,
           root->data->math);

    printList(root->left);
}

void show(ListNode *root, char *type) {
    if (root == NULL || root->data == NULL) return;

    if (type == "tree") {
        char symbol[5] = "-- ";
        print2DUtil(root, 0, symbol);
    }
    if (type == "list") {
        printf("+-----------------------+-----------------+-----------------+------------------+\n");
        printf("|        surname        |      physics    |      history    |        math      |\n");
        printf("+-----------------------+-----------------+-----------------+------------------+\n");
        printList(root);
    }
}



void countLeaves(ListNode *root, int *pCountLeaves) {
    if (root == NULL || root->data == NULL) return;

    if(root->right == NULL){
        ++*pCountLeaves;
    } else {
        countLeaves(root->right, pCountLeaves);
    }

    if(root->left == NULL){
        ++*pCountLeaves;
    } else {
        countLeaves(root->left, pCountLeaves);
    }
}


void deleteTree(ListNode *root, int *pCount) {
    if (root == NULL || root->data == NULL) return;

    /* first delete both subtrees */
    deleteTree(root->left, pCount);
    deleteTree(root->right, pCount);

    /* then delete the node */
    printf("Deleting node: %s\n ", root->data->lastname);
    free(root);
    memset(root, 0, sizeof(ListNode));
    --*pCount;
}

void deleteSelectedNode(ListNode *root, char *lastname, int *pCount){
    if (root == NULL || root->data == NULL) return;

    if(strcmp(root->data->lastname, lastname) == 0){
        deleteTree(root, pCount);
        return;
    } else {
        deleteSelectedNode(root->right, lastname, pCount);
        deleteSelectedNode(root->left, lastname, pCount);
    }
}

void print_menu() {
    printf("What do you want to do?\n");
    printf("1. Print tree\n");
    printf("2. Print list\n");
    printf("3. Add new item\n");
    printf("4. Remove selected node and node descendants\n");
    printf("5. Delete tree\n");
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
    ListNode *nodeHead = (ListNode *) malloc(sizeof(ListNode));

    do {
        if (nodeHead == NULL) nodeHead = (ListNode *) malloc(sizeof(ListNode));

        print_menu();

        variant = get_variant(6);

        switch (variant) {
            case 1:
                show(nodeHead, "tree");
                break;

            case 2:
                show(nodeHead, "list");
                break;

            case 3:
                printf("");
                Student *data = (Student *) malloc(sizeof(Student));
                printf("Write student lastname \n > ");
                scanf("%30s", data->lastname);
                printf("\n Write physics rate \n > ");
                scanf("%d", &data->physics);
                printf("\n Write history rate \n > ");
                scanf("%d", &data->history);
                printf("\n Write math rate \n > ");
                scanf("%d", &data->math);

                addItem(nodeHead, pCount, data);
                ++count;
                break;
            case 4:
                printf("");
                char lastname[30];
                printf("Write student surname \n");
                scanf("%s", lastname);
                deleteSelectedNode(nodeHead, lastname, pCount);
                break;
            case 5:
                deleteTree(nodeHead, pCount);
                break;
        }
    } while (variant != 6);

    return 0;
}