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
using graph = vv<ll>;
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
        ll sx = in(), sy = in(), tx = in(), ty = in();
        vc<ll> x(n);
        vc<ll> y(n);
        vc<ll> r(n);
        graph g(n);
        vc<ll> dist(n, -1);
        queue<ll> q;

        for (ll i = 0; i < n; i++)
        {
            x[i] = in();
            y[i] = in();
            r[i] = in();
        }

        ll ans = -1;

        for (ll i = 0; i < n; i++)
        {
            if ((x[i] - sx) * (x[i] - sx) + (y[i] - sy) * (y[i] - sy) == r[i] * r[i])
            {
                if (q.empty())
                {
                    q.push(i);
                    dist[i] = 0;
                }
            }
            if ((x[i] - tx) * (x[i] - tx) + (y[i] - ty) * (y[i] - ty) == r[i] * r[i])
                ans = i;
            for (ll j = 0; j < n; j++)
            {
                if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= (r[i] + r[j]) * (r[i] + r[j]) && (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) >= (r[i] - r[j]) * (r[i] - r[j]))
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        while (q.empty() == false)
        {
            ll v = q.front();
            q.pop();

            for (auto &&i : g[v])
            {
                if (dist[i] != -1)
                    continue;
                dist[i] = dist[v] + 1;
                q.push(i);
            }
        }
        if (dist[ans] != -1)
            yes else no
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solver solver;
    solver.solve();
}
