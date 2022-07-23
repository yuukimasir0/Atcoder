using namespace std;
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "Yes\n";
#define no cout << "No\n";
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
istream &operator>>(istream &i, pair<T, U> &v)
{
  auto &&[j, k] = v;
  i >> j;
  i >> k;
  return i;
}

template <typename T>
istream &operator>>(istream &i, vc<T> &v)
{
  for (auto &&j : v)
    i >> j;
  return i;
}

template <typename T>
ostream &operator<<(ostream &i, vc<T> &v)
{
  for (auto &&j : v)
    cout << j << ' ';
  cout << '\n';
  return i;
}

struct in
{
  template <class T>
  operator T()
  {
    T t;
    std::cin >> t;
    return t;
  }
};

struct Solver
{
  void solve()
  {
    i32 n = in(), m = in();
    vc<i32> x(n + 1);
    for (i32 i = 1; i <= n; i++)
      cin >> x[i];
    vc<i64> c(m), y(m);
    vv<i64> dp(n + 1, vc<i64>(n + 1));
    dp[0][1] = x[0];
    for (i32 i = 0; i < m; i++)
      cin >> c[i] >> y[i];
    for (i32 i = 1; i <= n; i++)
    {
      for (i32 j = 1; j <= i; j++)
        dp[i][j] = dp[i - 1][j - 1] + x[i];
      dp[i][0] = *max_element(all(dp[i - 1]));
      for (i32 j = 0; j < m; j++)
        if (i >= c[j])
          dp[i][c[j]] = max(dp[i - 1][c[j] - 1] + x[i] + y[j], dp[i][c[j]]);
      //cout << dp[i];
    }
    cout << *max_element(all(dp[n])) << '\n';
  }
};

int main()
{
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cout << fixed << setprecision(15);
  Solver solver;
  solver.solve();
}