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
    i64 n = in();
    vc<i64> a(n), s(2 * n);
    cin >> a;
    s[0] = a[0];
    for (i64 i = 1; i < n; i++)
      s[i] = s[i - 1] + a[i];
    for (i64 i = n; i < 2 * n; i++)
      s[i] = s[i - 1] + a[i - n];
    i64 M = s[n - 1];
    if (M % 10 != 0)
    {
      cout << "No\n";
      return;
    }
    M /= 10;
    for (i32 i = 0; i < n; i++)
      if (binary_search(all(s), s[i] + M))
      {
        cout << "Yes\n";
        return;
      }
    cout << "No\n";
  }

  void solve2()
  {
    i64 n = in();
    vc<i64> a(n), s(2 * n);
    cin >> a;
    s[0] = a[0];
    for (i64 i = 1; i < n; i++)
      s[i] = s[i - 1] + a[i];
    for (i64 i = n; i < 2 * n; i++)
      s[i] = s[i - 1] + a[i - n];
    i64 M = s[n - 1];
    if (M % 10 != 0)
    {
      cout << "No\n";
      return;
    }
    M /= 10;
    i64 i = 1, j = 0;
    while (j != 2 * n - 1)
    {
      if (s[i] - s[j] == M)
      {
        cout << "Yes\n";
        return;
      }
      while (s[i] - s[j] > M)
        j++;
      while (s[i] - s[j] < M && i != 2 * n - 1)
        i++;
      if (i == 2 * n - 1 && s[i] - s[j] < M)
        break;
    }

    cout << "No\n";
  }
};

int main()
{
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cout << fixed << setprecision(15);
  Solver solver;
  solver.solve2();
}