#pragma region header
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
#pragma endregion header

ll n, a, b;

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n >> a >> b;
    ll ans = n * (n + 1) / 2;
    for (ll i = a; i <= n; i += a)
    {
        ans -= i;
    }
    for (ll i = b; i <= n; i += b)
    {
        ans -= i;
    }
    ll c = lcm(a, b);
    for (ll i = c; i <= n; i += c)
    {
        ans += i;
    }
    cout << ans << "\n";
}
