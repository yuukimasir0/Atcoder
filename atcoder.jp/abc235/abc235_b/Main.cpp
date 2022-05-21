#pragma region header
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
constexpr int inf = 2e9;
constexpr ll llinf = 9e18;
#pragma endregion header

ll n;
ll a;

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n;
    ll ans = -1;
    for (ll i = 0; i < n; i++) {
        cin >> a;
        if(a > ans) {
            ans = a;
        } else {
            cout << ans << "\n";
            return 0;
        }
    }
    cout << ans << "\n";
}
