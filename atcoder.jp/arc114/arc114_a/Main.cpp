#pragma region
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
// clang-format off
#include <bits/extc++.h>
typedef long long ll;
typedef long long i64;
typedef int i32;
typedef long double ld;
typedef std::pair<int, int> pint;
typedef std::pair<long long, long long> pll;
#define overload3(_1, _2, _3, name, ...)     name
#define overload4(_1, _2, _3, _4, name, ...) name
#define all1(x) (x).begin(), (x).end()
#define all2(x, a) (x).begin(), (x).begin() + a
#define all3(x, a, b) (x).begin() + a, (x).begin() + b
#define all(...) overload3(__VA_ARGS__, all3, all2, all1)(__VA_ARGS__)
#define rall1(x) (x).rbegin(), (x).rend()
#define rall2(x, a) (x).rbegin(), (x).rbegin() + a
#define rall3(x, a, b) (x).rbegin() + a, (x).rbegin() + b
#define rall(...) overload3(__VA_ARGS__, rall3, rall2, rall1)(__VA_ARGS__)
#define rep1(n) for(int i = 0; i < n; i++)
#define rep2(i, n) for(int i = 0; i < n; i++)
#define rep3(i, a, b) for(int i = a; i < b; i++)
#define rep4(i, a, b, c) for(int i = a; i < b; i += c)
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep1(n) for(int i = (n - 1); i >= 0; i--)
#define rrep2(i, n) for(int i = (n - 1); i >= 0; i--)
#define rrep3(i, a, b) for(int i = (b - 1); i >= (a); i--)
#define rrep4(i, a, b, c) for(int i = (b - 1); i >= (a); i -= (c))
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define LL(...) long long __VA_ARGS__; input(__VA_ARGS__)
#define INT(...) int __VA_ARGS__; input(__VA_ARGS__)
#define ULL(...) unsigned long long __VA_ARGS__; input(__VA_ARGS__)
#define UINT(...) unsigned int __VA_ARGS__; input(__VA_ARGS__)
#define LD(...) long double __VA_ARGS__; input(__VA_ARGS__)
#define STR(...) std::string __VA_ARGS__; input(__VA_ARGS__)
#define VC(class, name, size) std::vector<class> name(size); input(name)
#define println(...) { print(__VA_ARGS__); return; }
#define printif(bool, a, b) { if(bool) print(a); else print(b); }
#ifdef _MASIR0
#define debug(...) print(__VA_ARGS__)
#define debugvc(a) std::cout << a
#else
#define debug(...) void(0)
#define debugvc(a) void(0)
#endif
template<class... T> void input(T &...a) { (std::cin >> ... >> a); }
template<class T, class U> std::istream &operator>>(std::istream &i, std::pair<T, U> &v) { auto &&[j, k] = v; i >> j >> k; return i; }
template<class T> std::istream &operator>>(std::istream &i, std::vector<T> &v) { for(auto &&j : v) i >> j; return i; }
template<class T, class... U> void print(T &a, U &...b) { std::cout << a; (std::cout << ... << (std::cout << ' ', b)); std::cout << '\n'; }
template<class T> std::ostream &operator<<(std::ostream &i, std::vector<T> &v) { for(auto &&j : v) std::cout << j << ' '; std::cout << '\n'; return i; }
template<class... T> constexpr auto min(T... a) { return min(std::initializer_list<std::common_type_t<T...>>{a...}); }
template<class... T> constexpr auto max(T... a) { return max(std::initializer_list<std::common_type_t<T...>>{a...}); }
template<class T> auto min(const std::vector<T> &a) { return *min_element(a.begin(), a.end()); }
template<class T> auto max(const std::vector<T> &a) { return *max_element(a.begin(), a.end()); }
template<class T> bool chmin(T &a, T b) { return a > b ? a = b, true : false; }
template<class T> bool chmax(T &a, T b) { return a < b ? a = b, true : false; }
template<class T, class U> bool chmin(T &a, U b) { return a > (T)b ? a = (T)b, true : false; }
template<class T, class U> bool chmax(T &a, U b) { return a < (T)b ? a = (T)b, true : false; }
template<class T> using vc = std::vector<T>;
template<class T> using vv = std::vector<std::vector<T>>;
template<class T> using pq = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template<class T> using PQ = std::priority_queue<T, std::vector<T>, std::less<T>>;
using namespace std;
// clang-format on
// constexpr int mod = 1e9 + 7; // 998244353;
#pragma endregion

struct Solver {
    void solve() {
        LL(N);
        VC(i64, X, N);
        i64 ans = LLONG_MAX;
        vc<i64> p;
        rep(i, 2, 51) {
            bool flag = true;
            for(const auto &c : p)
                if(i % c == 0) {
                    flag = false;
                    break;
                }
            if(flag) p.push_back(i);
        }
        auto n = p.size();
        rep(1 << n) {
            vc<i32> list;
            auto flag = true;
            i64 res = 1;
            rep(j, n) if(i & (1 << j)) list.push_back(j);
            for(const auto &j : list) res *= p[j];
            rep(j, N) if(gcd(res, X[j]) == 1) flag = false;
            if(flag) chmin(ans, res);
        }
        print(ans);
    }
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(15);
    Solver solver;
    rep(1) solver.solve();
}