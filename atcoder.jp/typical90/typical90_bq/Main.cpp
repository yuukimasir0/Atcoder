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
    i64 n = in(), k = in();
    if (n == 1)
      cout << k << '\n';
    else if (n == 2 && k != 1)
      cout << k * (k - 1) % mod << '\n';
    else if (k == 1 || k == 2)
      cout << 0 << '\n';
    else
      cout << k % mod * (k - 1) % mod * powmod(k - 2, n - 2) % mod << '\n';
  }

  i64 powmod(i64 a, i64 n)
  {
    i64 res = 1;
    while (n)
    {
      if (n & 1)
        res = res * a % mod;
      a = a * a % mod;
      n >>= 1;
    }
    res %= mod;
    return res;
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