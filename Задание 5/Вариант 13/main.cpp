
#include <iostream>
#include <iomanip>
#include <fstream>

#include "student.cpp"
#include "trunk.cpp"

using namespace std;

///BinaryTreeClass
template<typename T>
class BinaryTree{

private:
    template<typename NT>
    class Node{
    public:
        Node *left;
        Node *right;
        NT data;
        Node(T data = T(), Node *left = nullptr, Node *right = nullptr){
            this->data = data;
            this->left = left;
            this->right = right;
        }
    };

    int size;
    int allChildNodesCount;
    Node<T> *root;

    void showTrunks(Trunk *p);

    void placeNode(Node<T> *current, T newData);

    void printTreeRecursively(Node<T> *root, Trunk *prev, bool isLeft);

    void printTableRecursively(Node<T> *root);

    void saveTreeToFileRecursively(Node<T> *root, fstream &fs);

    void printAllChildNodesRecursively(Node<T> *node);

    void clearTreeRecursively(Node<T>* &node);

public:
    BinaryTree();
    ~BinaryTree();

    void addNode(T data);

    void printTable();

    void printTree();

    void clearTree();

    void saveTreeToFile();

    void printAllChildNodes();

    int getSingleChildNodesCount();
};



template<typename T>
int BinaryTree<T>::getSingleChildNodesCount(){
    return allChildNodesCount;
}

template<typename T>
void BinaryTree<T>::placeNode(Node<T> *current, T newData){

    Student currentData = current->data;

    double avgMarksValueCurrent = currentData.getAvg();
    double avgMarksValueNew = newData.getAvg();

    if(avgMarksValueNew < avgMarksValueCurrent){
        if (current->left != nullptr) {
            current = current->left;
            placeNode(current, newData);
        }else {
            current->left = new Node<T>(newData);
        }
    } else {
        if (current->right != nullptr) {
            current = current->right;
            placeNode(current, newData);
        }else {
            current->right = new Node<T>(newData);
        }
    }
}

template<typename T>
BinaryTree<T>::BinaryTree(){
    size = 0;
    root = nullptr;
};

template<typename T>
BinaryTree<T>::~BinaryTree(){
    clearTreeRecursively(root);
};

template<typename T>
void BinaryTree<T>::addNode(T data){
    if (root == nullptr) {
        root = new Node<T>(data);
    } else{
        Node<T> *current = this->root;
        placeNode(current, data);
    }
}

template<typename T>
void BinaryTree<T>::showTrunks(Trunk *p){
    if (p == nullptr) {
        return;
    }
    showTrunks(p->prev);
    cout << p->str;
}

template<typename T>
void BinaryTree<T>::printTreeRecursively(Node<T> *root, Trunk *prev, bool isLeft){
    if (root == nullptr) {
        return;
    }

    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTreeRecursively(root->right, trunk, true);

    if (!prev) {
        trunk->str = "—————";
    }
    else if (isLeft)
    {
        trunk->str = "┌────";

        prev_str = "    |";
    }
    else {
        trunk->str = "└────";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    Student st = root->data;
    cout << st.getSurname() <<" ("<< st.getAvg() <<")"<< endl;

    if (prev) {
        prev->str = prev_str;
    }
    trunk->str = "    |";

    printTreeRecursively(root->left, trunk, false);
}

template<typename T>
void BinaryTree<T>::printTree(){
    if (root == nullptr) {
        cout<<"Tree is not exists!"<<endl;
    } else {
        printTreeRecursively(root, nullptr, false);
    }
}

template<typename T>
void BinaryTree<T>::printTableRecursively(Node<T> *node){
    if (node == nullptr) return;

    Student st = node->data;
    cout <<setw(8)<<"|"<<setw(20) <<st.getSurname()<< setw(5) << "|" <<setw(5) <<st.getMathMark()<< setw(5) << "| "<<setw(5)<<st.getPhysicsMark()<< setw(5) << "| "<<setw(5)<<st.getHistoryMark()<< '\n';
    printTableRecursively(node->left);
    printTableRecursively(node->right);
}

template<typename T>
void BinaryTree<T>::printTable() {
    if (root == nullptr) {
        cout<<"Tree is not exists!"<<endl;
    }
    else {
        cout<<left;
        cout <<setw(8)<< "|"<<setw(20) << "Surname" << setw(13)<< "|" << setw(10)<<"Marks"<<'\n' <<
             setw(28) << "|---------------------------" << setw(10) << "| Math " << setw(10) << "| Physics " << setw(10) << "| Physics" << '\n';
        printTableRecursively(root);
    }
}

template<typename T>
void BinaryTree<T>::clearTreeRecursively(Node<T>* &node){
    if (node == nullptr) return;
    clearTreeRecursively(node->left);
    clearTreeRecursively(node->right);
    Student st = node->data;
    cout << "Deleting node: " << st.getSurname()<<endl;
    delete node;
    node = nullptr;
}

template<typename T>
void BinaryTree<T>::clearTree(){
    clearTreeRecursively(root);
    cout<<endl;
}

template<typename T>
void BinaryTree<T>::saveTreeToFileRecursively(Node<T> *node, fstream& fs){
    if (node == nullptr) return;

    Student st = node->data;

    if (!fs.is_open()){
        cout<<"Unable to open file"<<endl;
    } else{
        fs<<st.getSurname()<<","<<st.getMathMark()<<","<<st.getPhysicsMark()<<","<<st.getHistoryMark()<<"\n";
    }

    saveTreeToFileRecursively(node->left, fs);
    saveTreeToFileRecursively(node->right, fs);
}

template<typename T>
void BinaryTree<T>::saveTreeToFile(){
    string path = "file.txt";
    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);

    saveTreeToFileRecursively(root, fs);

    fs.close();
}

template<typename T>
void BinaryTree<T>::printAllChildNodesRecursively(Node<T> *node) {

    if (node == nullptr) return;

    if (node->left != nullptr && node->right != nullptr){
        Student st = node->data;
        cout<<st.getSurname()<<endl;
        allChildNodesCount++;
    }
    printAllChildNodesRecursively(node->left);
    printAllChildNodesRecursively(node->right);

}

template<typename T>
void BinaryTree<T>::printAllChildNodes(){
    allChildNodesCount = 0;
    printAllChildNodesRecursively(root);
    cout << "Количество узлов имеещих два потомка " << allChildNodesCount << endl;
}

///////////////////////////////////////////////////

void loadDataFromFile(BinaryTree<Student> &lst){

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
            lst.addNode(newStudent);
        }
        fs.close();
    }
    else cout << "Unable to open file";
}

///MENU
void DisplayMainMenu(){
    cout << "---Main Menu---\n";
    cout << "Please make your selection\n";
    cout << "1 - Add new data\n";
    cout << "2 - Show table\n";
    cout << "3 - Show tree\n";
    cout << "4 - Save data to the file\n";
    cout << "5 - Load data from the file\n";
    cout << "6 - Clear all data\n";
    cout << "7 - Узлы имеющие два потомка\n";
    cout << "0 - Quit\n";
    cout << "Select menu [0-7]: ";
}

///Add new node
void addNewStudent(BinaryTree<Student> &lst) {
    string surname;
    int mathMark;
    int physicsMark;
    int historyMark;

    cout<<" New student"<<endl;
    cout<<"Student's surname: ";
    cin>>surname;
    cout<<"Math mark: ";
    cin>>mathMark;
    cout<<"Physics mark: ";
    cin>>physicsMark;
    cout<<"History mark: ";
    cin>>historyMark;
    cout<<"Done!"<<endl<<endl;

    Student newStudent = *new Student(surname, mathMark, physicsMark, historyMark);
    lst.addNode(newStudent);
}


int main() {
    Student newStudent;
    BinaryTree<Student> lst;

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
                lst.printTable();
                break;
            case 3:
                lst.printTree();
                break;
            case 4:
                lst.saveTreeToFile();
                break;
            case 5:
                loadDataFromFile(lst);
                break;
            case 6:
                lst.clearTree();
                break;
            case 7:
                lst.printAllChildNodes();
                break;
        }
    } while (i != 0);
}

