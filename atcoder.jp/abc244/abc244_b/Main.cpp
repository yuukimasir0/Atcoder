#include <bits/stdc++.h>
using namespace std;

int n;
string t;

int main(){
  cin >> n >>t;
  int x = 0, y = 0;
  int dire = 0;
  for(int i = 0; i < n; i++)
    if(t[i] == 'R')
      dire++;
    else{
      if(dire % 4 == 0)
        x++;
      else if(dire % 4 == 1)
        y--;
      else if(dire % 4 == 2)
        x--;
      else
        y++;
    }
  cout << x << " " << y << endl;
}