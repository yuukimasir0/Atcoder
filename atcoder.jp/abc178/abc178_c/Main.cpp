using namespace std;
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "Yes\n";
template <typename T>
using vc = vector<T>;
template <typename T>
using pQ = priority_queue<T, vc<T>, greater<T>>;
template <typename T>
using Pq = priority_queue<T, vc<T>, less<T>>;
template <typename T>
using vv = vc<vc<T>>;
typedef intmax_t ll;
typedef int_fast64_t i64;
typedef int_fast32_t i32;
constexpr ll mod = 1e9 + 7;

template <typename T, typename U>
istream &operator>>(istream &i, vc<pair<T, U>> &v)
{
    for (auto &&[j, k] : v)
    {
        i >> j;
        i >> k;
    }
    return i;
}

template <typename T>
istream &operator>>(istream &i, vc<T> &v)
{
    for (auto &&j : v)
        i >> j;
    return i;
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
        ll n = in();
        ll ans = powmod(10, n, mod) - powmod(9, n, mod) - powmod(9, n, mod) + powmod(8, n, mod);
        ans = (ans % mod + mod) % mod;
        cout << ans << '\n';
    }

    ll powmod(ll a, ll n, ll mod)
    {
        ll ans = 1;
        while (n > 0)
        {
            if (n & 1)
                ans = ans * a % mod;
            a = a * a % mod;
            n >>= 1;
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);
    Solver solver;
    solver.solve();
}
