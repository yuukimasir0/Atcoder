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
bool ch(T &a, T &b) {
  return a < b ? swap(a, b), true : false;
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
    i64 n = in();
    vc<string> s(n);
    cin >> s;
    i64 ans = 0;
    unordered_map<string, i32> mp;
    for (i32 i = 0; i < n; i++)
      if(mp[s[i]]++ == 0)
        ans++;
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