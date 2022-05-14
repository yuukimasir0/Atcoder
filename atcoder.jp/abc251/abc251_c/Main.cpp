#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
string s[200009];
ll t[200009];

int main() {
  cin >> n;
  for(ll i = 0; i < n; i++) {
	cin >> s[i] >> t[i];
  }
  map<string, ll> ans;
  for(ll i = 0; i < n; i++){
    if(ans.count(s[i]) != 0) {
      t[i] = -1;
    } else {
      ans[s[i]] = 1;
    }
  }
  ll temp = 0;
  ll max = -1;
  for(ll i = 0; i < n; i++) {
    if(t[i] > max) {
      max = t[i];
      temp = i;
    }
  }
  cout << temp + 1 << endl;
}