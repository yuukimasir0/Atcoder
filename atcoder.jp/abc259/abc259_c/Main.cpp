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
        string s = in(), t = in();
        ll n = s.length();
      
        reverse(all(s));
        reverse(all(t));
        for (ll i = 0; i < n; i++) {
            if(s[i] == t[i])
                continue;
            if(i >= 2 && s[i-1] == s[i-2] && s[i-1] == t[i]) {
                s = s.substr(0, i) + s[i - 1] + s.substr(i, n);
                n++;
            } else {
                no return;
            }
        }
        yes
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solver solver;
    solver.solve();
}
