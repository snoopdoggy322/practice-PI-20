#include <iostream>
#include <string>
#include <cstring>
using namespace std;


char** enterText();
int countRowsWithArithmeticOperations(char** text, int numberOfRows);
int numberOfRows = 10; 

int main(int argc, char** argv) {
	
	char** text = enterText();	
	int rowsWithArithmeticOperations = countRowsWithArithmeticOperations(text, numberOfRows);
	cout << rowsWithArithmeticOperations << endl;
	
	return 0;
}

char** enterText() {
	const int minNumberOfRows = 1;
	const int maxNumberOfRows = 100;	
	const int maxLengthOfRow = 255;
	
	char** text = new char* [numberOfRows];
	for (int i = 0; i < numberOfRows; i++) text[i] = new char[maxLengthOfRow] {};

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
