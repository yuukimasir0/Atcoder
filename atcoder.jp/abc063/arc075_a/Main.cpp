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

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n;
    vector<int> s(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        ans += s[i];
    }
    if (ans % 10)
    {
        cout << ans << "\n";
        return 0;
    }
    sort(all(s));
    for (int i = 0; i < n;i++)
    {
        if(s[i] % 10) {
            cout << ans - s[i] << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
}