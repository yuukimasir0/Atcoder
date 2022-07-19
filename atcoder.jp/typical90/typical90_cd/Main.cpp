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
typedef unsigned long long u64;
// constexpr i32 inf = 2e9;
// constexpr i64 llinf = 9e18;
constexpr i64 mod = 1e9 + 7;

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
    u64 l = in(), r = in();
    i64 ans = 0;
    auto p10 = init();
    for (i32 i = 1; i < 20; i++){
      u64 vl = max(l, p10[i - 1]);
      u64 vr = min(r, p10[i] - 1ULL);
      if(vl > vr)
        continue;
      i64 val = (f(vr) - f(vl - 1) + mod) % mod;
      ans += 1LL * i * val;
      ans %= mod;
    }
    cout << ans << '\n';
  }

  vc<u64> init()
  {
    vc<u64> res(20);
    res[0] = 1;
    for (i32 i = 1; i < 20; i++)
      res[i] = (10ULL * res[i - 1]);
    return res;
  }

  i64 f(i64 x)
  {
    if (x % 2LL == 0)
    {
      i64 v1 = (x / 2LL) % mod;
      i64 v2 = (x + 1LL) % mod;
      return v1 * v2 % mod;
    }
    else
    {
      i64 v1 = x % mod;
      i64 v2 = ((x + 1LL) / 2LL) % mod;
      return v1 * v2 % mod;
    }
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