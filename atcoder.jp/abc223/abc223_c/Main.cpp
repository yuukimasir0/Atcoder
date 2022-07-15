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
        ll n = in();
        vc<ll> a(n);
        vc<ll> b(n);
        vc<double> time(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
            time[i] = (double)a[i] / b[i];
        }
        double conf = 0;
        for(auto &&i : time)
            conf += i;
        conf /= 2;
        double ans = 0;
        for (ll i = 0; i < n; i++)
        {
            ans += min((double)a[i], b[i] * conf);
            conf -= min(time[i], conf);
            if(conf <= 0)
                break;
        }
        cout << ans << "\n";
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
