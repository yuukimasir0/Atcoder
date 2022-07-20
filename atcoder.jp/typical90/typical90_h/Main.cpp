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
constexpr i32 mod = 1e9 + 7;

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
    cout << j;
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
    i32 n = in();
    string s = in();
    vv<i64> dp(n + 1, vc<i64>(8));
    dp[0][0] = 1;
    for (i32 i = 0; i < n; i++)
    {
      for (i32 j = 0; j <= 7; j++) {
        dp[i + 1][j] += dp[i][j];
        if (s[i] == 'a' && j == 0)
          dp[i + 1][j + 1] += dp[i][j];
        if (s[i] == 't' && j == 1)
          dp[i + 1][j + 1] += dp[i][j];
        if (s[i] == 'c' && j == 2)
          dp[i + 1][j + 1] += dp[i][j];
        if (s[i] == 'o' && j == 3)
          dp[i + 1][j + 1] += dp[i][j];
        if (s[i] == 'd' && j == 4)
          dp[i + 1][j + 1] += dp[i][j];
        if (s[i] == 'e' && j == 5)
          dp[i + 1][j + 1] += dp[i][j];
        if (s[i] == 'r' && j == 6)
          dp[i + 1][j + 1] += dp[i][j];
      }
      for (i32 j = 0; j <= 7; j++)
        dp[i + 1][j] %= mod;
    }
    cout << dp[n][7] << '\n';
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