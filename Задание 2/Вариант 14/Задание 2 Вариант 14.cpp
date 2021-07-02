#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

struct Date{
	int day,month,year;
};
 
struct Date * convert(int inputdate)
{
	if(inputdate - (inputdate % 1000000)<=0)
		return NULL;
	struct Date d = Date{0,0,0};
	struct Date * date = &d;
    date->day = inputdate / 1000000;
    inputdate -= inputdate / 1000000* 1000000;
    date->month = inputdate/ 10000;
    inputdate-= inputdate / 10000* 10000;
    date->year = inputdate;
    if(date->day>27&&date->month==2)
		return NULL;
    if(date->day>31||date->month>12)
		return NULL;
    return date;
}

int main()
{
    int inputdate;
 
    setlocale(LC_CTYPE, "rus");
 	struct Date * date;
    printf("Ââåäèòå äàòó â ôîğìàòå ÄÄÌÌÃÃÃÃ: "); 
    scanf("%d", &inputdate);
    
    date = convert(inputdate);
 
 	if(date==NULL)
 		printf("Îøèáêà! Íåïğàâèëüíûé ôîğìàò!");
 	else
    	printf("Äåíü:%d Ìåñÿö:%d Ãîä:%d", date->day, date->month, date->year);
 
    return 0;
}

