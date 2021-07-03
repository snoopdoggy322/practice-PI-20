#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int i, j, size = 5000;
	char str[size];
	printf("Input your text: ");
	gets(str);
	printf("The initial text is \n%s", str);
	for (i=0;i<size;i++)
		if(str[i]=='!'){
			for(j=strlen(str);j>i;j--)			
				str[j+1]=str[j];
			for(j=strlen(str);j>i;j--)			
				str[j+1]=str[j];
			str[i]='.';
			str[i+1]='.';
			str[i+2]='.';
		}
	printf("\nThe final text is \n%s", str);
}
