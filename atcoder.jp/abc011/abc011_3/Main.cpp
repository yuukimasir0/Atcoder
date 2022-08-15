#pragma region
using namespace std;
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for (int i = 0; i < n; i++)
#define rep2(i, n) for (int i = 0; i < n; i++)
#define rep3(i, a, b) for (int i = a; i < b; i++)
#define rep4(i, a, b, c) for (int i = a; i < b; i += c)
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define rrep1(n) for (int i = (int)(n - 1); i >= 0; i--)
#define rrep2(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define rrep3(i, a, b) for (int i = (int)(b - 1); i >= (int)(a); i--)
#define rrep4(i, a, b, c) \
  for (int i = (int)(b - 1); i >= (int)(a); i -= (int)(c))
#define rrep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define LL(...)    \
  i64 __VA_ARGS__; \
  input(__VA_ARGS__)

#define STR(...)      \
  string __VA_ARGS__; \
  input(__VA_ARGS__)

template <class T, class... U>
void print(T &a, U &...b) {
  cout << a;
  (cout << ... << (cout << ' ', b));
  cout << '\n';
}

#ifdef _CAT
#define debug(...) print(__VA_ARGS__)
#else
#define debug(...)
#endif

template <class... T>
constexpr auto min(T... a) {
  return min(initializer_list<common_type_t<T...>>{a...});
}

template <class... T>
constexpr auto max(T... a) {
  return max(initializer_list<common_type_t<T...>>{a...});
}

template <class... T>
void input(T &...a) {
  (cin >> ... >> a);
}

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
#pragma endregion

struct Solver {
  void solve() {
    LL(n, ng1, ng2, ng3);
    vc<i64> dp(max(n + 1, 4), 301);
    if (n == ng1 || n == ng2 || n == ng3) {
      print("NO");
      return;
    }
    dp[n] = 0;
    if (n - 1 == 0 || n - 2 == 0) {
      print("YES");
      return;
    }
    for (i64 i = n - 1; i >= 0; i--) {
      if (i == ng1 || i == ng2 || i == ng3) continue;
      if (i + 1 <= n) chmin(dp[i], dp[i + 1] + 1);
      if (i + 2 <= n) chmin(dp[i], dp[i + 2] + 1);
      if (i + 3 <= n) chmin(dp[i], dp[i + 3] + 1);
    }
    rep(n + 1) debug(dp[i]);
    if (dp[0] > 0 && dp[0] <= 100)
      print("YES");
    else
      print("NO");
  }
};

signed main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cout << fixed << setprecision(15);
  Solver solver;
  solver.solve();
}