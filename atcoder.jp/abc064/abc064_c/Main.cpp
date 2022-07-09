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
        ll n = in();
        vc<ll> a(n);
        vc<bool> c(8, false);
        ll over = 0;
        for (auto &&i : a)
        {
            i = in();
            if (i >= 3200)
                over++;
            else {
                c[i / 400] = true;
            }
        }
        ll ans = 0;
        for (auto &&i : c) {
            if (i)
                ans++;
        }
        cout << max(ans, 1LL) << " " << ans + over << "\n";
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solver solver;
    solver.solve();
}
