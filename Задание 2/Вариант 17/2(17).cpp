#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class DateTime{
 private:
    int year;
    int month;
    int day;
    int hour;
    int minutes;
    int seconds;
    
 public:   
    DateTime(int _year,int _month,int _day,int _hour,int _minutes,int _seconds){
       year=_year;
       month=_month;
       day=_day;
       hour=_hour;
       minutes=_minutes;
       seconds=_seconds;
    }
    
    long differenceInSeconds(DateTime secondDate){
        return seconds+(minutes*60)+(hour*60*60)+(day*24*60*60)+(month*30*24*60*60)+(year*365*24*60*60);
    }
    DateTime fromSeconds(long s){
        int year =s/60/60/24/365;
        s-=year;
        int month =s/30/24/60/60;
        s-=month;
        int day =s/24/60/60;
        s-=day;
        int hour =s/60/60;
        s-=hour;
        int minutes =s/60;
        s-=minutes;
        int seconds =s;
        s-=seconds;
        return DateTime(
            year,
            month,day,hour,minutes,seconds
            );
    }
};

int main()
{
     DateTime newYear = DateTime(2022,12,31,12,59,59);
    DateTime date = DateTime(2021,6,29,17,40,55);
     std::cout << DateTime.fromSeconds(date.differenceInSeconds(newYear)) << std::endl;
    return 0;
}
