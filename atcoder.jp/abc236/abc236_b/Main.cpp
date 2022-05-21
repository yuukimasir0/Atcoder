#pragma region header
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
constexpr int inf = 2e9;
constexpr ll llinf = 9e18;
#pragma endregion header

ll n;
ll a[100009];

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n;
    for (ll i = 1; i < 4 * n; i++)
    {
        ll temp;
        cin >> temp;
        a[temp]++;
    }
    for (ll i = 1; i <= n; i++)
    {
        if(a[i] != 4) {
            cout << i << "\n";
        return 0;
        }
    }
}