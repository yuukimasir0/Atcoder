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
    i32 h = in(), w = in();
    vv<i32> a(h, vc<i32>(w));
    vv<i32> b(h, vc<i32>(w));
    cin >> a >> b;
    i64 cnt = 0;
    for (i32 i = 0; i < h - 1; i++)
      for (i32 j = 0; j < w - 1; j++)
      {
        i32 temp = b[i][j] - a[i][j];
        a[i][j] += temp;
        a[i][j + 1] += temp;
        a[i + 1][j] += temp;
        a[i + 1][j + 1] += temp;
        cnt += abs(temp);
      }
    for (i32 i = 0; i < h; i++)
      for (i32 j = 0; j < w; j++)
        if (a[i][j] != b[i][j])
        {
          cout << "No\n";
          return;
        }
    cout << "Yes\n" << cnt << '\n';
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