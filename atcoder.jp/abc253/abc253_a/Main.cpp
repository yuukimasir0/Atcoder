#pragma region header
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
constexpr int inf = 2e9;
constexpr ll llinf = 9e18;
#pragma endregion header

ll a, b, c;
string s;

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> a >> b >> c;
    if(a <= b && b <= c) {
        cout << "Yes\n";
        return 0;
    }
    else if (c <= b && b <= a) {
        cout << "Yes\n";
        return 0;
    }
    cout << "No\n";
}
