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
        vc<ll> a(n);
        for(auto&& i : a)
            i = in();
        vc<ll> b(n, 0);
        vc<bool> c(n, true);
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j <= i; j++) {
                b[j] += a[i];
                if(b[j] > 3 && c[j]) {
                    ans++;
                    c[j] = false;
                }
            }
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
