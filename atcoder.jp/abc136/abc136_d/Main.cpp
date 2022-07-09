using namespace std;
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define yes cout << "Yes\n";
#define no cout << "No\n";
template <typename T>
using vc = vector<T>;
template <typename T>
using vv = vc<vc<T>>;
typedef long long ll;
constexpr int inf = 2e9;
constexpr ll llinf = 9e18;

namespace cat
{
    inline ll mod(ll x, ll m)
    {
        return (((x % m) + m) % m);
    }
}

struct in
{
    template <class T>
    operator T()
    {
        T t;
        std::cin >> t;
        return t;
    }
};

struct Solver
{
    void solve()
    {
        string s = in();
        auto r = rle(s);
        int n = r.size();
        for (int i = 0; i < n; i++)
        {
            int zero = r[i].second - 1;
            if (i % 2 == 0)
            {
                while (zero--)
                    cout << 0 << " ";
                int sum = r[i].second + r[i + 1].second;
                if (sum % 2 == 0)
                {
                    cout << sum / 2 << " " << sum / 2 << " ";
                }
                else
                {
                    if (r[i].second % 2 == 0)
                    {
                        cout << sum / 2 << " " << sum / 2 + 1 << " ";
                    }
                    else
                    {
                        cout << sum / 2 + 1 << " " << sum / 2 << " ";
                    }
                }
            }
            else
            {
                while (zero--)
                    cout << 0 << " ";
            }
        }
    }

    vc<pair<char, ll>> rle(string &s)
    {
        vc<pair<char, ll>> rle;
        int n = s.length();
        pair<char, ll> now = {s[0], 1};
        for (int i = 1; i < n; i++)
        {
            if (s[i] == now.first)
            {
                now.second++;
                if (i == n - 1)
                    rle.emplace_back(now);
            }
            else
            {
                rle.emplace_back(now);
                now.first = s[i];
                now.second = 1;
                if (i == n - 1)
                    rle.emplace_back(now);
            }
        }
        return rle;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solver solver;
    solver.solve();
}
