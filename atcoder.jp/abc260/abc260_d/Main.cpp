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
        ll n = in(), k = in();
        vc<ll> nxt(n, -1);
        vc<ll> cnt(n);
        vc<ll> ans(n, -1);
        set<ll> st;
        for (ll i = 0; i < n; i++)
        {
            ll p = in();
            p--;
            auto it = st.lower_bound(p);
            if (it == st.end())
            {
                cnt[p] = 1;
            }
            else
            {
                ll m = *it;
                nxt[p] = m;
                cnt[p] = cnt[m] + 1;
                st.erase(it);
            }
            if (cnt[p] == k)
            {
                ll j = p;
                while (j != -1)
                {
                    ans[j] = i + 1;
                    j = nxt[j];
                }
            }
            else
                st.insert(p);
        }
        for (auto &&i : ans)
            cout << i << "\n";
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