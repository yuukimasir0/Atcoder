#pragma region header
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
constexpr int inf = 2e9;
constexpr ll llinf = 9e18;
#pragma endregion header

ll n, m;
unordered_map<string, ll> s;
bool a[100009];

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n >> m;
    for (ll i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        s[temp] = i;
    }

    for (ll i = 0; i < m; i++) {
        string temp;
        cin >> temp;
        a[s[temp]] = true;
    }

    for (ll i = 0; i < n; i++)
        cout << (a[i] ? "Yes" : "No") << "\n";
}