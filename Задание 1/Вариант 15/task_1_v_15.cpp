#include <iostream>
#include <string>
#include <cstring>
using namespace std;


char** enterText();
char** replaceArithmeticOperations(char** text, int numberOfRows);
const int numberOfRows = 10;


int main(int argc, char** argv) {
		
	char** text = enterText();
	char** newText = replaceArithmeticOperations(text, numberOfRows);

	for (int count = 0; count < numberOfRows; count++) {
			cout << newText[count] << endl;
		}
	
	return 0;
}


char** enterText() {
	const int minNumberOfRows = 1;
	const int maxNumberOfRows = 100;	
	const int maxLengthOfRow = 255;
	
	char** text = new char* [numberOfRows];
	for (int i = 0; i < numberOfRows; i++) text[i] = new char[maxLengthOfRow];
	
	cout << "Enter the text: " << endl;
	int rowsCount = 0;
	while (rowsCount < numberOfRows){
		cin.getline(text[rowsCount], maxLengthOfRow);
		rowsCount++;
	}
	
	return text;
}

char** replaceArithmeticOperations(char** text, int numberOfRows) {
	
	const char symbol = '_';
	
	const int numberOfArithmeticOperations = 4;
	const char* arithmeticOperations = new char[numberOfArithmeticOperations] {'+', '-', '*', '/'};
	
	
	for (int countRows = 0; countRows < numberOfRows; countRows++) {
		char* ptr = text[countRows]; 
		while (*ptr != '\0') {
			for (int countOperations = 0; countOperations < numberOfArithmeticOperations; countOperations++) {
				if (*ptr == arithmeticOperations[countOperations]) {
	    			*ptr = symbol;
				}
			}
			*ptr++;
		}
	}
	
	delete arithmeticOperations;
	return text;
}
