using namespace std;
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "Yes\n";
#define no cout << "No\n";
template <typename T>
bool chmin(T &a, T b) {
  return a > b ? a = b, true : false;
}
template <typename T>
bool chmax(T &a, T b) {
  return a < b ? a = b, true : false;
}
template <typename T>
using vc = vector<T>;
template <typename T>
using pQ = priority_queue<T, vc<T>, greater<T>>;
template <typename T>
using Pq = priority_queue<T, vc<T>, less<T>>;
template <typename T>
using vv = vc<vc<T>>;
typedef long long ll;
typedef long long i64;
typedef int i32;
// constexpr i32 inf = 2e9;
// constexpr i64 llinf = 9e18;
// constexpr i32 mod =

template <typename T, typename U>
istream &operator>>(istream &i, pair<T, U> &v) {
  auto &&[j, k] = v;
  i >> j;
  i >> k;
  return i;
}

template <typename T>
istream &operator>>(istream &i, vc<T> &v) {
  for (auto &&j : v) i >> j;
  return i;
}

template <typename T>
ostream &operator<<(ostream &i, vc<T> &v) {
  for (auto &&j : v) cout << j << ' ';
  cout << '\n';
  return i;
}

struct in {
  template <class T>
  operator T() {
    T t;
    std::cin >> t;
    return t;
  }
};

struct Solver {
  void solve() {
    i32 h = in(), w = in(), k = in();
    vv<i32> c(h, vc<i32>(w, 0));
    i32 m = 0;
    i64 ans = 0;
    vc<i32> sh(h, 0);
    vc<i32> sw(w, 0);
    for (i32 i = 0; i < h; i++) {
      string s = in();
      for (i32 j = 0; j < w; j++)
        if (s[j] == '#') {
          c[i][j] = 1;
          sh[i]++;
          sw[j]++;
          m++;
        }
    }
    for (i32 i = 0; i < (1 << h); i++)
      for (i32 j = 0; j < (1 << w); j++) {
        i32 temp = m;
        vc<bool> che(h);
        for (i32 k = 0; k < h; k++) 
          if((i >> k & 1 )!= 0) {
            temp -= sh[k];
            che[k] = true;
          }
        for (i32 k = 0; k < w; k++)
          if ((j >> k & 1) != 0) {
            temp -= sw[k];
            for (i32 l = 0; l < h; l++)
              if(che[l])
                temp += c[l][k];
          }
        if(temp == k)
          ans++;
      }
    cout << ans << '\n';
  }
};

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cout << fixed << setprecision(15);
  Solver solver;
  solver.solve();
}