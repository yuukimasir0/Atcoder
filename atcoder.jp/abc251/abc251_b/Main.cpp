#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, w;
ll a[309];

int main() {
  cin >> n >> w;
  map<ll, ll> mp;
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i] <= w)
 	   mp[a[i]] = a[i];
  }
  for(ll i = 0; i < n; i++)
    for(ll j = i; j < n; j++)
      if(i != j && a[i] + a[j] <= w)
        mp[a[i] + a[j]] = a[i] + a[j];
  for(ll i = 0; i < n; i++)
    for(ll j = i; j < n; j++)
      for(ll k = j; k < n; k++)
        if(i != j && j != k && k != i && a[i] + a[j] + a[k] <= w)
          mp[a[i] + a[j] + a[k]] = a[i] + a[j] + a[k];
  cout << mp.size() << endl;
}