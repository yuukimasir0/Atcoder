#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

int main(){
  cin >> s;
  map<char, bool> mp;
  for(ll i = 0; i < s.length(); i++){
    if(!mp[s[i]])
      mp[s[i]]= true;
    else{
      cout << "No" << endl;
      return 0;
    }
  }
  string check = "qazwsxedcrfvtgbyhnujmiklop";
  string check2 = "QAZWSXEDCRFVTGBYHNUJMIKOLP";
  bool can = false;
  for(ll i = 0; i < s.length(); i++){
    for(ll j = 0 ; j < check.length(); j++)
      if(s[i] == check[j]){
        can = true;
        break;
      }
    if(can)
      break;
  }
  if(!can){
    cout << "No" << endl;
    return 0;
  }
  can = false;
    for(ll i = 0; i < s.length(); i++){
    for(ll j = 0 ; j < check2.length(); j++)
      if(s[i] == check2[j]){
        can = true;
        break;
      }
    if(can)
      break;
  }
  if(!can)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}