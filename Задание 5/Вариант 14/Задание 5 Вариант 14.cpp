#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>




struct student {
	int id;
	char name[255];
	int physics,history,math;
};

typedef student T;
typedef struct Node {
	T data;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;

void printTree(Node *root) {
	if (root) {
		printf("%d",root->data);
		if (root->left || root->right) {
			printf("(");

			if (root->left)
				printTree(root->left);
			else
				printf("NULL");
			printf(",");

			if (root->right)
				printTree(root->right);
			else
				printf("NULL");
			printf(")");
		}
	}
}


Node* getFreeNode(T value, Node *parent) {
	Node* tmp = (Node*) malloc(sizeof(Node));
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}


void insert(Node **head, student value) {
	Node *tmp = NULL;
	if (*head == NULL) {
		*head = getFreeNode(value, NULL);
		return;
	}

	tmp = *head;
	while (tmp) {
		if (value.id> tmp->data.id) {
			if (tmp->right) {
				tmp = tmp->right;
				continue;
			} else {
				tmp->right = getFreeNode(value, tmp);
				return;
			}
		} else if (value.id< tmp->data.id) {
			if (tmp->left) {
				tmp = tmp->left;
				continue;
			} else {
				tmp->left = getFreeNode(value, tmp);
				return;
			}
		} else {
			exit(2);
		}
	}
}

void simPrint(Node* root) {
	if (root) {
		simPrint(root->left);
		printf("%d\t\t%s\t\t%d\t\t%d\t\t%d\n", root->data.id,root->data.name,root->data.physics,root->data.history,root->data.math);
		simPrint(root->right);
	}
}
void printTreeTable(Node* root) {
	if(root) {
		printf("№\t\tФамилия\t\tФизика\t\tИстория\t\tМатематика\n");
		simPrint(root);
	} else
		printf("Дерево данных пусто!\n");

}

void printTreeStructure(Node* root, int n=0) {
	if (root) {
		int i;
		printTreeStructure(root->left,n++);
		for(i = 0; i<n; i++)
			printf("\t");
		printf("%d\n", root->data.id);
		printTreeStructure(root->right,n++);
	}
}
Node* deleteTree(Node* root) {
	if(root!=NULL) {
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
	}
	return NULL;
}

int getLength(Node* root, int length=0) {
	if(root!=NULL) {
		length++;
		length+=getLength(root->left);
		length+=getLength(root->right);
	}
	return length;
}


struct student inputStudent() {
	struct student stud;
	int temp=-1;
	system("cls");
	printf("Добавление студента\nВведите номер:");
	scanf("%d",&stud.id);
	system("cls");
	printf("Добавление студента\nВведите ФИО:");
	scanf("%s",&stud.name);
	system("cls");
	do {
		printf("Добавление студента\nВведите оценку по физике:");
		scanf("%d",&temp);
		if(temp<1||temp>5) {
			system("cls");
			printf("Не верно задана оценка!\n");
		}
	} while(temp<1||temp>5);
	stud.physics=temp;
	system("cls");
	do {
		printf("Добавление студента\nВведите оценку по истории:");
		scanf("%d",&temp);
		if(temp<1||temp>5) {
			system("cls");
			printf("Не верно задана оценка!\n");
		}
	} while(temp<1||temp>5);
	stud.history=temp;
	system("cls");
	do {
		printf("Добавление студента\nВведите оценку по математике:");
		scanf("%d",&temp);
		if(temp<1||temp>5) {
			system("cls");
			printf("Не верно задана оценка!\n");
		}
	} while(temp<1||temp>5);
	stud.math=temp;
	return stud;
}

void printMenu(int choice) {
	int menui;
	char menu[7][100]= {
		"Добро пожаловать, пользователь! Выбери действие (Выход - Esc):",
		"Создание дерева",
		"Просмотр дерева в виде таблицы",
		"Просмотр дерева в виде структуры",
		"Добавление элемента в дерево",
		"Удаление дерева",
		"Подсчет количества хорошистов"
	};
	for(menui=0; menui<7; menui++) {
		if(menui>0) {
			if(choice==menui) {
				printf("%d)=>%s\n",menui,menu[menui]);
			} else {
				printf("%d)%s\n",menui,menu[menui]);
			}
		} else
			printf("%s\n",menu[menui]);
	}
}

int COMSHelper(Node* root,int count=0){
	if(root!=NULL) {
		if(root->data.math>3&&root->data.history>3&&root->data.physics>3)
			count++;
		count += COMSHelper(root->left);
		count += COMSHelper(root->right);
	}
	return count;
}

int countOfMiddleStudents(Node* root){
	int count = 0;
	count = COMSHelper(root);
	return count;
}



struct Node * executeAction(int choice,Node * root) {
	unsigned char g;
	switch (choice) {
		case 1:
			if(root==NULL)
				insert(&root, inputStudent());
			else {
					int localChoice = 1;
				do {
					system("cls");
					printf("Уже существует список. Желаете удалить?\n");
					if(localChoice>0) {
						printf("1)=>Удалить и создать новый список\n");
						printf("2)Назад\n");
					} else {
						printf("1)Удалить и создать новый список\n");
						printf("2)=>Назад\n");
					}
					g=getch();
					switch (g) {
						case 72:
							localChoice*=-1;
							break;
						case 80:
							localChoice*=-1;
							break;
						case 13:
							if(localChoice>0) {
								root = deleteTree(root);
								insert(&root, inputStudent());
								system("cls");
								printf("Дерево успешно создано!\n");
								printTreeTable(root);
								printf("\n\n1)=>Назад");
								getch();
							}
							break;
					}
					if(g==13)
						break;
				} while(g != 27);
			}
			break;
		case 2:	
			system("cls");
			printf("Табличное отображение дерева:\n");
			printTreeTable(root);
			printf("\n\n1)=>Назад");
			getch();
			break;
		case 3:
			system("cls");
			printf("Структурное отображение дерева:\n");
			printTreeStructure(root);
			printf("\n\n1)=>Назад");
			getch();
			break;
		case 4:
			insert(&root, inputStudent());
			system("cls");
			printf("Студент успешно добавлен!\n");
			printTreeTable(root);
			printf("\n\n1)=>Назад");
			getch();
			break;
		case 5:
			system("cls");
			printf("Дерево успешно удалено:\n");
			root = deleteTree(root);
			printf("\n\n1)=>Назад");
			getch();
			break;
		case 6:
			system("cls");
			printf("Количество хорошистов: ");
			printf("%d\n",countOfMiddleStudents(root));
			printf("\n\n1)=>Назад");
			getch();
			break;
		default:
			printf("ERROR!");
			exit(-1);
			break;
	}
	return root;
}

int main() {
	unsigned char g;
	setlocale(LC_ALL, "Rus");
	int choice = 1;
	Node *Tree = NULL;
	do {
		system("cls");
		printMenu(choice);
		g=getch();
		switch (g) {
			case 72:
				if(choice==1)
					choice=6;
				else
					choice--;
				break;
			case 80:
				if(choice==6)
					choice=1;
				else
					choice++;
				break;
			case 13:
				Tree = executeAction(choice,Tree);
				break;
		}
	} while(g != 27);
	return 0;
}
