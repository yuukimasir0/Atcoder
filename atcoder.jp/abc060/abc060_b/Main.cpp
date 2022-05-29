#pragma region header
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define yes cout << "YES\n";
#define no cout << "NO\n";
using namespace std;
typedef long long ll;
constexpr int inf = 2e9;
constexpr ll llinf = 9e18;
#pragma endregion header

ll n;
string s;
ll a, b, c;

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> a >> b >> c;
    for (int i = 0; i < 10000; i++) {
        if((a * i - c) % b)
            continue;
        yes;
        return 0;
    }
    no;
}
