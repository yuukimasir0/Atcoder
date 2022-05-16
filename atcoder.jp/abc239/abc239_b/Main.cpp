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
  
ll n;
string s;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> n;
  
  if(n % 10 != 0 && n < 0) {
    n /= 10;
    n--;
  } else {
    n /= 10;
  }
   cout << n << "\n"; 
}
