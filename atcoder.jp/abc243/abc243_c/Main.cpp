#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll x[200009], y[200009];
string s;

int main(){
  cin >> n;
  for(ll i = 0; i < n; i++)
    cin >> x[i] >> y[i];
  cin >> s;
  map<ll, vector<ll> > d;
  for(ll i = 0; i < n; i++)
    d[y[i]].push_back(i);
  
  for (auto p : d) {
    vector<ll> ids = p.second;
    vector<pair<ll,char>> ps;
    for (ll i : ids) {
      ps.emplace_back(x[i], s[i]);
    }
    sort(ps.begin(), ps.end());
    ll len = ps.size();
    for(ll i = 0; i < len-1; i++){
      if (ps[i].second == 'R' && ps[i+1].second == 'L') {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}