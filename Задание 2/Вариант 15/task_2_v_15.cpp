#include <iostream>
using namespace std;


struct Time
{   int hours;
    int minutes;
    int seconds;
};

Time* addMinutes(Time* myTime, int minutes);

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
	
	int addingMinutes = 0;
	cout << "How many minutes do you want to add (max - 1440(1 day))? -  ";
	cin >> addingMinutes;
	if (minutes < 0 || minutes > 1440) {
		cout << "Wrong input" << endl;
		return -1;
	}
	
	Time* newTime = addMinutes(myTime, addingMinutes);
	cout << "New time -  " << newTime->hours << ":" << newTime->minutes << ":" << newTime->seconds << endl;	
	
	return 0;
}


Time* addMinutes(Time* myTime, int minutes) {
	Time* newTime = new Time;
	newTime->seconds = myTime->seconds;
	
	int addingHours = minutes / 60;
	int addingMinutes = minutes % 60;
	
	if (addingMinutes == 0){
		newTime->minutes = myTime->minutes;
		newTime->hours = myTime->hours + addingHours;	
	} else {
		newTime->minutes = myTime->minutes + addingMinutes;
		newTime->hours = myTime->hours + addingHours;
		if (newTime->minutes > 59) {
			newTime->hours += newTime->minutes / 60;
			newTime->minutes = newTime->minutes % 60;
		}
	}
	
	if (newTime->hours > 23) {
			newTime->hours = newTime->hours % 24;
		}
		
	return newTime;
}
