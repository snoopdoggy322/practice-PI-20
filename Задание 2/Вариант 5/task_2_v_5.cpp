#include <iostream>
using namespace std;



struct Time
{   int hours;
    int minutes;
    int seconds;
};

Time* addOneSecond(Time* myTime);

int main(int argc, char** argv) {
	
	int hours = 0, minutes = 0, seconds = 0;
	
	Time* myTime = new Time;
	cout << "Enter the time" << endl;
	cout << "Hours: ";
	cin >> hours;
	if (hours < 0 || hours > 23) {
		cout << "Wrong input" << endl;
		return -1;
	}
	
	cout << "Minutes: ";
	cin >> minutes;
	if (minutes < 0 || minutes > 59) {
		cout << "Wrong input" << endl;
		return -1;
	}
	
	cout << "Seconds: ";
	cin >> seconds;
	if (seconds < 0 || seconds > 59) {
		cout << "Wrong input" << endl;
		return -1;
	}
	
	myTime->hours = hours;
	myTime->minutes = minutes;
	myTime->seconds = seconds;
	
	Time* newTime = addOneSecond(myTime);
	cout << "New time -  " << newTime->hours << ":" << newTime->minutes << ":" << newTime->seconds << endl;	
	
	return 0;
}

Time* addOneSecond(Time* myTime) {
	
	Time* newTime = new Time;
	newTime->seconds = myTime->seconds + 1;
	
	if (newTime->seconds < 60) {
		newTime->hours = myTime->hours;
		newTime->minutes = myTime->minutes;
	} else {
		newTime->seconds = 0;
		newTime->minutes = myTime->minutes + 1;
		newTime->hours = myTime->hours;
		
		if (newTime->minutes > 59) {
			newTime->minutes = 0;
			newTime->hours++;
		}	
		
		if (newTime->hours > 23) {
				newTime->hours = 0;
			}
	}
	
	return newTime;
}
