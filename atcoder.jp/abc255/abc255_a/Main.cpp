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
//constexpr int inf = 2e9;
//constexpr ll llinf = 9e18;

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
        ll r = in(), c = in();
        r--;
        c--;
        ll a[2][2];
        cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
        cout << a[r][c] << "\n";
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solver solver;
    solver.solve();
}
