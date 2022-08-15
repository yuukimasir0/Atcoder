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

#define LD(...) \
ld __VA_ARGS__; \
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

#ifdef _MASIR0
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
template<typename T, typename U> bool chmin(T &a, U b) { return a > (T)b ? a = (T)b, true : false; }
template<typename T> bool chmax(T &a, T b) { return a < b ? a = b, true : false; }

template<typename T> using vc = vector<T>;
template<typename T> using pQ = priority_queue<T, vc<T>, greater<T>>;
template<typename T> using Pq = priority_queue<T, vc<T>, less<T>>;
template<typename T> using vv = vc<vc<T>>;

typedef long long ll;
typedef long long i64;
typedef int i32;
typedef long double ld;
constexpr i32 mod = 998244353;
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
        LL(X, Y, R);
        LL(x1, y1, x2, y2);
        bool red = true;
        bool blue = true;
        auto f = [](i64 x, i64 y) {
            return x * x + y * y;
        };

        if(x1 <= X - R && X + R <= x2 && y1 <= Y - R && Y + R <= y2) red = false;
        if(f(x1 - X, y1 - Y) <= R * R && f(x1 - X, y2 - Y) <= R * R && f(x2 - X, y1 - Y) <= R * R && f(x2 - X, y2 - Y) <= R * R) blue = false;
        puts(red ? "YES" : "NO");
        puts(blue ? "YES" : "NO");
    }
};

signed main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);
    Solver solver;
    solver.solve();
}