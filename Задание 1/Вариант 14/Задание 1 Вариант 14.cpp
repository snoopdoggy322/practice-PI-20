#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int i, j, size = 5000;
	char str[size];
	for (i=0;i<size;i++)
		str[i]=' ';
	printf("Введите текст: ");
	gets(str);
	int count1=0,count2=0,count3=0;
	for (i=0;i<size;i++){
		if(str[i]=='[')
			count1++;
		if(str[i]=='{')
			count2++;
		if(str[i]=='(')
			count3++;
		if(str[i]==']')
			count1--;
		if(str[i]=='}')
			count2--;
		if(str[i]==')')
			count3--;
	}
	if(count1==0&&count2==0&&count3==0)
		printf("\nСбалансировано");
	else
		printf("\nНе сбалансировано");
}
