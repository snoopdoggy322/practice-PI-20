#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(int argc, char** argv) { 
  int i=0,j=0,l=0;
 	char st[200];
  char ch=' ';
   cout<<" Введите текст:  ";   gets(st);  cout<<endl;
   string mins;
   int mn,bgmn,emn,tek;
  	mn=strlen(st);  bgmn=0;
     while (true)    {
         while ((st[j]!=ch) and (j<strlen(st)))   j++;
         tek=j-l;
         for (int i=l; i<j; i++)
         {  if (tek<mn)   {  mn=tek;  bgmn=l;  emn=j-1;   }          } 
        if (j==strlen(st)) break;
        j++;  l=j;
  	}
//запись строки
    for (int i=bgmn; i<=emn; i++)   mins=mins+st[i];
    cout<<"Короткое слово:  "<<mins<<endl<<endl;
    system("pause");
    return(0);
}
