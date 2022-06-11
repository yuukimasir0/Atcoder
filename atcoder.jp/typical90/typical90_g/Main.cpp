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
    vc<ll> a(n);
    for (auto &&i : a)
      i = in();
    ll q = in();
    vc<ll> b(q);
    for (auto &&i : b)
      i = in();
    sort(all(a));
    for (auto &&i : b)
      cout << min(abs(i - *lower_bound(all(a), i)), abs(i - *(lower_bound(a.begin() + 1, a.end(), i) - 1))) << "\n";
  }
};

int main()
{
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solver solver;
  solver.solve();
}
