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
        graph g(n + 1);
        for (ll i = 1; i <= n; i++) {
            ll a = in();
            g[i].push_back(a);
        }
        vc<ll> dist(n + 1, -1);
        queue<ll> q;

        dist[1] = 0;
        q.push(1);

        while(q.empty() == false) {
            ll v = q.front();
            q.pop();

            for(auto &&i : g[v]) {
                if(dist[i] != -1)
                    continue;
                dist[i] = dist[v] + 1;
                q.push(i);
            }
        }
        cout << dist[2] << "\n";
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solver solver;
    solver.solve();
}
