#include "string"

using namespace std;

class Student{
    string surname;
    int math;
    int physics;
    int history;
    double avg;

public:
    Student(string surname="", int math = 0, int physics = 0, int history = 0){
        this->surname = surname;
        this->math = math;
        this->physics = physics;
        this->history = history;
    }

    ~Student(){};

    double getAvg(){
        return (this->math + this->physics + this->history)/3;
    }

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
};
