using namespace std;
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "Yes\n";
#define no cout << "No\n";
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
constexpr int inf = 2e9;
constexpr ll llinf = 9e18;

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
        i32 n = in();
        vc<i32> a(n);
        cin >> a;
        auto sum = f(n);
        unordered_map<i32, ll> mp;
        for(auto &&i : a)
            mp[i]++;
        ll ans = 0;
        for(auto &&[key, cnt] : mp)
            ans += sum[cnt];
        for (i32 i = 0; i < n; i++)
        {
            ll temp = ans;
            temp -= sum[mp[a[i]]];
            temp += sum[mp[a[i]] - 1];
            cout << temp << "\n";
        }
    }

    vc<ll> f(i32 n) {
        vc<ll> ans(n+1, 0);
        for (i32 i = 2; i <= n; i++)
            ans[i] = (i * (i - 1)) >> 1;
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
