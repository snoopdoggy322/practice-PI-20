#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


unsigned int compareNumbers(int* number1, int* number2, int* number3, int size);
void printResult(int* number1, int* number2, int* number3, int size, unsigned int resultOfCompare);

int main(int argc, char** argv) {
	
	const unsigned int size = 200;
	int* number1 = new int[size];
	int* number2 = new int[size];
	int* number3 = new int[size];
	
	const unsigned int range = 10;
	srand((unsigned)time(NULL));
	srand((unsigned)rand());
	for (int i = 0; i < size; i++) {
		number1[i] = rand() % range;
		number2[i] = rand() % range;
		number3[i] = rand() % range;	
	}
	
	cout << "FIRST number" << endl;
	for (int i = 0; i < size; i++) {
		cout << number1[i];
	}
	cout << endl << "SECOND number" << endl;
	for (int i = 0; i < size; i++) {
		cout << number2[i];
	}
	cout << endl << "THIRD number" << endl;
	for (int i = 0; i < size; i++) {
		cout << number3[i];
	}
	
	printResult(number1, number2, number3, size, compareNumbers(number1, number2, number3, size));
	
	delete number1;
	delete number2;
	delete number3;
	
	return 0;
}

unsigned int compareNumbers(int* number1, int* number2, int* number3, int size) {
	for (int i = 0; i < size; i++) {
		if (number1[i] > number2[i] && number1[i] > number3[i]) {
			return 1;
		}
		if (number2[i] > number1[i] && number2[i] > number3[i]) {
			return 2;
		}
	}
	return 3;
}

void printResult(int* number1, int* number2, int* number3, int size, unsigned int resultOfCompare){
	
	switch (resultOfCompare) {
		case 1:
			cout << endl << "MAX number is  " << endl;
			for (int i = 0; i < size; i++) {
				cout << number1[i];
			}
			break;
		case 2:
			cout << endl << "MAX number is  " << endl;
			for (int i = 0; i < size; i++) {
				cout << number2[i];
			}
			break;
		case 3:	
			cout << endl << "MAX number is  " << endl;
			for (int i = 0; i < size; i++) {
				cout << number3[i];
			}
			
	}
	cout << endl;
	
}

