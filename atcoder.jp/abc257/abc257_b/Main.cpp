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
// constexpr int inf = 2e9;
// constexpr ll llinf = 9e18;
// constexpr double pi = 3.141592653589793238462643383279

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
        ll n = in(), k = in(), q = in();
        vc<ll> a(k);
        vc<bool> move(k, false);
        for (auto &&i : a)
            i = in();
        for (int i = 0; i < n - 1; i++)
            if (a[i + 1] - a[i] > 1)
                move[i] = true;
        if (n != a[k - 1])
            move[k - 1] = true;
        while (q--)
        {
            ll l = in();
            l--;
            if (move[l])
                a[l]++;
            for (int i = 0; i < n - 1; i++)
                if (a[i + 1] - a[i] > 1)
                    move[i] = true;
                else
                    move[i] = false;
            if (n != a[k - 1])
                move[k - 1] = true;
            else
                move[k - 1] = false;
        }
        for (auto &&i : a)
            cout << i << " ";
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
