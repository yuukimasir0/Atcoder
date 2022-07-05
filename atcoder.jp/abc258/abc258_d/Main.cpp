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
        ll n = in(), x = in();
        vc<pair<ll, ll>> g(n);
        set<ll> m;
        vc<ll> sum(n);
        int i = 0;
        ll ans = llinf;
        for (auto &&[a, b] : g)
        {
            a = in();
            b = in();
            m.insert(b);
            if (i == 0)
            {
                sum[i] = a + b;
                ans = min(ans, sum[i] + *m.begin() * (x - i - 1));
                i++;
                continue;
            }
            sum[i] = a + b + sum[i - 1];
            ans = min(ans, sum[i] + *m.begin() * (x - i - 1));
            i++;
            if (i > x)
                break;
        }
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
