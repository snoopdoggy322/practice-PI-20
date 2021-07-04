#include <stdio.h>
#include <iostream>
using namespace std;
 
void IncTime(int &,int &,int &,int );
int main()
{
    int hours, minutes, seconds;
    printf("Vvedite vremya:");
    scanf("%u %u %u", &hours, &minutes, &seconds);
    IncTime(hours,minutes,seconds,1);
    printf("%d:%d:%d",hours,minutes,seconds);
    return 0;
}
 
void IncTime(int &H,int &M,int &S,int T){
    int tm= 3600*H+60*M+S+3600;
    H = tm/3600;
    tm %= 3600;
    M = tm/60;
    S = tm%60;
}

