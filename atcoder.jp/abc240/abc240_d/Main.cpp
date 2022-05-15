#include <bits/stdc++.h>
#pragma GCC optimize("03")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

int n, x;
int a;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int ball[200009];
  int count = 0;
  int check[200009];
  int now = 0;
  
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a;
    count++;
    if(a == ball[now]) {
      check[now]++;
      if(check[now] == a) {
        count -= a;
        now--;
      }
    } else {
      now++;
      ball[now] = a;
      check[now] = 1;
    }
    cout << count << "\n";
  }
}
