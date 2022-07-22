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
    vc<pair<i32, i32>> l(n), r(n);
    i32 h = -1;
    i32 w = -1;
    for (i32 i = 0; i < n; i++)
    {
      cin >> l[i] >> r[i];
      w = max(w, r[i].first);
      h = max(h, r[i].second);
    }

    vv<i32> s(h + 1, vc<i32>(w + 1));
    for (i32 i = 0; i < n; i++)
    {
      s[l[i].second][l[i].first]++;
      s[r[i].second][r[i].first]++;
      s[l[i].second][r[i].first]--;
      s[r[i].second][l[i].first]--;
    }
    for (i32 i = 0; i <= h; i++)
      for (i32 j = 1; j <= w; j++)
        s[i][j] += s[i][j - 1];
    for (i32 i = 1; i <= h; i++)
      for (i32 j = 0; j <= w; j++)
        s[i][j] += s[i - 1][j];
    vc<i32> ans(n + 1);
    for (i32 i = 0; i <= h; i++)
      for (i32 j = 0; j <= w; j++)
        if (s[i][j] > 0)
          ans[s[i][j]]++;
    for (i32 i = 1; i <= n; i++)
      cout << ans[i] << '\n';
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