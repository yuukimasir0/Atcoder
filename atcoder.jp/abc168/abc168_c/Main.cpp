#pragma region header
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define yes cout << "Yes\n";
#define no cout << "No\n";
using namespace std;
typedef long long ll;
constexpr int inf = 2e9;
constexpr ll llinf = 9e18;
#pragma endregion header

double a, b, h, m;

struct Solver
{
  void solve()
  {
    cin >> a >> b >> h >> m;
    h /= 6;
    h += (m / 360);
    m /= 30;
    double rad = abs(h - m);
    if(rad >= 1) {
      rad = 2 - rad;
    }
    rad *= 3.141592653589793238;
    double ans = sqrt (a * a + b * b - 2 * a * b * cos(rad));
    printf("%.18f\n", ans);
  }
};

int main()
{
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solver Solver;
  Solver.solve();
}
