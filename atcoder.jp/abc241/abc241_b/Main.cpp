#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
ll a[1009], b[1009];
map<ll, ll> mp;

int main(){
  cin >> n >> m;
  for(ll i = 0; i < n; i++){
    cin >> a[i];
    mp[a[i]]++;
  }
  for(ll i = 0; i < m; i++)
    cin >> b[i];
  for(ll i = 0; i < m; i++)
    if(mp[b[i]] != 0){
      mp[b[i]]--;
    }else{
      cout << "No" << endl;
      return 0;
    } 
  cout << "Yes" << endl;
}