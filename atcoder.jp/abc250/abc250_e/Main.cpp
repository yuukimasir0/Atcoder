#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, q;
ll x, y;
map<ll, ll> mp;
  const ll INF = 1001001001;

int main() {
  cin >> n;
  vector<ll> a(n), b(n), ca(n), cb(n), mx(n);
  for(ll i = 0; i < n; i++)
    cin >> a[i];
  for(ll i = 0; i < n; i++)
    cin >> b[i];
  for(ll i = 0; i < n; i++) {
    if(!mp.count(a[i])) {
      mp[a[i]] = mp.size() + 1;
    }
    ca[i] = mp.size();
  }
  ll m = 0;
  set<ll> st;
  for(ll i = 0; i < n; i++) {
    ll x = mp[b[i]];
    st.insert(b[i]);
    if(x == 0) x = INF;
    m = max(m, x);
    mx[i] = m;
    cb[i] = st.size();
  }
  cin >> q;
  for(ll i = 0; i < q; i++) {
    cin >> x >> y;
    --x; --y;
    if(ca[x] == cb[y] && mx[y] == cb[y]) {
      puts("Yes");
    } else {
      puts("No");
    }
  }
}