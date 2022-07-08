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
        ll n = s.length();
        while(1) {
            s = s.substr(0, n - 2);
            n -= 2;
            bool flag = true;
            for (ll i = 0; i < n / 2; i++) {
                if(s[i] != s[i + n/2]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                cout << n << "\n";
                return;
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solver solver;
    solver.solve();
}
