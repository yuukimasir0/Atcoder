#pragma region header
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
constexpr int inf = 2e9;
constexpr ll llinf = 9e18;
#pragma endregion header

ll n, q;

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n >> q;
    map<ll, vector<ll>> a;
    for (ll i = 1; i <= n; i++)
    {
        ll temp;
        cin >> temp;
        a[temp].emplace_back(i);
    }
    for (ll i = 0; i < q; i++) {
        ll x, k;
        cin >> x >> k;
        if(k > a[x].size()) {
            cout << -1 << "\n";
        } else {
            cout << a[x][k-1] << "\n";
        }
    }
}
