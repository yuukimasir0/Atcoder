#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll const MOD = 998244353;
ll a;

int main(){
  cin >> n;
  vector<vector<ll>> index(n+1);
  for(ll i = 1; i <= n; i++) {
    cin >> a;
    index[a].push_back(i);
  }
    

  ll q;
  cin >> q;
  for(ll i = 0; i < q; i++) {
    ll l, r, x;
    cin >> l >> r >> x;
    auto st = lower_bound(index[x].begin(), index[x].end(), l);
    auto fin = upper_bound(index[x].begin(), index[x].end(), r);
    cout << fin - st << endl;
  }
}