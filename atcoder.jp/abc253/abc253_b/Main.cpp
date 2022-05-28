#pragma region header
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
constexpr int inf = 2e9;
constexpr ll llinf = 9e18;
#pragma endregion header

ll h, w;
string s[105];

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> h >> w;
    for (ll i = 0; i < h; i++)
    {
        cin >> s[i];
    }
    ll memo[4];
    ll k = 0;
    for (ll i = 0; i < h; i++)
        for (ll j = 0; j < w; j++)
        {
            if (s[i][j] == 'o')
            {
                memo[k] = i;
                memo[k + 1] = j;
                k += 2;
            }
        }
    cout << abs(memo[0] - memo[2]) + abs(memo[1] - memo[3]) << "\n";
}
