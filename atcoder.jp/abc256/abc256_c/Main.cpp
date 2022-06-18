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
        int n = 3;
        vc<int> h(n);
        vc<int> w(n);
        int ans = 0;
        for (auto &&i : h)
            i = in();
        for (auto &&i : w)
            i = in();

        for (int a = 1; a < h[0] - 1; a++)
            for (int c = 1; c < w[0] - a; c++)
                for (int g = 1; g < h[0] - a; g++)
                    for (int i = 1; i < min(h[2] - c, w[2] - g); i++)
                    {
                        int b = w[0] - a - c;
                        int d = h[0] - a - g;
                        int f = h[2] - c - i;
                        int j = w[2] - g - i;
                        if (b <= 0 || d <= 0 || f <= 0 || j <= 0)
                            continue;
                        if (h[1] - b - j == w[1] - d - f && h[1] - b - j > 0)
                            ans++;
                    }

        cout << ans << "\n";
    }
};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solver solver;
    solver.solve();
}
