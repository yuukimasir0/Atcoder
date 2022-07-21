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
    vv<i32> g(n + 1);
    for (i32 i = 1; i < n; i++)
    {
      i32 a = in(), b = in();
      g[a].push_back(b);
      g[b].push_back(a);
    }
    vc<bool> ans(n);
    vc<bool> seen(n);
    auto dfs = [&](auto dfs, i32 v, bool col) -> void
    {
      ans[v] = col;
      seen[v] = true;
      for(i32 i : g[v])
        if(seen[i])
          continue;
        else
          dfs(dfs, i, !col);
    };
    dfs(dfs, 1, false);
    vc<i32> ans1, ans2;
    for (i32 i = 1; i <= n; i++)
      if(ans[i])
        ans1.push_back(i);
      else
        ans2.push_back(i);
    if(ans1.size() > ans2.size())
      for (i32 i = 0; i < n / 2; i++)
        cout << ans1[i] << ' ';
    else
      for (i32 i = 0; i < n / 2; i++)
        cout << ans2[i] << ' ';
    cout << '\n';
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