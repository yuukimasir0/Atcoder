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
typedef intmax_t ll;
typedef int_fast64_t i64;
typedef int_fast32_t i32;
// constexpr int inf = 2e9;
// constexpr ll llinf = 9e18;

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
    i32 n = in(), p = in(), q = in();
    vc<i32> a(n);
    cin >> a;
    i64 ans = 0;
    for (i32 i = 0; i < n; i++)
      for (i32 j = i + 1; j < n; j++)
        for (i32 k = j + 1; k < n; k++)
          for (i32 l = k + 1; l < n; l++)
            for (i32 m = l + 1; m < n; m++)
              if (a[i] % p * a[j] % p * a[k] % p * a[l] % p * a[m] % p == q)
                ans++;
    cout << ans << '\n';
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