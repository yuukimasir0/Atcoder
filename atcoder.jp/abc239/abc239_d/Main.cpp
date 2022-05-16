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
  
int a, b, c, d;
int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  map<int, int> prime;
  prime[2] = 2;
  
  for(int i = 3; i <= 200; i++) {
    bool p = true;
    for(auto j : prime) {
      if(i % j.second == 0) {
        p = false;
        break;
      }
      if(j.second * j.second > i)
        break;
    }
    if(p)
      prime[i] = i;
  }
  
  cin >> a >> b >> c >> d;
  for(int i = a; i <= b; i++){
    bool can = true;
    for(int j = c; j <= d; j++)
      if(prime.count(i + j)) {
        can = false;
      }
    if(can) {
      cout << "Takahashi\n";
      return 0;
    }
  }
  cout << "Aoki\n";
}
