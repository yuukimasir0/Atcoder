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
        ll n = in(), q = in();
        string s = in();
        ll top = 0;
        while (q--)
        {
            ll t = in();
            ll x = in();
            if (t == 1)
            {
                top -= x;
                if (top < 0)
                {
                    top += n;
                }
            }
            if (t == 2)
                cout << s[(top + x - 1) % n] << "\n";
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
