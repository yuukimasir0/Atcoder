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
// constexpr double pi = 3.141592653589793238462643383279;

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
        string s = in();
        ll ad = 0;
        ll ch = n;
        vc<pair<ll, bool>> h(n);
        int i = 0;
        for (auto &&[w, b] : h)
        {
            w = in();
            b = s[i] - '0';
            if (b)
            {
                ad++;
                ch--;
            }
            i++;
        }
        sort(all(h), greater<pair<ll, bool>>());
        ll ans = ch;
        ll temp = ch;
        for (ll i = 0; i < n; i++)
        {
            if (h[i].second)
                temp++;
            else
                temp--;
            if (i != n - 1 && h[i].first == h[i + 1].first)
                continue;
            ans = max(ans, temp);
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
