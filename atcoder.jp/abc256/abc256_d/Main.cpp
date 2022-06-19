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
// constexpr double pi = 3.141592653589793238462643383279

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
        vc<pair<ll, ll>> a;
        for (ll i = 0; i < n; i++)
        {
            ll l = in(), r = in();
            a.push_back({l, 0});
            a.push_back({r, 1});
        }
        sort(all(a));

        int cnt = 0;
        for (auto [t, f] : a)
        {
            if (f == 0)
            {
                if (cnt == 0)
                    cout << t << " ";
                cnt++;
            }
            else
            {
                cnt--;
                if (cnt == 0)
                    cout << t << "\n";
            }
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
