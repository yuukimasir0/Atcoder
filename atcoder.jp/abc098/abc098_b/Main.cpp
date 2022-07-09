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
        map<char, bool> c1;
        ll n = in();
        string s = in();
        ll ans = -1;
        for (ll i = 0; i < n; i++)
        {
            map<char, bool> c2;
            ll temp = 0;
            for (int j = 0; j < i; j++)
                c1[s[j]] = true;
            for (ll j = i; j < n; j++)
                c2[s[j]] = true;
            for(auto &&i : s) {
                if(c1[i] && c2[i]) {
                    temp++;
                    c2[i] = false;
                }
            }
            ans = max(ans, temp);
        }
        cout << ans << '\n';
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solver solver;
    solver.solve();
}
