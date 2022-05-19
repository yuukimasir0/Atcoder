#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t;
ll a, s;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> t;
  for(ll i = 0; i < t; i++) {
    cin >> a >> s;
    bool can = false;
    if(2*a <= s && ((s - 2*a) & a) == 0)
      can = true;
    cout << (can ? "Yes\n" : "No\n");
  }
}