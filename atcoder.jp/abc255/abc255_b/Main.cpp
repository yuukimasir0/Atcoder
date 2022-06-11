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
        ll n = in(), k = in();
        vc<ll> a(k);
        vc<ll> x(n);
        vc<ll> y(n);
        for (auto &&i : a)
            i = in();
        for (ll i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        vc<double> m(n, inf);
        double M = 0;
        for (ll i = 0; i < n; i++)
        {
            for (auto &&j : a)
            {
                m[i] = min(m[i], sqrt((x[i] - x[j - 1]) * (x[i] - x[j - 1]) + (y[i] - y[j - 1]) * (y[i] - y[j - 1])));
            }
            M = max(M, m[i]);
        }
        printf("%.18f\n", M);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solver solver;
    solver.solve();
}
