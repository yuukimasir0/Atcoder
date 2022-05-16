#include <bits/stdc++.h>
#pragma GCC optimize("03")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
constexpr int inf = 2e9;
constexpr ll llinf = 9e18;
  
ll x, y;
ll a1[8], b1[8];
ll a2[8], b2[8];


int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> x >> y;
  ll as[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
  ll bs[8] = {1, -1, 2, -2, 2, -2, 1, -1};
  
  for(ll i = 0; i < 8; i++) {
    a1[i] = x + as[i];
    b1[i] = y + bs[i];
  }
  
  cin >> x >> y;
  
  for(ll i = 0; i < 8; i++) {
    a2[i] = x + as[i];
    b2[i] = y + bs[i];
  }
  
  for(ll i = 0; i < 8; i++)
    for(ll j = 0; j < 8; j++)
      if(a1[i] == a2[j] && b1[i] == b2[j]) {
        cout << "Yes\n";
        return 0;
      }
  cout << "No\n";
  
}
