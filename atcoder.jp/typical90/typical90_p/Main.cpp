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
constexpr ll M = 9999;
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
    vc<ll> temp(3);
    for (auto &&i : temp)
      i = in();
    sort(all(temp));
    ll a = temp[0], b = temp[1], c = temp[2];
    ll ans = llinf;
    for (ll i = M; i >= 0; i--)
      for (ll j = M-i; j >= 0; j--)
        if ((n - c * i - b * j) % a == 0 && n - c * i - b * j >= 0)
          ans = min(ans, i + j + (n - c * i - b * j) / a);
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
