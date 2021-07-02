#include <iostream>
#include <string>
#include <cstring>
using namespace std;


char** enterText();
int countRowsWithArithmeticOperations(char** text, int numberOfRows);
int numberOfRows = 0; 

int main(int argc, char** argv) {
	
	char** text = enterText();
	if (text == NULL) {
		cout << "Error in text input." << endl;
		return 1;
	}
	
	int rowsWithArithmeticOperations = countRowsWithArithmeticOperations(text, numberOfRows);
	cout << endl << "Number of rows with arithmetic operations: " << rowsWithArithmeticOperations << endl;
	
	return 0;
}

char** enterText() {
	const int minNumberOfRows = 1;
	const int maxNumberOfRows = 100;	
	const int maxLengthOfRow = 255;
	
	
	cout << "Enter the number of rows: ";
	cin >> numberOfRows;
	if (numberOfRows < minNumberOfRows || numberOfRows > maxNumberOfRows) {
		cout << "Wrong number of rows! ";
		return NULL;
	}
	
	char** text = new char* [numberOfRows];
	for (int i = 0; i < numberOfRows; i++) text[i] = new char[maxLengthOfRow];
	
	cin.ignore();
	cout << "Enter the text: " << endl;
	int rowsCount = 0;
	while (rowsCount < numberOfRows){
		cin.getline(text[rowsCount], maxLengthOfRow);
		rowsCount++;
	}
	
	return text;
}

int countRowsWithArithmeticOperations(char** text, int numberOfRows) {
	
	int result = 0;
	
	const int numberOfArithmeticOperations = 4;
	const char* arithmeticOperations = new char[numberOfArithmeticOperations] {'+', '-', '*', '/'};
	
	for (int countRows = 0; countRows < numberOfRows; countRows++) {
		for (int countOperations = 0; countOperations < numberOfArithmeticOperations; countOperations++) {
			if (strchr(text[countRows], arithmeticOperations[countOperations])) {
    			result++;
    			break;
			}
		}
	}
	
	delete arithmeticOperations;
	return result;
}
