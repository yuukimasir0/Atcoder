#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll a[20];
vector<ll> x[20];
vector<ll> y[20];

int main(){
  cin >> n;
  ll ans = 0;
  
  for(ll i = 0; i < n; i++){
    cin >> a[i];
    for(ll j = 0; j < a[i]; j++){
      ll temp;
      cin >> temp;
      temp--;
      x[i].push_back(temp);
      cin >> temp;
      y[i].push_back(temp);
    }
  }
  
  for(ll i = 0; i < (1 << n); i++){
    bool flag = true;
    ll ans_t = 0;
    for(ll j = 0; j < n; j++){
      if((i & (1 << j)) == 0){
        continue;
      }else{
        ans_t++;
        for(ll k = 0; k < a[j]; k++){
          ll t = (i & (1 << x[j][k]));
          if(t != 0)
            t = 1;
          if(t ^ y[j][k]){
            flag = false;
            ans_t = 0;
            break;
          }
        }
      }
      if(!flag)
        break;
    }
    ans = max(ans, ans_t);
  }
  cout << ans << endl;
}