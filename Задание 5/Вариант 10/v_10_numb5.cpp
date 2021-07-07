
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <clocale>
using namespace std;


const int nameLength = 20;

struct student {
	int number;
	char name[nameLength];
	struct grades {
		int physics;
		int history;
		int math;
	} grade;
};

struct node {
	student data;
	node* left;
	node* right;
};


node* addStudent(node* top, const student& newnode);
int menu();
int searchStudent(node* top, char* studentName, bool& isFound);
void viewTree(node* top, int indent);
void viewTable(node* top);
int writeToFile(ofstream& f, node* top);
int readFile(char* filename, node*& top);
student enterStudent();
void deleteAllStudents(node*& top);



int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	node* top = NULL;
	char* filename = "student2.txt";
	ofstream fout;
	readFile(filename, top);

	while (1) {
		switch (menu()) {
		case 1:
			top = addStudent(top, enterStudent());
			break;
		case 2:
			viewTree(top, 1);
			cout << "To continue, press any key" << endl;
			cin.get();
			break;
		case 3:
			if (!top) {
				cout << "There's no info in file" << endl;
			}
			else {
				cout << "-----------------------------------------------------" << endl;
				cout << "| N |  Name     |  Physics  |  History  | Math      |" << endl;
				cout << "-----------------------------------------------------" << endl;
				viewTable(top);
			}
			cout << "-----------------------------------------------------" << endl;
			cout << "To continue, press any key" << endl;
			cin.get();
			break;

		case 4: {
			if (!top) {
				cout << "There's no info in the tree" << endl;
				cout << "To continue, press any key" << endl;
				cin.get();
				break;
			}
			char* name;
			cin >> name;
			bool isFound = false;
			searchStudent(top, name, isFound);
			if (isFound) {
				cout << "Amount from: " << N << endl;
			}
			else {
				cout << "There is no any Ivanov" << endl;
			}
			cout << "To continue, press any key" << endl;
			cin.get();
			break;
		}

		case 5:
			fout.open(filename);
			if (!fout) {
				cout << "Error in opening file" << endl;
				return 1;
			}
			writeToFile(fout, top);
			cout << "The data was saved to file" << filename << endl;
			cout << "------------------------------" << endl;
			fout.close();
			cout << "To continue, press any key" << endl;
			cin.get();
			break;

		case 6:
			deleteAllStudents(*&top);
			cout << "All students was deleted from the tree" << endl;
			cout << "To continue, press any key" << endl;
			cin.get();
			break;

		case 7: {
			int numberOf3InPhysics = 0,
				numberOf3InHistory = 0,
				numberOf3InMath = 0;

			searchSubject(top, numberOf3InPhysics, numberOf3InHistory, numberOf3InMath);
			showResultOfSearchSubject(numberOf3InPhysics, numberOf3InHistory, numberOf3InMath);
			cout << "To continue, press any key" << endl;
			cin.get();
			break;
		}

		case 8:
			return 0;

		default:
			cout << "You should enter the number from 1 ti 8" << endl;
			cin.get();
			break;
		}
	}
}



node* addStudent(node* top, const student& newnode) {
	if (!top) {
		top = new node;
		if (!top) {
			cout << "There's no free space" << endl;
			return 0;
		}

		top->data = newnode;
		top->left = 0;
		top->right = 0;
	}
	else if (top->data.number > newnode.number)
		top->left = addStudent(top->left, newnode); //добавляем в левое поддерево
	else
		top->right = addStudent(top->right, newnode);

	return top;
}



void viewTree(node* top, int indent) {
	if (top) {
		indent += 3;
		viewTree(top->right, indent);
		cout << setw(indent) << '*' << top->data.number << endl;
		viewTree(top->left, indent);
	}
}



void viewTable(node* top) {
	if (top) {
		cout << "|" << setw(3) << top->data.number << "|";
		cout << setw(11) << top->data.name << "|";
		cout << setw(11) << top->data.grade.physics << "|";
		cout << setw(11) << top->data.grade.history << "|";
		cout << setw(11) << top->data.grade.math << "|" << endl;

		viewTable(top->left);
		viewTable(top->right);
	}
}



student enterStudent() {
	student newStudent;
	cin.ignore();
	cout << "Enter the number of student: ";
	cin >> newStudent.number;

	cin.ignore();
	cout << "Enter the name of student: ";
	cin.getline(newStudent.name, nameLength);

	bool isCorrect = false;
	while (!isCorrect) {
		cout << "Enter the physics grade: ";
		cin >> newStudent.grade.physics;
		if (newStudent.grade.physics < 1 || newStudent.grade.physics > 5) {
			cout << "Wrong format of grade (it should be from 1 to 5)" << endl;
		}
		else {
			isCorrect = true;
		}

	}

	cin.ignore();
	isCorrect = false;
	while (!isCorrect) {
		cout << "Enter the history grade: ";
		cin >> newStudent.grade.history;
		if (newStudent.grade.history < 1 || newStudent.grade.history > 5) {
			cout << "Wrong format of grade (it should be from 1 to 5)" << endl;
		}
		else {
			isCorrect = true;
		}
	}

	cin.ignore();
	isCorrect = false;
	while (!isCorrect) {
		cout << "Enter the math grade: ";
		cin >> newStudent.grade.math;
		if (newStudent.grade.math < 1 || newStudent.grade.math > 5) {
			cout << "Wrong format of grade (it should be from 1 to 5)" << endl;
		}
		else {
			isCorrect = true;
		}
	}

	return newStudent;
}



int menu() {
	char buf[10];
	int item;

	do {
		system("cls");
		cout << "|--------------------------------------------|" << endl;
		cout << "|                  M E N U                   |" << endl;
		cout << "|--------------------------------------------|" << endl;
		cout << "| 1 - Add new student                        |" << endl;
		cout << "| 2 - View tree                              |" << endl;
		cout << "| 3 - View list                              |" << endl;
		cout << "| 4 - Search student                         |" << endl;
		cout << "| 5 - Write to file                          |" << endl;
		cout << "| 6 - Delete all students                    |" << endl;
		cout << "| 8 - EXIT                                   |" << endl;
		cout << "----------------------------------------------" << endl << endl;

		cout << "Enter the number" << endl;
		cin >> buf;
		cin.get();
		item = atoi(buf);

		if (!item) {
			cout << "You should enter the number from 1 to 8" << endl;
			cin.get();
		}
	} while (!item);
	return item;
}


bool isEquals(char* name1, char* name2) {
	for (int i = 0; i < nameLength; i++) {
		if (name2[i] == ' ') break;
		if (name1[i] != name2[i]) {
			return false;
		}
	}
	return true;
}


int searchStudent(node* top, char* elem, bool& isFound) {
	int N = 0;
	if (!top) {
		return -1;
	}
	if (isFound)
		return 0;
	if (isEquals(elem, top->data.name)) {
		isFound = true;
		return 0;
	}
	else {
		searchStudent(top->left, elem, isFound);
		N = N + 1;
		searchStudent(top->right, elem, isFound);
		N = N + 1;
	}

	return N;
}



int readFile(char* filename, node*& top) {
	ifstream fin(filename, ios::in);
	if (!fin) {
		cout << "There is no file " << filename << endl;
		return 1;
	}

	student newStudent;
	top = 0;
	for (int i = 0; i < nameLength; i++) newStudent.name[i] = ' ';

	while (fin >> newStudent.number) {
		fin >> newStudent.name;
		fin >> newStudent.grade.physics;
		fin >> newStudent.grade.history;
		fin >> newStudent.grade.math;
		fin.get();

		top = addStudent(top, newStudent);
	}
	return 0;
}



int writeToFile(ofstream& f, node* top) {
	if (top) {
		f << top->data.number << endl;
		f << top->data.name << endl;
		f << top->data.grade.physics << endl;
		f << top->data.grade.history << endl;
		f << top->data.grade.math << endl;

		writeToFile(f, top->left);
		writeToFile(f, top->right);
	}
	return 0;
}

void deleteAllStudents(node*& top) {
	if (!top)  return;
	deleteAllStudents(top->left);
	deleteAllStudents(top->right);
	delete top;
	top = NULL;

}

