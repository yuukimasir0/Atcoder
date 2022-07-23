using namespace std;
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

struct Solver
{
    void solve()
    {
        i32 n = in();
        vc<string> S(n);
        cin >> S;
        string yes = "correct";
        string no = "incorrect";
        for (i32 i = 0; i < n; i++)
            for (i32 j = i + 1; j < n; j++)
                if (i != j)
                {
                    if (S[i][j] == 'W' && S[j][i] == 'W')
                    {
                        cout << no << '\n';
                        return;
                    }
                    else if (S[i][j] == 'L' && S[j][i] == 'L')
                    {
                        cout << no << '\n';
                        return;
                    }
                    else if (S[i][j] == 'D' && S[j][i] == 'L')
                    {
                        cout << no << '\n';
                        return;
                    }
                    else if (S[i][j] == 'L' && S[j][i] == 'D')
                    {
                        cout << no << '\n';
                        return;
                    }
                    else if (S[i][j] == 'D' && S[j][i] == 'W')
                    {
                        cout << no << '\n';
                        return;
                    }
                    else if (S[i][j] == 'W' && S[j][i] == 'D')
                    {
                        cout << no << '\n';
                        return;
                    }
                }
        cout << yes << '\n';
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