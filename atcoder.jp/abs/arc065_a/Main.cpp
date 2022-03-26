#include <bits/stdc++.h>
using namespace std;
string s;

int main(){
  string check[4] = {"dream", "dreamer", "erase", "eraser"};
  for(int i = 0; i < 4; i++)
    reverse(check[i].begin(), check[i].end());
  cin >> s;
  reverse(s.begin(), s.end());
  for(int i = 0; i < s.size(); i++){
    bool cando = false;
    for(int j = 0; j < 4; j++){
      if(s.compare(i,check[j].size(), check[j]) == 0){
        i += check[j].size() - 1;
        cando = true;
      }
    }
    if(!cando){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}