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
// constexpr int inf = 2e9;
// constexpr ll llinf = 9e18;

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
        vc<double> x(n);
        vc<double> y(n);
        for (auto i = 0; i < n; i++)
            x[i] = in(), y[i] = in();
        double ans = -1;
        for (ll i = 0; i < n; i++)
            for (ll j = i+1; j < n; j++)
                ans = max(ans, sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])));
        printf("%.18f\n", ans);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solver solver;
    solver.solve();
}
