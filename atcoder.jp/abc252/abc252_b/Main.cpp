#pragma region header
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
constexpr int inf = 2e9;
constexpr ll llinf = 9e18;
#pragma endregion header

ll n, k;
string s;

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n >> k;
    map<ll, vector<ll>> a;
    ll MAX = -1;
    for (ll i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        MAX = max(temp, MAX);
        a[temp].emplace_back(i+1);
    }
    ll b;
    for (ll i = 0; i < k; i++)
    {
        cin >> b;
        for (auto j : a[MAX]) {
            if(b == j) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
}
