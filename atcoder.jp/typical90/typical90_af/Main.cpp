using namespace std;
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define yes cout << "Yes\n";
#define no cout << "No\n";
template <typename T>
using vc = vector<T>;
template <typename T>
using vv = vc<vc<T>>;
typedef long long ll;
constexpr int inf = 2e9;
constexpr ll llinf = 9e18;

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
    ll n = in();
    vc<ll> p(n);
    ll ans = -1;
    for (int i = 0; i < n; i++)
      p[i] = i;
    vv<ll> a(n, vc<ll>(n));
    for (auto &&i : a)
      for (auto &&j : i)
        j = in();
    ll m = in();
    vv<bool> r(n, vc<bool>(n, true));
    while (m--)
    {
      int x = in(), y = in();
      x--;
      y--;
      r[x][y] = false;
      r[y][x] = false;
    }
    do
    {
      ll sum = 0;
      bool flag = true;
      for (int i = 0; i < n; i++)
      {
        sum += a[p[i]][i];
        if (i < n - 1 && !r[p[i]][p[i + 1]])
        {
          flag = false;
        }
      }
      if (flag)
      {
        if (ans < 0)
          ans = sum;
        else
          ans = min(ans, sum);
      }
    } while (next_permutation(all(p)));
    cout << ans << "\n";
  }
};

int main()
{
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solver solver;
  solver.solve();
}
