#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
       int n;
    cout<<"n:";
    cin>>n;
    string s="1";
    for(int i=0; i<n; i++)
    {
        int x=0;
        for(int k=s.length()-1; k>=0; k--)
        {
            x+=(s[k]-'0')*3;
            s[k]=x%10+'0';
            x/=10;
        }
        if(x) s=char(x+'0')+s;
    }
    cout<<s<<endl;
}

