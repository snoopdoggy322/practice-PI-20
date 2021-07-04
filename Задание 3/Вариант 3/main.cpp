//
//  main.cpp
//  Practice
//
//  Created by Emin Bari on 29.06.2021.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class myexception: public exception
{
    virtual const char* what() const throw()
    {
        return "Exception happened";
    }
} myexception;

class Student{
    string surname;
    int math;
    int physics;
    int history;

public:
    Student(string surname="", int math = 0, int physics = 0, int history = 0){
        this->surname = surname;
        this->math = math;
        this->physics = physics;
        this->history = history;
    }

    ~Student(){};

    string getSurname(){
        return this->surname;;
    }

    int getMathMark(){
        return this->math;
    }

    int getPhysicsMark(){
        return this->physics;
    }

    int getHistoryMark(){
        return this->history;
    }

    void setMathMark(int mark){
        this->math = mark;
    }

    void setPhysicsMark(int mark){
        this->physics = mark;
    }

    void setHistoryMark(int mark){
        this->history = mark;
    }
};
//

template<typename T>
class List{
private:
    template<typename NT>
    class Node{
    public:
        Node *pNext;
        NT data;
        Node(T data = T(), Node *pNext = nullptr){
            this->data = data;
            this->pNext = pNext;
        }
    };

    int size;
    Node<T> *head;

public:
    List();
    ~List();

    void pop_front();
    void clear();
    void push_back(T data);
    void push_front(T data);
    void insert(T data, int index);
    void removeAt(int index);
    void pop_back();

    ///search
    T& search(string surname);

    int getSize(){
        return size;
    }

    T& operator[](const int index);

    void searchAndEdit();
};
//

template<typename T>
List<T>::List(){
    size = 0;
    head = nullptr;
};

template<typename T>
List<T>::~List(){
    clear();
};


template<typename T>
void List<T>::pop_front(){
    Node<T> *tmp = head;
    head = head->pNext;
    delete tmp;
    size--;
}

template<typename T>
void List<T>::clear(){
    while (size) {
        pop_front();
    }
}

template<typename T>
void List<T>::push_back(T data){
    if (head == nullptr) {
        head = new Node<T>(data);
    } else{
        Node<T> *current = this->head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }

    size++;
}

template<typename T>
void List<T>::push_front(T data){
    head = new Node<T>(data, head);
    size++;
}

template<typename T>
void List<T>::insert(T data, int index){

    if (index == 0) {
        push_front(data);
    } else {
        Node<T> *previous = this->head;
        for (int i=0; i<index-1; i++) {
            previous = previous->pNext;
        }

        Node<T> *newNode = new Node<T>(data, previous->pNext);
        previous->pNext = newNode;

        size++;
    }

}

template<typename T>
void List<T>::removeAt(int index){

    if (index == 0) {
        pop_front();
    } else {
        Node<T> *previous = this->head;
        for (int i=0; i<index-1; i++) {
            previous = previous->pNext;
        }

        Node<T> *toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;

        size--;
    }

}

template<typename T>
void List<T>::pop_back(){
    removeAt(size-1);
}

template<typename T>
T & List<T>::operator[](const int index){
    int counter = 0;
    Node<T> *current = this->head;

    while (current != nullptr) {
        if (counter == index) {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }

}


template <typename T>
T & List<T>::search(string surname){
    Node<T>* current = this->head;
    while(current != nullptr) {
        Student student = current->data;
        if(student.getSurname() == surname) return current->data;
        current = current->pNext;
    }
    throw myexception;
}


void DisplayMainMenu()
{
    cout << "---Main Menu---\n";
    cout << "Please make your selection\n";
    cout << "1 - Add new data\n";
    cout << "2 - Show table\n";
    cout << "3 - Save data to the file\n";
    cout << "4 - Load data from the file\n";
    cout << "5 - Найти и отредактировать\n";
    cout << "6 - Clear all data\n";
    cout << "0 - Quit\n";
    cout << "Select menu [0-6]: ";
}

void addNewStudent(List<Student> &lst) {
    string surname;
    int mathMark;
    int physicsMark;
    int historyMark;

    cout<<" New student"<<endl;
    cout<<"Student's surname: ";
    cin>>surname;
    cout<<endl<<"Math mark: ";
    cin>>mathMark;
    cout<<endl<<"Physics mark: ";
    cin>>physicsMark;
    cout<<endl<<"History mark: ";
    cin>>historyMark;
    cout<<endl<<"Done!";

    Student newStudent = *new Student(surname, mathMark, physicsMark, historyMark);
    lst.push_back(newStudent);
}

void showListData(List<Student> &lst) {
    cout <<left;
    cout <<setw(2) <<"No"<<setw(8)<< "|"<<setw(20) << "Surname" << setw(13)<< "|" << setw(10)<<"Marks"<<'\n' <<
         setw(30) << "--|--------------------------" << setw(10) << "| Math " << setw(10) << "| Physics " << setw(10) << "| Physics" << '\n';

    for (int i = 0; i < lst.getSize(); ++i) {
        cout <<setw(2)<<i<<setw(8)<<"|"<<setw(20) <<lst[i].getSurname()<< setw(5) << "|" <<setw(5) <<lst[i].getMathMark()<< setw(5) << "| "<<setw(5)<<lst[i].getPhysicsMark()<< setw(5) << "| "<<setw(5)<<lst[i].getHistoryMark()<< '\n';
    }
}

void saveToFile(List<Student> &lst){
    string path = "file.txt";
    fstream fs;
    fs.open(path, fstream::in | fstream::out);

    if (!fs.is_open()){
        cout<<"Error"<<endl;

    } else{
        for (int i = 0; i < lst.getSize(); ++i) {
            fs<<lst[i].getSurname()<<","<<lst[i].getMathMark()<<","<<lst[i].getPhysicsMark()<<","<<lst[i].getHistoryMark()<<"\n";
        }
    }
    fs.close();
}

void readFile(List<Student> &lst){

    ifstream fs ("file.txt");

    string line;
    char surname[100];
    int mathMark;
    int physicsMark;
    int historyMark;
    Student newStudent;

    if (fs.is_open())
    {
        while ( getline (fs,line) )
        {
            sscanf(line.c_str(), "%[^,],%i,%i,%i", surname, &mathMark,&physicsMark, &historyMark);

            newStudent = *new Student(surname, mathMark, physicsMark, historyMark);
            lst.push_back(newStudent);
        }
        fs.close();
    }
    else cout << "Unable to open file";
}


template<typename T>
void List<T>::searchAndEdit(){
    string surname;

    int mathMark;
    int physicsMark;
    int historyMark;

    try {
        cout<<"Search by surname:"<<endl;
        cin>>surname;

        Node<T>* current = this->head;
        while(current != nullptr) {
            Student *student = &current->data;
            if(student->getSurname() == surname){

                cout<<"Студент "<<student->getSurname()<<" найден."<<endl;
                cout<<"Математика: "<<student->getMathMark()<<endl<<"Физика: "<<student->getPhysicsMark()<<endl<<"История: "<< student->getHistoryMark()<<endl;
                cout<<"Введите новые значения оценок: "<<endl;
                cout<<"Math mark: ";
                cin>>mathMark;
                cout<<endl<<"Physics mark: ";
                cin>>physicsMark;
                cout<<endl<<"History mark: ";
                cin>>historyMark;

                student->setMathMark(mathMark);
                student->setPhysicsMark(physicsMark);
                student->setHistoryMark(historyMark);

                cout<<endl<<"Done!";
            }
            current = current->pNext;
        }
        throw myexception;




    }
    catch (exception& e){
        cout << "Can't find "<<surname<<" student" << '\n';
    }

}

int main(int argc, const char * argv[]) {

    setlocale(LC_ALL, "ru");
    List<Student> lst;
    int i;

    do {
        DisplayMainMenu();
        cin >> i;

        switch (i) {
            case 0:
                return 0;
            case 1:
                addNewStudent(lst);
                break;
            case 2:
                showListData(lst);
                break;
            case 3:
                saveToFile(lst);
                break;
            case 4:
                readFile(lst);
                break;
            case 5:
                lst.searchAndEdit();
                break;
            case 6:
                lst.clear();
                break;
        }
    } while (i != 0);
    return 0;
}
