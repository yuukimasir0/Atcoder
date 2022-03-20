#include <bits/stdc++.h>
using namespace std;

string s[3], t[3];

int main(){
  int counter = 0;
  for(int i = 0; i < 3; i++)
    cin >> s[i];
  for(int i = 0; i < 3; i++)
    cin >> t[i];
  
  for(int i = 0; i < 3; i++)
    if(s[i] == t[i])
      counter++;
  if(counter == 1)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}