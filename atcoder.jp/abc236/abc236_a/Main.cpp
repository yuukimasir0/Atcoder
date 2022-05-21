#pragma region header
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
constexpr int inf = 2e9;
constexpr ll llinf = 9e18;
#pragma endregion header

string s;
ll a, b;
ll n;

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> s >> a >> b;
    a--;
    b--;
    n = s.length();
    for (ll i = 0; i < n; i++) {
        if(i == a) {
            cout << s[b];
        } else if(i == b) {
            cout << s[a];
        } else {
            cout << s[i];
        }
    }
    cout << "\n";
}