#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <conio.h>
#include <iostream>
#include <clocale>
using namespace std;

const int nameLength = 20;

struct student
{   int number;
    char name[nameLength];
    struct grades
    {
      int physics;
      int history;
      int math;
    } grade;

    student*next;
};



student* add(student* end, const student& newStudent);
student* addFirst(const student& newStudent);
student enterStudent();
int menu();
void print(const student& student1);
void view(student*beg);
int readFile(char* filename, student** beg, student** end);
int writeFile(char* filename, student* beg);
int deleteAllElements(char* filename, student** beg, student** end);
void searchStudentsWithSameName(student* beg);
int searchSubjectWithMinNumberOf3(student* beg);


int main() {
	
	setlocale(LC_ALL,"Russian"); 
	student *beg=0,
    	    *end=0;
  
  	char *filename="students.txt";


  	while(1) {  
	  switch (menu()) {   
	  	case 1:
	    	if (beg)
	        	end = add(end, enterStudent());
		    else {
		        beg = addFirst(enterStudent());
		        end = beg;
		    }
	      break;
   		//===================
    	case 2:
		    view(beg);
		    cout<<endl<<"To continue, press any key"<<endl;
		    getch();
		    break;
	   //===================
	    case 3:
		    writeFile(filename, beg);
		    cout << "The data is written to a file " << filename << endl;
		    cout << "To continue, press any key" << endl;
		    getch();
		    break;
	   //===================
	    case 4:
		    readFile(filename, &beg, &end);
		    break;
	   //===================
	    case 5:            
	    	deleteAllElements(filename, &beg, &end);
			break;
	   //===================
	    case 6:            
	    	searchStudentsWithSameName(beg);
	    	cout << "To continue, press any key" << endl;
	    	getch();
	    	break;
	   //===================
	    case 7:            
	    	searchSubjectWithMinNumberOf3(beg);
	    	break;
	   //===================
	    case 8:            
	    	return 0;
	   //===================
	    default:    
	    	cout<<"You should enter a number from 1 to 8"<<endl;
	    	getch();
	    	break;
    }
  }
}



student* add(student *end, const student& newStudent)
{      
	student *newElement = new student;
    *newElement = newStudent;
    newElement->next = NULL;
    end->next = newElement;
    end = newElement;
   	return end;
}



student* addFirst(const student& newStudent)
{   
	student *beg = new student;
    *beg = newStudent;
	beg->next = NULL;
    return beg;
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
		} else {
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
		} else {
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
		} else {
			isCorrect = true;
		}
	}

    return newStudent;
}



int menu()  {
    char buf[10];
    int item;
    do {  
		system("cls");
      	cout << endl;
      	cout << "--------------- M E N U ---------------" << endl << endl;
	    cout << " 1 - Add new student" << endl;
	    cout << " 2 - View all students" << endl;
	    cout << " 3 - Write info to file" << endl;
	    cout << " 4 - Read info from file" << endl;
	    cout << " 5 - Delete all students" << endl;
	    cout << " 6 - Search two students with the same name" << endl;
	    cout << " 7 - Search the subject with the least triples" << endl;
	    cout << " 8 - EXIT" << endl;
	    cout << "---------------------------------------" << endl;
	    cout << "Enter the number:" << endl;
	
	    cin >> buf;
	    item = atoi(buf);

	    if (!item) {
	        cout << "You should enter the number from 1 to 8" << endl;
	        getch();
	    }

      } while(!item);
      return item;
}



void print(const student&student1)
{   
	cout << "|" << setw(3) << student1.number << "|" << setw(11) <<student1.name << "|";
	cout << setw(11) << student1.grade.physics;
	cout << "|" <<setw(11) << student1.grade.history << "|";
	cout << setw(11) << student1.grade.math << "|" << endl;
}



void view(student *beg)
{   
	if (!beg) { 
		cout << "The list is empty" << endl; 
		return; 
	}
	
    student* temp = beg;
    cout << "-----------------------------------------------------" << endl;
	cout << "| N |  Name     |  Physics  |  History  |Math       |" << endl;
    cout << "-----------------------------------------------------" << endl;
     
	while(temp) {
    	print(*temp);
        temp = temp->next;
    }
    cout << "-----------------------------------------------------" << endl;
}



int readFile(char* filename, student** beg, student** end) {    
	ifstream fin(filename, ios::in);
    if (!fin) {  
		cout << "File was not found " << filename << endl; 
		return 1;
	}
	
    student student1;
    *beg=0;

    while (fin >> student1.number) {
		fin >> student1.name;
        fin >> student1.grade.physics;
        fin >> student1.grade.history;
	    fin >> student1.grade.math;
        fin.get();

        if (*beg) {
			*end = add(*end, student1);
		} else {  
			*beg = addFirst(student1);  
            *end = *beg;  
		}
	}

    puts("Reading from file is competed");
    puts("To continue, press any key");
    getch();
	return 0;
}



int  writeFile(char* filename, student* temp) {  
	ofstream fout(filename);
   	if(!fout) {
	    cout<<"Error in opening file"<<endl;
		return 1;
	}

   	while(temp) {   
   		fout << temp->number << endl;
       	fout << temp->name << endl;
       	fout << temp->grade.physics << endl;
       	fout << temp->grade.history << endl;
       	fout << temp->grade.math << endl;

		temp = temp->next;
    }

   	return 0;
}




int deleteAllElements(char* filename, student** beg, student** end) {

	student* buf;
  	student* temp = *beg;
  	while (temp) {
    	buf = temp;
        temp = temp->next;
        *beg = temp;
        delete buf;
    }
    beg = end = NULL;

	puts("All students are deleted from list");
	puts("To continue, press any key");
	getch();
	
	return 0;
}



int searchSubjectWithMinNumberOf3(student*beg) {
 	student*temp=beg;

	int numberOf3InPhysics = 0,  
	    numberOf3InHistory = 0,  
	    numberOf3InMath = 0;     

  	while (temp)  {
	   	if (temp->grade.physics == 3) ++numberOf3InPhysics;
	   	if (temp->grade.history == 3) ++numberOf3InHistory;
	   	if (temp->grade.math == 3) ++numberOf3InMath;
	   	temp=temp->next;
  	}

 	puts("The subject that has the least triples:\n");

 	if((numberOf3InPhysics < numberOf3InHistory) && (numberOf3InPhysics < numberOf3InMath))
    	cout << "Physics" << endl << endl;

 	if ((numberOf3InHistory < numberOf3InPhysics) && (numberOf3InHistory < numberOf3InMath))
    	cout << "History" << endl << endl;

 	if ((numberOf3InMath < numberOf3InPhysics) && (numberOf3InMath < numberOf3InHistory))
    	cout<<"Math"<<endl<<endl;

	if (numberOf3InPhysics == numberOf3InHistory)  {
	    if (numberOf3InHistory == numberOf3InMath)
	    	cout << "the same number of triples in all subjects: " << numberOf3InPhysics << endl << endl;
	    else if (numberOf3InPhysics < numberOf3InMath)
		        cout << "Physics and History" << endl << endl;
	} else if ((numberOf3InPhysics == numberOf3InMath) && (numberOf3InMath < numberOf3InHistory))
		cout << "Math and Physics" << endl << endl;
	
	if ((numberOf3InHistory == numberOf3InMath) && (numberOf3InMath < numberOf3InPhysics))
	    cout << "Math and History" << endl << endl;
	
	puts("To continue, press any key\n");
	getch();
	return 0;
}

bool isEquals(char* name1, char* name2) {
	for (int i = 0; i < nameLength; i++) {
		if (name1[i] != name2[i]) {
			return false;
		}
	}
	return true;
}

void searchStudentsWithSameName(student* beg) {
	student* temp = beg;
	student* buf;

	bool isFound = false;

  	while (temp)  {
  		buf = temp->next;
	   	while (buf) {
	   		if (isEquals(temp->name, buf->name)) {
		   		cout << "There are 2 students with name " << buf->name 
				   << " (N " << temp->number << " and N " << buf->number << ")" << endl;
				isFound = true;
			}
	   		buf = buf->next;
		}
	   	temp = temp->next;
  	}	
  	
  	if (!isFound) {
  		cout << "There are no students with the same name." << endl;
	  }
}

