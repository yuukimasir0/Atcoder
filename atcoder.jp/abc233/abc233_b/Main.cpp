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

namespace cat
{
    inline ll mod(ll x, ll m)
    {
        return (((x % m) + m) % m);
    }
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
       ll l = in(), r = in();
       string s = in();
       string mid = s.substr(l-1, r - l + 1);
       reverse(all(mid));
       string ans = s.substr(0, l-1) + mid + s.substr(r);
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

