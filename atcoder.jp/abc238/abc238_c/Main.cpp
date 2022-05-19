#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll n;
constexpr ll MOD = 998244353;
constexpr ll inv2 = 499122177;

ll solve(ll n) {
  ll ans = 0;
  n %= MOD;
  ans = n;
  ans %= MOD;
  ans *= (n+1);
  ans %= MOD;
  ans *= inv2;
  ans %= MOD;
  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> n;
  ll ans = 0;
  ll p = 10;
  for(ll dg = 1; dg <= 18; dg++){
    ll l = p / 10;
    ll r = min(n, p-1);
    if(l <= r){
      ans += solve(r - l + 1);
      ans %= MOD;
    }
    p *= 10;
  }
  cout << ans << "\n";
}