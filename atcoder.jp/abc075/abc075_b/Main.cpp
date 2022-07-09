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
        ll h = in(), w = in();
        vv<ll> a(h + 2, vc<ll>(w + 2, 0));
        vv<ll> b(h + 2, vc<ll>(w + 2, 0));
        vc<string> s(h+2);
        for (ll i = 1; i <= h; i++)
        {
            cin >> s[i];
            for (ll j = 0; j < w; j++)
                if (s[i][j] == '#')
                    a[i][j+1] = -1;
        }
        for (ll i = 1; i <= h; i++)
            for (ll j = 1; j <= w; j++)
                b[i][j] = a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1] + a[i][j - 1] + a[i][j] + a[i][j + 1] + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1];
        for (ll i = 1; i <= h; i++)
        {
            for (ll j = 0; j < w; j++)
                if (s[i][j] == '#')
                    cout << "#";
                else
                    cout << abs(b[i][j+1]);
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
