#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

struct student {
	int id;
	char name[255];
	int physics,history,math;
};

struct list {
	struct student stud;
	struct list *ptr;
};

struct list * init(struct student stud) {
	struct list *lst;
	lst = (struct list*)malloc(sizeof(struct list));
	lst->stud = stud;
	lst->ptr = NULL;
	return(lst);
}

struct list * addelem(list *lst, struct student stud) {
	if(!lst)
		return init(stud);
	struct list *temp, *p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->ptr;
	lst->ptr = temp;
	temp->stud = stud;
	temp->ptr = p;
	return(lst);
}

struct list * deletelem(list *lst, list *root) {
	struct list *temp;
	temp = root;
	if(temp==lst) {
		temp=temp->ptr;
	} else {
		while (temp->ptr != lst)
			temp = temp->ptr;
		temp->ptr = lst->ptr;
	}
	free(lst);
	return(temp);
}



void listprint(list *lst) {
	if(!lst) {
		printf("Спиок пуст!");
		return;
	}
	struct list *p = lst;
	printf("№\t\tФамилия\t\tФизика\t\tИстория\t\tМатематика\n");
	do {
		printf("%d\t\t%s\t\t%d\t\t%d\t\t%d\n", p->stud.id,p->stud.name,p->stud.physics,p->stud.history,p->stud.math);
		p = p->ptr;
	} while (p != NULL);
}

int getLength(list *lst)  {
	int count = 0;
	struct list *temp = lst;
	while(temp)  {
		count++;
		temp = temp->ptr;
	}
	return count;
}

struct student copyStudent(list *temp) {
	struct student stud;
	stud.id = temp->stud.id;
	strcpy(stud.name, temp->stud.name);
	stud.physics = temp->stud.physics;
	stud.history = temp->stud.history;
	stud.math = temp->stud.math;
	return stud;
}

struct list * sortList(list *lst) {
	if(!lst)
		return lst;
	if(!lst->ptr)
		return lst;
	struct list *next, *temp,*result=NULL;
	int i, length = getLength(lst);
	for(i=0; i<length; i++) {
		if(lst->ptr==NULL) {
			result = addelem(result,copyStudent(lst));
			return result;
		}
		temp = lst;
		next = lst->ptr;
		do {
			if(result==NULL) {
				if(strcmp (next->stud.name, temp->stud.name)<0)
					temp=next;
			} else {
				if(strcmp (next->stud.name, temp->stud.name)>=0)
					temp=next;
			}
			next = next->ptr;
		} while (next != NULL);
		if(result==NULL)
			result = init(copyStudent(temp));
		else
			result = addelem(result,copyStudent(temp));
		if(temp == lst)
			lst=lst->ptr;
		else
			deletelem(temp,lst);
	}

	return NULL;
}

struct list * deleteList(list *lst) {
	if(!lst) return NULL;
	struct list *p=lst, *prev = lst;

	int i, length = getLength(lst);
	for(i=0; i<length; i++) {
		if(lst->ptr==NULL) {
			free(lst);
			return NULL;
		}
		p=lst;
		prev = lst;
		while(p->ptr) {
			prev = p;
			p=p->ptr;
		}
		prev->ptr=NULL;
		free(p);
	}
	return NULL;
}

void printMenu(int choice) {
	int menui;
	char menu[6][100]= {
		"Добро пожаловать, пользователь! Выбери действие (Выход - Esc):",
		"Создание списка",
		"Просмотр списка",
		"Добавление элемента в список",
		"Удаление списка",
		"Сортировка списка"
	};
	for(menui=0; menui<6; menui++) {
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

struct list * executeAction(int choice,list * lst) {
	unsigned char g;
	switch (choice) {
		case 1:
			if(lst==NULL)
				lst = init(inputStudent());
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
								lst = deleteList(lst);
								lst = init(inputStudent());
								system("cls");
								printf("Список успешно создан!\n");
								listprint(lst);
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
			printf("Список:\n");
			listprint(lst);
			printf("\n\n1)=>Назад");
			getch();
			break;
		case 3:
			lst = addelem(lst,inputStudent());
			system("cls");
			printf("Студент успешно добавлен!\n");
			listprint(lst);
			printf("\n\n1)=>Назад");
			getch();
			break;
		case 4:
			system("cls");
			printf("Список успешно удален:\n");
			lst = deleteList(lst);
			printf("\n\n1)=>Назад");
			getch();
			break;
		case 5:
			system("cls");
			printf("Список успешно отсортирован:\n");
			lst = sortList(lst);
			listprint(lst);
			printf("\n\n1)=>Назад");
			getch();
			break;
		default:
			printf("ERROR!");
			exit(-1);
			break;
	}
	return lst;
}

int main() {
	unsigned char g;
	setlocale(LC_ALL, "Rus");
	int choice = 1;
	struct list* lst;
	do {
		system("cls");
		printMenu(choice);
		g=getch();
		switch (g) {
			case 72:
				if(choice==1)
					choice=5;
				else
					choice--;
				break;
			case 80:
				if(choice==5)
					choice=1;
				else
					choice++;
				break;
			case 13:
				lst = executeAction(choice,lst);
				break;
		}
	} while(g != 27);
	return 1;
}

