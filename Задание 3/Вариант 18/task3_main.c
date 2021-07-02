#include <stdio.h>
#include <iostream>
#include <iomanip>
#pragma warning(disable : 4996)

#define STR_SIZE 60
#define TIME_SIZE 11

using namespace std;

struct data_t {
	int id;
	char FIO[STR_SIZE];
	int physics;
	int history;
	int math;
};

struct list_t {
	data_t data;
	list_t* next;
};

const int size_d = sizeof(data_t);
list_t* head, * tail;
// Чтение файла
void read_file(FILE* f) {
	fseek(f, 0, SEEK_END);
	long len = ftell(f) / size_d;
	rewind(f);
	if (len == 0) {
		head = tail = NULL;
	}
	else {
		list_t* tmp;
		tmp = new list_t;
		fread(&tmp->data, size_d, 1, f);
		tmp->next = NULL;
		head = tail = tmp;
		for (int i = 1; i < len; i++) {
			tmp = new list_t;
			fread(&tmp->data, size_d, 1, f);
			tmp->next = NULL;
			tail->next = tmp;
			tail = tmp;
		}
	}
}
// Запись файла
FILE* write_file(FILE* f) {
	fclose(f);
	f = fopen("data.bin", "w+b");
	list_t* tmp = head;
	while (tmp != NULL) {
		fwrite(&tmp->data, size_d, 1, f);
		tmp = tmp->next;
	}
	return f;
}
// Ввод данных с клавиатуры
void input(data_t* data) {
	cout << "Student id:" << endl;
	cin >> data->id;
	cin.get();
	cout << "Student FIO:" << endl;
	cin.getline(data->FIO, STR_SIZE);
	cout << "Physics:" << endl;
	cin >> data->physics;
	cin.get();
	cout << "History:" << endl;
	cin >> data->history;
	cin.get();
	cout << "Math^" << endl;
	cin >> data->math;
	cin.get();
	
}
// Добавить элемент в хвост
void add_tail() {
	list_t* tmp = new list_t;
	input(&tmp->data);
	tmp->next = NULL;
	if (tail == NULL) {
		head = tail = tmp;
	}
	else {
		tail->next = tmp;
		tail = tmp;
	}
}
// Добавить элемент в голову
void add_head() {
	list_t* tmp = new list_t;
	input(&tmp->data);
	tmp->next = head;
	if (head == NULL) {
		head = tail = tmp;
	}
	else {
		head = tmp;
	}
}
// Организация очереди
void organize() {
	char c;
	do {
		add_tail();
		cout << "Continue oranization? (y/n): ";
		cin >> c;
		cin.get();
	} while (c == 'y');
}
// Удаление с головы
void pull() {
	if (head == NULL) {
		cout << "Queue is empty" << endl;
	}
	else {
		list_t* tmp = head;
		head = head->next;
		if (head == NULL) {
			tail = NULL;
		}
		delete tmp;
		cout << "Student removed" << endl;
	}
	cout << "Press enter to continue..." << endl;
	cin.get();
}
// Печать очереди
void show() {
	if (head == NULL) {
		cout << "Queue is empty" << endl;
	}
	else {
		cout << "+---+-------------------------+-----------+-----------+---------+" << endl;
		cout << "| # |    FIO               | Physics |  History  |  Math  |" << endl;
		cout.precision(2);
		list_t* tmp = head;
		while (tmp != NULL) {
			cout << "+---+------------+------------+-----------+-----------+---------+" << endl;
			cout << "|" << setw(3) << tmp->data.id << "|" << setw(12) << tmp->data.FIO << "|" << setw(12) << tmp->data.physics << "|" << setw(11) << tmp->data.history << "|" << setw(11) << tmp->data.math << "|" << endl;
			tmp = tmp->next;
		}
		cout << "+---+------------+------------+-----------+-----------+---------+" << endl;
	}
	cout << "Press enter to continue..." << endl;
	cin.get();
}

bool is_empty() {
	return head == nullptr;
}

void remove_first() {
	//if (is_empty()) return;
	list_t* p = head;
	head = p->next;
	delete p;
}

void remove_last() {
	//if (is_empty()) return;
	if (head == tail) {
		remove_first();
		return;
	}
	list_t* p = tail;
	while (p->next != tail) p = p->next;
	p->next = nullptr;
	delete tail;
	tail = p;
}

// Написать функцию, удаляющую элемент из списка по введенному номеру, скажем, 
// 15й элемент списка (в структуре списка номер НЕ хранится).
void remove(int val) {
	//if (is_empty()) return;
	if (head->data.id == val) {
		remove_first();
		return;
	}
	else if (tail->data.id == val) {
		remove_last();
		return;
	}
	list_t* slow = head;
	list_t* fast = head->next;
	while (fast && fast->data.id != val) {
		fast = fast->next;
		slow = slow->next;
	}
	if (!fast) {
		cout << "This element does not exist" << endl;
		return;
	}
	slow->next = fast->next;
	delete fast;
}
/*void my_function() {
	list_t* lst; // ТУТ ДОЛЖЕН БЫТЬ УКАЗАТЕЛЬ НА УДАЛЯЕМЫЙ ЭЛЕМЕНТ
	//list_t* root;
	int counter = 0, number = 0;
	cout << "Enter the number" << endl;
	cin >> number;
	cout << lst;

	struct list_t* tmp;
	tmp = tail;
	while (tmp->next != lst) // просматриваем список начиная с корня
	{ // пока не найдем узел, предшествующий lst
		tmp = tmp->next;
	}
	tmp->next = lst->next; // переставляем указатель
	free(lst); // освобождаем память удаляемого узла
	return;
} */


	/*if (head == NULL) {
		cout << "Queue is empty" << endl;
	}
	else {
		list_t* tmp = head;
		head = head->next;
		counter = counter + 1;
		while (tmp != NULL) {
			if (counter == number)
			{
			cout << counter << endl;
			tmp = tmp->next;
			delete tmp;
			cout << "Student with number " << number << " removed" << endl;
			}
			else 
				tmp = tmp->next;
				counter = counter + 1;

		}

	}
	cout << "Press enter to continue..." << endl;
	cin.get(); 
} 
*/

int main(int argc, char** argv) {
	FILE* f;
	f = fopen("data.bin", "r+b");
	if (!f) {
		f = fopen("data.bin", "w+b");
		if (!f) {
			cout << "Can`t open (create) file" << endl;
			return 1;
		}
	}
	read_file(f);
	char c;
	while (1) {
		cout << "1 - Organize" << endl;
		cout << "2 - Add in tail" << endl;
		cout << "3 - Add in head" << endl;
		cout << "4 - Pull" << endl;
		cout << "5 - Show" << endl;
		cout << "6 - My function 8" << endl;
		cout << "7 - Exit" << endl;
		cout << "Choose your destiny: ";
		cin >> c;
		cin.get();
		switch (c) {
		case '1':
			organize();
			f = write_file(f);
			break;
		case '2':
			add_tail();
			f = write_file(f);
			break;
		case '3':
			add_head();
			f = write_file(f);
			break;
		case '4':
			pull();
			f = write_file(f);
			break;
		case '5':
			show();
			break;
		case '6':
			cout << "Enter the number of the student you want to remove" << endl;
			int val;
			cin >> val;
			remove(val);
			break;
		case '7':
			fclose(f);
			return 0;
		}
	}
	fclose(f);
	return 0;
} 
