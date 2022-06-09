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
        vv<ll> a(n, vc<ll>(n + 1));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j <= i; j++)
            {
                if (i == j || j == 0)
                {
                    a[i][j] = 1;
                    cout << 1 << " ";
                }
                else
                {
                    a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
                    cout << a[i - 1][j - 1] + a[i - 1][j] << " ";
                }
            }
            cout << "\n";
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
