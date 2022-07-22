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
    cout << j << ' ';
  cout << '\n';
  return i;
}

template <typename T, typename U>
ostream &operator<<(ostream &i, pair<T, U> &p)
{
  auto [j, k] = p;
  cout << "(" << j << ", " << k << ") ";
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
    i32 n = in(), m = in();
    vc<tuple<i32, i32, i32>> list(n + m);
    for (i32 i = 0; i < n; i++)
      cin >> get<0>(list[i]);
    for (i32 i = 0; i < n; i++)
      cin >> get<2>(list[i]);
    for (i32 i = 0; i < m; i++)
      cin >> get<0>(list[n + i]);
    for (i32 i = 0; i < m; i++)
      cin >> get<2>(list[n + i]);
    for (i32 i = 0; i < n; i++)
      get<1>(list[i]) = 0;
    for (i32 i = 0; i < m; i++)
      get<1>(list[n + i]) = 1;
    sort(all(list), greater<tuple<i32, i32, i32>>());
    multiset<i32> st;
    for (i32 i = 0; i < n + m; i++)
    {
      auto [h, num, w] = list[i];
      if (num == 1)
        st.insert(w);
      else
      {
        auto it = st.lower_bound(w);
        if (it == st.end())
        {
          cout << "No\n";
          return;
        }
        st.erase(it);
      }
    }
    cout << "Yes\n";
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