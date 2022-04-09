#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll temp;
map<ll, bool> check;

int main(){
  ll ans = 0;
  cin >> n;
  for(ll i = 0; i < n; i++){
    cin >> temp;
    if(!check[temp]){
      check[temp] = true;
      ans++;
    }else continue;
  }
  cout << ans << endl;
}
