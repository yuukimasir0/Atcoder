#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, x;
ll c[15];
ll a[15][15];


int main(){
  cin >> n >> m >> x;
  for(ll i = 0; i < n; i++){
    cin >> c[i];
    for(ll j = 0; j < m; j++)
      cin >> a[i][j];
  }
  const ll inf = (1 << 30);
  ll ans = inf;
  
  for(ll i = 1; i < (1 << n); i++){
    vector<ll> skill(15, 0);
    ll temp = 0;
    for(ll j = 0; j < n; j++)
      if(((i >> j) & 1) == 1){
        temp += c[j];
        for(ll k = 0; k < m; k++)
          skill[k] += a[j][k];
      }
    for(ll j = 0; j < m; j++){
      if(skill[j] < x)
        temp = inf;
    }
    ans = min(ans, temp);
  }
  if(ans == inf)
    ans = -1;
  cout << ans << endl;
}