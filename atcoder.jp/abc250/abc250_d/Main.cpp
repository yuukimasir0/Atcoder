#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, q;
ll const MAX = 793701;

int main(){
  cin >> n;
  map<ll, ll> prime;
  prime[2] = 2;
  for(ll i = 3; i < MAX; i++){
    bool check = true;
    for(auto j : prime){
      if(i % j.second == 0){
        check = false;
        break;
      }
      if(j.second * j.second > i)
        break;
    }
    if(check)
      prime[i] = i;
  }
  ll ans = 0;
  
  for(auto i : prime){
    for(auto j : prime){
      if(j.second >= i.second || i.second * i.second * i.second * j.second > n)
        break;
        ans++;
    }
    if(i.second * i.second * i.second > n / 2)
      break;
  }
  cout << ans << endl;
}