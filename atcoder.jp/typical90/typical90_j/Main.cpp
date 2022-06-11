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
    vc<ll> c(n);
    vc<ll> p(n);
    for (ll i = 0; i < n; i++)
      cin >> c[i] >> p[i];
    vc<ll> s1(n + 1);
    vc<ll> s2(n + 1);
    for (ll i = 1; i <= n; i++) {
      if(c[i-1] == 1) {
        s1[i] = s1[i - 1] + p[i - 1];
        s2[i] = s2[i - 1];
      } else {
        s1[i] = s1[i - 1];
        s2[i] = s2[i - 1] + p[i - 1];
      }
    }
    ll q = in();
    while(q--) {
      ll l = in();
      ll r = in();
      cout << s1[r] - s1[l-1] << " " << s2[r] - s2[l-1] << "\n";
    }
  }
};

int main()
{
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solver solver;
  solver.solve();
}
