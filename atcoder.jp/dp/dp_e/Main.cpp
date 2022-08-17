#pragma region
using namespace std;
#include <bits/stdc++.h>

#define overload4(_1, _2, _3, _4, name, ...) name

#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define rep1(n)          for(int i = 0; i < n; i++)
#define rep2(i, n)       for(int i = 0; i < n; i++)
#define rep3(i, a, b)    for(int i = a; i < b; i++)
#define rep4(i, a, b, c) for(int i = a; i < b; i += c)
#define rep(...)         overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define rrep1(n)          for(int i = (n - 1); i >= 0; i--)
#define rrep2(i, n)       for(int i = (n - 1); i >= 0; i--)
#define rrep3(i, a, b)    for(int i = (b - 1); i >= (a); i--)
#define rrep4(i, a, b, c) for(int i = (b - 1); i >= (a); i -= (c))
#define rrep(...)         overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)

#define LL(...)  \
i64 __VA_ARGS__; \
input(__VA_ARGS__)

#define STR(...)    \
string __VA_ARGS__; \
input(__VA_ARGS__)

#define VC(typename, name, size) \
vc<typename> name(size);         \
input(name);

template<class T, class... U> void print(T &a, U &...b) {
    cout << a;
    (cout << ... << (cout << ' ', b));
    cout << '\n';
}

#ifdef _CAT
#define debug(...) print(__VA_ARGS__)
#else
#define debug(...)
#endif

template<class... T> constexpr auto min(T... a) { return min(initializer_list<common_type_t<T...>>{a...}); }
template<class... T> constexpr auto max(T... a) { return max(initializer_list<common_type_t<T...>>{a...}); }
template<class T> auto min(const T &a) { return *min_element(all(a)); }
template<class T> auto max(const T &a) { return *max_element(all(a)); }

template<class... T> void input(T &...a) { (cin >> ... >> a); }
template<typename T> bool chmin(T &a, T b) { return a > b ? a = b, true : false; }
template<typename T> bool chmax(T &a, T b) { return a < b ? a = b, true : false; }

template<typename T> using vc = vector<T>;
template<typename T> using pQ = priority_queue<T, vc<T>, greater<T>>;
template<typename T> using Pq = priority_queue<T, vc<T>, less<T>>;
template<typename T> using vv = vc<vc<T>>;

typedef long long ll;
typedef long long i64;
typedef int i32;
typedef long double ld;
// constexpr i32 mod = 1e9 + 7; // 998244353;
template<typename T, typename U> istream &operator>>(istream &i, pair<T, U> &v) {
    auto &&[j, k] = v;
    i >> j;
    i >> k;
    return i;
}
template<typename T> istream &operator>>(istream &i, vc<T> &v) {
    for(auto &&j : v) i >> j;
    return i;
}
template<typename T> ostream &operator<<(ostream &i, vc<T> &v) {
    for(auto &&j : v) cout << j << ' ';
    cout << '\n';
    return i;
}
#pragma endregion

struct Solver {
    void solve() {
        LL(N, W);
        vc<i64> w(N), v(N);
        rep(N) input(w[i], v[i]);
        i32 MAX_V = N * max(v);
        vv<i64> dp(N, vc<i64>(MAX_V + 1, LLONG_MAX));
        dp[0][v[0]] = w[0];
        dp[0][0] = 0;
        rep(i, 1, N) rep(j, MAX_V + 1) {
            if(j >= v[i] && dp[i - 1][j - v[i]] != LLONG_MAX)
                chmin(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
            chmin(dp[i][j], dp[i - 1][j]);
        }
        rrep(i, MAX_V + 1) {
            debug(i, dp[N - 1][i]);
            if(dp[N - 1][i] <= W) {
                print(i);
                return;
            }
        }
    }
};

signed main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);
    Solver solver;
    solver.solve();
}