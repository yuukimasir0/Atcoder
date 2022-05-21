#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
string s;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> n >> s;
  deque<ll> a = {n} ;
  for(ll i = n-1; i >= 0; i--) {
    if(s[i] == 'L') {
      a.push_back(i);
    } else {
      a.push_front(i);
    }
  }
  for(ll i = 0; i <= n; i++)
    cout << a[i] << (i != n ? " " : "\n");
}