#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll s, temp;
bool check[10];

int main(){
cin >> s;
for(ll i = 0; i <= 9; i++){
  temp = s % 10;
  check[temp] = true;
  s /= 10;
}
for(ll i = 0; i <= 9; i++){
  if(!check[i]){
    cout << i << endl;
    return 0;
  }
}
  cout << 0 << endl;
}