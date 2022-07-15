using namespace std;
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "Yes\n";
#define no cout << "No\n";
template <typename T>
using vc = vector<T>;
template <typename T>
using pq = priority_queue<T, vc<T>, greater<T>>;
template <typename T>
using PQ = priority_queue<T, vc<T>, less<T>>;
template <typename T>
using vv = vc<vc<T>>;
typedef long long ll;
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
        ll n = in(), m = in();
        vv<ll> g(n);
        vc<ll> cnt(n, 0);
        for (ll i = 0; i < m; i++)
        {
            ll a = in(), b = in();
            a--;
            b--;
            g[a].push_back(b);
            cnt[b]++;
        }
        pq<ll> q;
        vc<ll> ans;
        for (ll i = 0; i < n; i++)
            if(cnt[i] == 0)
                q.push(i);
        while(q.size())
        {
            ll t = q.top();
            q.pop();
            ans.push_back(t);
            for(auto &&i : g[t])
            {
                cnt[i]--;
                if(cnt[i] == 0)
                    q.push(i);
            }
        }
        if(ans.size() != n)
            cout << -1;
        else
            for(auto &&i : ans)
                cout << i + 1 << " ";
        cout << "\n";
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solver solver;
    solver.solve();
}
