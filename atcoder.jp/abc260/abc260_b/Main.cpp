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
typedef long long ll;
// constexpr int inf = 2e9;
// constexpr ll llinf = 9e18;

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

template <typename T>
ostream &operator<<(ostream &i, vc<T> &v)
{
    for (auto &&j : v)
        cout << j;
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
        ll n = in(), x = in(), y = in(), z = in();
        Pq<tuple<ll, ll, ll>> s;
        vc<ll> m(n);
        vc<ll> e(n);
        vc<ll> ans;
        cin >> m;
        cin >> e;
        for (ll i = 0; i < n; i++)
            s.push({m[i], n - i, e[i]});
        while (x--)
        {
            auto [ma, nu, en] = s.top();
            s.pop();
            ans.push_back(n - nu);
        }
        Pq<tuple<ll, ll, ll>> E;
        while (s.empty() == false)
        {
            auto [ma, nu, en] = s.top();
            s.pop();
            E.push({en, nu, ma});
        }
        while (y--)
        {
            auto [ma, nu, en] = E.top();
            E.pop();
            ans.push_back(n - nu);
        }
        Pq<pair<ll, ll>> S;
        while (E.empty() == false)
        {
            auto [ma, nu, en] = E.top();
            E.pop();
            S.push({en + ma, nu});
        }
        while (z--)
        {
            auto [sum, nu] = S.top();
            S.pop();
            ans.push_back(n - nu);
        }
        sort(all(ans));
        for (auto &&i : ans)
            cout << i + 1 << '\n';
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