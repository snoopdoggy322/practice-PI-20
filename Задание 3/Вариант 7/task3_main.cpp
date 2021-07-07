#include <stdio.h>
#include <iostream>
#include <iomanip>


using namespace std;

struct student {
    int id;
    string name;
    int math;
    int history;
    int physics;
};

struct list_t {
    student data;
    list_t *next;
};

const int size_d = sizeof(student);
list_t *head,*tail;


// Ввод данных с клавиатуры
void input(student *data) {
    cout << "Number:" << endl;
    cin >> data->id;
    
    cout << "Name:" << endl;
    cin >> data->name;
    cout << "math:" << endl;
    cin >> data->math;
    cout << "history:" << endl;
    cin >> data->history;
    cout << "physics:" << endl;
    cin >> data->physics;
    cin.get();
}
// Добавить элемент в хвост
void add_tail() {
    list_t *tmp = new list_t;
    input(&tmp->data);
    tmp->next = NULL;
    if(tail == NULL) {
        head = tail = tmp;
    } else {
        tail->next = tmp;
        tail = tmp;
    }
}
// Добавить элемент в голову
void add_head() {
    list_t *tmp = new list_t;
    input(&tmp->data);
    tmp->next = head;
    if(head == NULL) {
        head = tail = tmp;
    } else {
        head = tmp;
    }
}
// Организация очереди
void organize() {
    char c;
    do {
        add_tail();
        cout << "Continue oranization? (y/n): ";
        cin >> c;
        cin.get();
    } while(c == 'y');
}
// Удаление с головы
void pull() {
    if(head == NULL) {
        cout << "Queue is empty" << endl;
    } else {
        list_t *tmp = head;
        head = head->next;
        if(head == NULL) {
            tail = NULL;
        }
        delete tmp;
        cout << "Student removed" << endl;
    }
    cout << "Press enter to continue..." << endl;
    cin.get();
}
// Печать очереди
void show() {
    if(head == NULL) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "+---+------------+------------+-----------+-----------+" << endl;
        cout << "| # |    Namr    |     Math     | History |  Physics  |" << endl;
        cout.precision(2);
        list_t *tmp = head;
        while(tmp != NULL) {
            cout << "+---+------------+------------+-----------+-----------+" << endl;
            cout << "|" << setw(3) << tmp->data.id << "|" << setw(12) << tmp->data.name << "|" << setw(12) << tmp->data.math << "|" << setw(11) << tmp->data.history << "|" << setw(11) << tmp->data.physics << "|"  << endl;
            tmp = tmp->next;
        }
        cout << "+---+------------+------------+-----------+-----------+" << endl;
    }
    cout << "Press enter to continue..." << endl;
    cin.get();
}

void swap() {
    if(head == NULL) {
        cout << "Queue is empty" << endl;
    } else {
      
    }
    cout << "Press enter to continue..." << endl;
    cin.get();
}
void best() {
    if(head == NULL) {
        cout << "Queue is empty" << endl;
    } else {
        list_t *tmp = head;
        while(tmp != NULL) {
            if((tmp->data.history+tmp->data.math+tmp->data.physics)/3>=4.5){
                cout<<tmp->data.name<<endl;
            }
            tmp = tmp->next;
        }
    }
    cout << "Press enter to continue..." << endl;
    cin.get();
}
void remove(int val) {
    //if (is_empty()) return;
    if (head->data.id == val) {
        pull();
        return;
    }
    else if (tail->data.id == val) {
        pull();
        return;
    }
    list_t* slow = head;
    list_t* fast = head->next;
    while (fast && fast->data.id != val) {
        fast = fast->next;
        slow = slow->next;
    }
    if (!fast) {
        cout << "This element does not exist" << endl;
        return;
    }
    slow->next = fast->next;
    delete fast;
}
void deletePath() {
    if(head == NULL) {
        cout << "Queue is empty" << endl;
    } else {
        list_t *tmp = head;
        while(tmp != NULL) {
            if(tmp->data.id<8){
                remove(tmp->data.id);
            }
            tmp = tmp->next;
        }
    }
    cout << "Press enter to continue..." << endl;
    cin.get();
}

int main(int argc, char** argv) {

    char c;
    while(1) {
        cout << "1 - Organize" << endl;
        cout << "2 - Add in tail" << endl;
        cout << "3 - Add in head" << endl;
        cout << "4 - Pull" << endl;
        cout << "5 - Show" << endl;
        cout << "6 - 7" << endl;
        cout << "7 - 17" << endl;
        cout << "8 - 20" << endl;
        cout << "9 - Exit" << endl;
        cout << "Choose your destiny: ";
        cin >> c;
        cin.get();
        switch(c) {
            case '1':
                organize();
                break;
            case '2':
                add_tail();
                break;
            case '3':
                add_head();
                break;
            case '4':
                pull();
                break;
            case '5':
                swap();
                break;
                case '6':
                best();
                break;
                case '7':
                deletePath();
                break;
            case '9':
                return 0;
        }
    }
    return 0;
}
