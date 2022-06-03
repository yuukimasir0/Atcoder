#pragma region header
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define yes cout << "Yes\n";
#define no cout << "No\n";
using namespace std;
typedef long long ll;
constexpr int inf = 2e9;
constexpr ll llinf = 9e18;
#pragma endregion header

ll n;
string s;

struct Solver
{
    void solve()
    {
        cin >> n;
        set<ll> mx;
        vector<ll> a(n);
        vector<ll> b(n);
        cin >> a[0];
        mx.insert(a[0]);
        b[0] = a[0];
        cout << 2 * a[0] << "\n";
        ll ans = a[0];
        for (ll i = 1; i < n; i++)
        {
            cin >> a[i];
            mx.insert(a[i]);
            b[i] = b[i - 1] + a[i];
            ans += b[i];
            cout << ans + (i + 1) * *mx.rbegin() << "\n";
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
