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
        ll x = in(), a = in(), d = in(), n = in();
        if (d == 0)
        {
            cout << abs(a - x) << "\n";
            return;
        }
        if (x < a && d > 0)
        {
            cout << abs(a - x) << "\n";
            return;
        }
        else if (x > a + d * (n - 1) && d > 0)
        {
            cout << abs(x - a - d * (n - 1)) << "\n";
            return;
        }
        if (x > a && d < 0)
        {
            cout << abs(a - x) << "\n";
            return;
        }
        else if (x < a + d * (n - 1) && d < 0)
        {
            cout << abs(x - a - d * (n - 1)) << "\n";
            return;
        }
        ll l = 0, r = n, m = (l + r) / 2;
        if (d > 0)
            while (true)
            {
                if (x > a + d * m)
                    l = m;
                else if (x < a + d * m)
                    r = m;
                m = (l + r) / 2;
                if (x >= a + d * (m) && x <= a + d * (m + 1))
                    break;
            }
        else
            while (true)
            {
                if (x < a + d * m)
                    l = m;
                else if (x > a + d * m)
                    r = m;
                m = (l + r) / 2;
                if (x <= a + d * (m) && x >= a + d * (m + 1))
                    break;
            }
        if (m < n - 1 && d > 0)
        {
            cout << min(x - a - d * (m), a + d * (m + 1) - x) << "\n";
            return;
        }
        else if (d > 0)
        {
            cout << x - a - d * (m) << "\n";
            return;
        }
        if (m < n - 1 && d < 0)
        {
            cout << min(x - a - d * (m + 1), a + d * (m)-x) << "\n";
            return;
        }
        else if (d < 0)
        {
            cout << x - a - d * (m) << "\n";
            return;
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