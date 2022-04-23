#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
string s[100];

int main(){
  ll ans = 0;
  cin >> n >> k;
  for(ll i = 0; i < n; i++)
    cin >> s[i];
  string abc = "qazwsxedcrfvtgbyhnujmikolp";
  
  for(ll i = 0; i < (1<<n); i++){
      map<char, ll> mp;
    for(ll j = 0; j < abc.length(); j++)
      mp[abc[i]] = 0;
    ll temp = 0;
    for(ll j = 0; j < n; j++)
      if((i >> j) & 1 == 1)
        for(ll l = 0; l < s[j].length(); l++)
          mp[s[j][l]]++;
    
    for(ll j = 0; j < n; j++)
        for(ll l = 0; l < s[j].length(); l++)
          if(mp[s[j][l]] == k){
            temp++;
            mp[s[j][l]] = 0;
          }
    ans = max(ans, temp);
  }
  cout << ans << endl;
}