using namespace std;
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define yes cout << "Yes\n";
#define no cout << "No\n";
template <typename T>
using vc = vector<T>;
template <typename T>
using vv = vc<vc<T>>;
template <typename T>
using pq_g = priority_queue<T, vc<T>, greater<T>>;
template <typename T>
using pq_l = priority_queue<T, vc<T>, less<T>>;
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
        ll n = in(), m = in();
        pq_l<ll> pq;
        for (ll i = 0; i < n; i++)
        {
            ll a = in();
            pq.push(a);
        }
        ll use = m;
        while (use--)
        {
            ll a = pq.top();
            pq.pop();
            a >>= 1;
            pq.push(a);
        }
        ll ans = 0;
        while(pq.empty() == false) {
            ans += pq.top();
            pq.pop();
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
