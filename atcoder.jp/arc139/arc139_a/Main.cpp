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

int n;
int t[100009];

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n;
    vector<ll> ans(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++)
    {
        ll y1, y2;
        y1 = (floor(ans[i - 1] / (1LL << t[i])) + 1) * (1LL << t[i]);
        y2 = y1 + (1LL << t[i]);
        if (y1 % (1LL << (t[i] + 1)))
            ans[i] = y1;
        else
            ans[i] = y2;
    }
    cout << ans[n] << "\n";
}
