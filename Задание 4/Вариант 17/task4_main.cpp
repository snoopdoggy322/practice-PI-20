#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#define s(a) (int)a.size()
 
bool bigger(std::vector<int>b, std::vector<int>a){
    if(s(a) > s(b))
        return false;
    else if(s(a) < s(b))
        return true;
    else{
        for(int i=s(a)-1;i>=0;i--){
            if(a[i] > b[i])
                return false;
            else if(b[i] > a[i])
                return true;
        }
    }
return false;
}
 
int main()
{
  std::string f;
  std::cin >> f;
  std::vector<int>a(s(f));
  int k = 0;
  for(int i=s(f)-1;i>=0;i--){
    a[k] = f[i] - 48;
    k++;
  }
  std::string se;
  std::cin >> se;
  std::vector<int>b(s(se));
  k = 0;
  for(int i=s(se)-1;i>=0;i--){
    b[k] = se[i] - 48;
    k++;
  }
  // Само вычитание
  bool minus = false;
  if(bigger(b, a)){
    std::swap(a, b);
    minus = true;
    }
  int rem = 0;
  for(int i=0;i<s(a) || rem != 0;i++){
    a[i] = a[i] - ( i < s(b) ? (b[i] + rem) : rem);
    rem = 0;
    if(a[i] < 0){
        rem++;
        a[i]+=10;
    }
  }
  while(s(a) > 1 && a.back() == 0){
    a.pop_back();
  }
  if(minus){
    printf("-");
  }
  for(int i=s(a)-1;i>=0;i--){
    printf("%d", a[i]);
  }
}
