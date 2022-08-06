using namespace std;
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes puts("Yes");
#define no puts("No");

#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for (int i = 0; i < n; i++)
#define rep2(i, n) for (int i = 0; i < n; i++)
#define rep3(i, a, b) for (int i = a; i < b; i++)
#define rep4(i, a, b, c) for (int i = a; i < b; i += c)
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
typedef unsigned long long u64;
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
  for (auto &&j : v) cout << j << '\n';
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
    i32 n = in(), m = in();
    vc<i32> a(n);
    cin >> a;
    i32 A = *max_element(all(a)) + 1;
    i32 N = max(A, n + 1);
    vc<i32> cnt(N);
    vc<bool> ok(m + 1, true);
    rep(n) {
      auto pf = prime_factor(a[i]);
      for (const auto &p : pf)
        if(ok[p]) {
          rep(j, p, m + 1, p)
              ok[j] = false;
        }
    }
    vc<i32> ans;
    rep(i, 1, m + 1) if (ok[i]) ans.push_back(i);
    cout << ans.size() << '\n';
    cout << ans << '\n';
  }

  vc<i32> prime_factor(i32 x) {
    vc<i32> res;
    for (int i = 2; i * i <= x; i++) {
      while (x % i == 0) {
        x /= i;
        res.push_back(i);
      }
    }
    if (x != 1) { res.push_back(x); }
    return res;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cout << fixed << setprecision(15);
  Solver solver;
  solver.solve();
}