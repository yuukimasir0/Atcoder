#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll const MAX = 200000;

int main(){
  ll ans = 0;
  cin >> n;
  vector<ll> a(MAX + 1);
  for(ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    a[x]++;
  }
  
  for(ll i = 1; i <= MAX; i++) {
    for(ll j = 1; i * j <= MAX; j++) {
      ans += a[i] * a[j] * a[i*j];
    }
  }
  cout << ans << endl;
}