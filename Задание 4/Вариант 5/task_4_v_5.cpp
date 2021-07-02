#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


unsigned int compareNumbers(int* number1, int* number2, int size);
void printResult(int* number1, int* number2, int size, unsigned int resultOfCompare);

int main(int argc, char** argv) {
	
	const unsigned int size = 200;
	int* number1 = new int[size];
	int* number2 = new int[size];
	
	const unsigned int range = 10;
	srand((unsigned)time(NULL));
	srand((unsigned)rand());
	for (int i = 0; i < size; i++) {
		number1[i] = rand() % range;
		number2[i] = rand() % range;	
	}
	
	printResult(number1, number2, size, compareNumbers(number1, number2, size));
	
	delete number1;
	delete number2;
	
	return 0;
}

unsigned int compareNumbers(int* number1, int* number2, int size) {
	for (int i = 0; i < size; i++) {
		if (number1[i] > number2[i]) {
			return 1;
		}
		if (number1[i] < number2[i]) {
			return -1;
		}
	}
	return 0;
}

void printResult(int* number1, int* number2, int size, unsigned int resultOfCompare){
	
	switch (resultOfCompare) {
		case -1:
			for (int i = 0; i < size; i++) {
				cout << number2[i];
			}
			cout << endl << "  is bigger than  " << endl;
			for (int i = 0; i < size; i++) {
				cout << number1[i];
			}	
			break;
		case 0:
			for (int i = 0; i < size; i++) {
				cout << number1[i];
			}
			cout << endl << "  ==  " << endl;
			for (int i = 0; i < size; i++) {
				cout << number2[i];
			}	
			break;
		case 1:	
		for (int i = 0; i < size; i++) {
			cout << number1[i];
		}
		cout << endl << "  is bigger than  " << endl;
		for (int i = 0; i < size; i++) {
			cout << number2[i];
		}	
			
	}
	cout << endl;
	
}
