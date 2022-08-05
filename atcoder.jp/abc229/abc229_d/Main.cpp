using namespace std;
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes puts("Yes");
#define no puts("No");

#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for (int i = 0; i < (int)n; i++)
#define rep2(i, n) for (int i = 0; i < (int)n; i++)
#define rep3(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define rep4(i, a, b, c) for (int i = (int)a; i < (int)b; i += (int)c)
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define overload4(_1, _2, _3, _4, name, ...) name
#define rrep1(n) for (int i = (int)(n - 1); i >= 0; i--)
#define rrep2(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define rrep3(i, a, b) for (int i = (int)(b - 1); i >= (int)(a); i--)
#define rrep4(i, a, b, c) for (int i = (int)(b - 1); i >= (int)(a); i -= (int)(c))
#define rrep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

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
typedef long double ld;
// constexpr i32 mod = 1e9 + 7; // 998244353;

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
    string s = in();
    i32 k = in();
    i32 r = 0, ans = 0, n = s.length();
    vc<i32> cnt(n + 1, 0);
    for (i32 i = 0; i < n; i++)
      if (s[i] == '.')
        cnt[i + 1] = cnt[i] + 1;
      else
        cnt[i + 1] = cnt[i];
    rep(l, n) {
      while (r < n && cnt[r + 1] - cnt[l] <= k)
        r++;
      chmax(ans, r - l);
    }
    cout << ans << '\n';
  }
};

signed main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cout << fixed << setprecision(15);
  Solver solver;
  solver.solve();
}