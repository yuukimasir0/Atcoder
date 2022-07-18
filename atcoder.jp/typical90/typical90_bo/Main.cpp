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
typedef intmax_t ll;
typedef long long i64;
typedef int i32;
// constexpr int inf = 2e9;
// constexpr ll llinf = 9e18;

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
    string n = in();
    i32 k = in();
    if (n == "0")
    {
      cout << "0" << '\n';
      return;
    }
    while (k--)
      n = exc9(n);
    i32 N = n.size();
    if (n[0] != '0')
      cout << n[0];
    for (i32 i = 1; i < N; i++)
      cout << n[i];
  }

  string exc9(string n)
  {
    string s = "";
    i64 N = exc10(n);
    while (N)
    {
      s = to_string(N % 9) + move(s);
      N /= 9;
    }
    for (auto &&i : s)
      if (i == '8')
        i = '5';
    return s;
  }

  i64 exc10(string n)
  {
    i64 res = 0;
    for (auto &&s : n)
    {
      res *= 8;
      res += (s - '0');
    }
    return res;
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