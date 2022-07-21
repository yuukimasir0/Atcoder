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

struct UnionFind
{
private:
  i32 n;
  vc<i32> parent;

public:
  UnionFind(i32 n) : n(n), parent(n, -1) {}
  i32 root(i32 x)
  {
    if (parent[x] == -1)
      return x;
    return parent[x] = root(parent[x]);
  }
  void merge(i32 x, i32 y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      return;
    if (parent[x] > parent[y])
      swap(x, y);
    parent[y] = x;
  }
  bool same(i32 x, i32 y)
  {
    return root(x) == root(y);
  }
};

struct Solver
{
  void solve()
  {
    i32 h = in(), w = in(), q = in();
    vv<bool> a(h + 2, vc<bool>(w + 2, false));
    UnionFind uf(h * w);
    auto query1 = [&]() -> void
    {
      i32 dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
      i32 x = in(), y = in();
      for (i32 i = 0; i < 4; i++)
      {
        i32 sx = x + dx[i], sy = y + dy[i];
        if (a[sx][sy] == false)
          continue;
        i32 h1 = (x - 1) * w + (y - 1);
        i32 h2 = (sx - 1) * w + (sy - 1);
        uf.merge(h1, h2);
      }
      a[x][y] = true;
    };
    auto query2 = [&]() -> void
    {
      i32 x1 = in(), y1 = in(), x2 = in(), y2 = in();
      if (a[x1][y1] == false || a[x2][y2] == false) {
        no
        return;
      }
      i32 h1 = (x1 - 1) * w + (y1 - 1);
      i32 h2 = (x2 - 1) * w + (y2 - 1);
      if (uf.same(h1, h2))
        yes else no
    };
    while (q--)
    {
      i32 t = in();
      if (t == 1)
        query1();
      else
        query2();
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