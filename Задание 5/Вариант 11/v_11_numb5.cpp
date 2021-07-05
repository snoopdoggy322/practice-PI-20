#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Student {
	int id;
	string name;
	int physics;
	int math;
	int history;
};

struct node_t {
	Student data;
	node_t* left, * right;
};


const int size_d = sizeof(Student);
node_t* root;
// Добавить узел
void add_node(Student data) {
	node_t* node = new node_t;
	node->data = data;
	node->left = node->right = NULL;
	if (root == NULL) {
		root = node;
	}
	else {
		node_t* tmp = root;
		while (tmp != NULL) {
			if (node->data.id > tmp->data.id) {
				if (tmp->right == NULL) {
					tmp->right = node;
					tmp = NULL;
				}
				else {
					tmp = tmp->right;
				}
			}
			else {
				if (tmp->left == NULL) {
					tmp->left = node;
					tmp = NULL;
				}
				else {
					tmp = tmp->left;
				}
			}
		}
	}
}
// Чтение файла
void read_file(FILE* f) {
	fseek(f, 0, SEEK_END);
	long len = ftell(f) / size_d;
	rewind(f);
	root = NULL;
	Student data;
	for (int i = 0; i < len; i++) {
		fread(&data, size_d, 1, f);
		add_node(data);
	}
}
// Запись узла в файл
void write_data(FILE* f, node_t* node) {
	if (node == NULL) {
		return;
	}
	fwrite(&node->data, size_d, 1, f);
	write_data(f, node->left);
	write_data(f, node->right);
}
// Запись файла
FILE* write_file(FILE* f) {
	fclose(f);
	f = fopen("data.bin", "w+b");
	write_data(f, root);
	return f;
}
// Ввод данных с клавиатуры
Student input() {
	Student data;
	cout << "Number:" << endl;
	cin >> data.id;
	cout << "Name:" << endl;
	cin >> data.name;
	cin.get();
	cout << "Math:" << endl;
	cin >> (data.math);
	cout << "Physics:" << endl;
	cin >> (data.physics);
	cout << "History:" << endl;
	cin >> (data.history);
	return data;
}
// Организация очереди
void organize() {
	char c;
	do {
		add_node(input());
		cout << "Continue oranization? (y/n): ";
		cin >> c;
		cin.get();
	} while (c == 'y');
}
// Печать дерева
void show_all(node_t* node) {
	if (root == NULL) {
		cout << "Tree is empty" << endl;
		cout << "Press enter to continue..." << endl;
		cin.get();
		return;
	}
	if (node == NULL) {
		return;
	}
	if (node == root) {
		cout << "+---+------------+------------+-----------+----------+" << endl;
		cout << "| # |    Name    |     History     | Math |  Physics |" << endl;
	}
	cout.precision(2);
	cout << "+---+------------+------------+-----------+-----------+" << endl;
	cout << "|" << setw(3) << node->data.id << "|" << setw(12) << node->data.name << "|" << setw(12) << node->data.history << "|" << setw(11) << node->data.physics << "|" << setw(11) << node->data.math << endl;
	show_all(node->left);
	show_all(node->right);
	if (node == root) {
		cout << "+---+------------+------------+-----------+-----------+" << endl;
		cout << "Press enter to continue..." << endl;
		cin.get();
	}
}
// Печать структуры дерева
void show_map(node_t* node, int tab) {
	if (tab == 0) {
		if (node == NULL) {
			cout << "Tree is empty" << endl;
		}
		else {
			cout << "Tree structure:" << endl;
		}
	}
	if (node != NULL) {
		show_map(node->right, tab + 3);
		cout << setw(tab) << " " << node->data.id << endl;
		show_map(node->left, tab + 3);
	}
	if (tab == 0) {
		cout << "Press enter to continue..." << endl;
		cin.get();
	}
}

int nelem(node_t* p, int level)
{
	static int i = 0, cnt = 0;

	if (p == NULL)
		return 0;
	else if (i == level)
		return 1;
	else {
		i++;
		cnt += nelem(p->left, level);
		cnt += nelem(p->right, level);
	}
	return cnt;
}
void countOfEementsOnRLevel() {
	int level;
	int count = 0;
	cout << "Type level:" << endl;
	cin >> level;
	if (root == NULL) {
		cout << "Tree is empty" << endl;
		cout << "Press enter to continue..." << endl;
		cin.get();
		return;
	}
	count = nelem(root, level);
	cout << "Count of elements - " << count << endl;
	cout << "Press enter to continue..." << endl;
	cin.get();
}

void node_min(const node_t* tr, int& min, int& count) {
	int m, c;
	min = (tr->data.history + tr->data.physics + tr->data.math) / 3;
	count = 1;
	if (tr->left) {
		node_min(tr->left, m, c);
		if (m < min) {
			min = m;
			count = c;
		}
		else if (m == min)
			count += c;
	}
	if (tr->right) {
		node_min(tr->right, m, c);
		if (m < min) {
			min = m;
			count = c;
		}
		else if (m == min)
			count += c;
	}
}

int treeHeight(node_t* node)
{
	if (node) {
		return 1 + max(treeHeight(node->left), treeHeight(node->right));
	}
	return 0;
}

int main(int argc, char** argv) {
	FILE* f;
	f = fopen("data.bin", "r+b");
	if (!f) {
		f = fopen("data.bin", "w+b");
		if (!f) {
			cout << "Can`t open (create) file" << endl;
			cin.get();
			return 1;
		}
	}
	read_file(f);
	char c;
	int min = 0;
	while (1) {
		cout << "1 - Organize" << endl;
		cout << "2 - Add node" << endl;
		cout << "3 - Show elements" << endl;
		cout << "4 - Show structure" << endl;
		cout << "5 - Count elements on level" << endl;
		cout << "6 - Max avg" << endl;
		cout << "7 - Deep of tree" << endl;
		cout << "8 - Exit" << endl;
		cout << "Do: ";
		cin >> c;
		cin.get();
		switch (c) {
		case '1':
			organize();
			f = write_file(f);
			break;
		case '2':
			add_node(input());
			f = write_file(f);
			break;
		case '3':
			show_all(root);
			break;
		case '4':
			show_map(root, 0);
			break;
		case '5':
			countOfEementsOnRLevel();
			break;
		case '6':
			node_min(root, min, min);
			break;
		case '7':
			cout << treeHeight(root) << endl;
			break;
		case '8':
			fclose(f);
			return 0;
		}
	}
	fclose(f);
	return 0;
}
