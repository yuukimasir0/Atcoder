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

ll n;
string s;

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n >> s;
    bool re = true;
    while (re)
    {
        re = false;
        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] == 'B' && s[i] == 'A')
            {
                swap(s[i - 1], s[i]);
                re = true;
            }
        }

        for (int i = 1; i < n; i++)
        {
            if (i == 1)
            {
                if (s[i - 1] == 'B' && s[i] == 'B')
                {
                    s = 'A' + s.substr(2);
                    n = s.length();
                    re = true;
                }
            }
            else if (i == n - 1 && n >= 2)
            {
                if (s[n - 1] == 'B' && s[n - 2] == 'B')
                {
                    s.erase(n - 1);
                    s.erase(n - 2);
                    s += 'A';
                    n = s.length();
                    re = true;
                }
            }
            else if (s[i - 1] == 'B' && s[i] == 'B')
            {
                string s1 = s.substr(0, i - 1);
                string s2 = s.substr(i + 1);
                s = s1;
                s += 'A';
                s += s2;
                n = s.length();
                re = true;
            }
        }
    }
    cout << s << "\n";
}
