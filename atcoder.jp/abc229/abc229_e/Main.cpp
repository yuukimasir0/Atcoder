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
typedef long long i64;
typedef int i32;
// constexpr i32 inf = 2e9;
// constexpr i64 llinf = 9e18;
// constexpr i32 mod =

template <typename T, typename U>
istream &operator>>(istream &i, pair<T, U> &v)
{
    auto &&[j, k] = v;
    i >> j;
    i >> k;
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

struct UnionFind
{
private:
    i32 n;
    vector<i32> parent;

public:
    UnionFind(i32 n) : n(n), parent(n, -1) {}
    i32 root(i32 x)
    {
        if (parent[x] < 0)
            return x;
        return parent[x] = root(parent[x]);
    }
    void merge(i32 x, i32 y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return;
        if (parent[x] > parent[y])
            swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
    }
    bool same(i32 x, i32 y)
    {
        return root(x) == root(y);
    }
    i32 size(i32 x)
    {
        return -parent[root(x)];
    }
};

struct Solver
{
    void solve()
    {
        i32 n = in(), m = in();
        vv<i32> g(n + 1);
        deque<i32> ans(1, 0);
        UnionFind uf(n + 1);
        for (i32 i = 0; i < m; i++)
        {
            i32 a = in(), b = in();
            g[a].push_back(b);
        }
        i64 now = 0;
        for (i32 i = n; i > 1; i--)
        {
            now++;
            for(auto &&v : g[i]) {
                if(uf.same(i, v) == false)
                {
                    uf.merge(i, v);
                    now--;
                }
            }
            ans.push_front(now);
        }
        while(ans.empty() == false)
        {
            cout << ans.front() << '\n';
            ans.pop_front();
        }
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