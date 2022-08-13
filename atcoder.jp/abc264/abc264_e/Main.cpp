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

#define VC(...) input(__VA__ARGS_)

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

struct UnionFind {
 private:
  i32 n;
  vector<i32> parent;

 public:
  UnionFind(i32 n) : n(n), parent(n, -1) {}
  i32 root(i32 x) {
    if (parent[x] < 0) return x;
    return parent[x] = root(parent[x]);
  }
  void merge(i32 x, i32 y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    if (parent[x] > parent[y]) swap(x, y);
    parent[x] += parent[y];
    parent[y] = x;
  }
  bool same(i32 x, i32 y) { return root(x) == root(y); }
  i32 size(i32 x) { return -parent[root(x)]; }
};
#pragma endregion

struct Solver {
  void solve() {
    LL(n, m, e);
    UnionFind dsu(n + 2);
    vc<pair<i64, i64>> u(e);
    rep(e) {
      LL(x, y);
      auto &[j, k] = u[i];
      j = min(x, n + 1);
      k = min(y, n + 1);
    }
    LL(q);
    vc<i64> x(q);
    cin >> x;
    rep(q) x[i]--;
    auto y = x;
    sort(all(y));
    i32 temp = 0;
    for (i32 i = 0; i < e; i++) {
      if (i != y[temp])
        dsu.merge(u[i].first, u[i].second);
      else
        temp++;
    }
    reverse(all(x));
    vc<i64> ans;
    ans.push_back(dsu.size(n + 1) - 1);
    rep(q) {
      dsu.merge(u[x[i]].first, u[x[i]].second);
      ans.push_back(dsu.size(n + 1) - 1);
    }
    reverse(all(ans));
    i32 N = ans.size();
    debug("---ans---");
    for(i32 i = 1; i < N; i++)
      print(ans[i]);
  }
};

signed main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cout << fixed << setprecision(15);
  Solver solver;
  solver.solve();
}