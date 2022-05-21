#pragma region header
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
constexpr int inf = 2e9;
constexpr ll llinf = 9e18;
#pragma endregion header

ll n;
ll a, b, c;

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n;
    a = n % 10;
    b = (n/10) % 10;
    c = (n / 100) % 10;

    ll ans = 0;
    ans += (a + b + c) * 100;
    ans += (a + b + c) * 10;
    ans += (a + b + c);
    cout << ans << "\n";
}
