#pragma region
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
// clang-format off
#include <bits/extc++.h>
// #include <atcoder/all>
using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
typedef __int128_t i128;
typedef long long ll;
typedef long long i64;
typedef int i32;
typedef long double ld;
typedef std::pair<int, int> pint;
typedef std::pair<long long, long long> pll;
template<class T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class U> using hash_map = gp_hash_table<T, U>;
#define overload3(_1, _2, _3, name, ...)     name
#define overload4(_1, _2, _3, _4, name, ...) name
#define all1(x) std::begin(x), std::end(x)
#define all2(x, a) std::begin(x), std::begin(x) + a
#define all3(x, a, b) std::begin(x) + a, std::begin(x) + b
#define all(...) overload3(__VA_ARGS__, all3, all2, all1)(__VA_ARGS__)
#define rall1(x) std::rbegin(x), std::rend(x)
#define rall2(x, a) std::rbegin(x), std::rbegin(x) + a
#define rall3(x, a, b) std::rbegin(x) + a, std::rbegin(x) + b
#define rall(...) overload3(__VA_ARGS__, rall3, rall2, rall1)(__VA_ARGS__)
#define rep1(n) for(decltype(n) i = 0; i < n; i++)
#define rep2(i, n) for(decltype(n) i = 0; i < n; i++)
#define rep3(i, a, b) for(decltype(a) i = a; i <  b; i++)
#define rep4(i, a, b, c) for(decltype(a) i = a; i < decltype(a) b; i += decltype(a) c)
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep1(n) for(decltype(n) i = (n - 1); i >= 0; i--)
#define rrep2(i, n) for(decltype(n) i = (n - 1); i >= 0; i--)
#define rrep3(i, a, b) for(decltype(a) i = decltype(a) (b - 1); i >= (a); i--)
#define rrep4(i, a, b, c) for(decltype(a) i = decltype(a) (b - 1); i >= (a); i -= decltype(a) (c))
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define sum(...) accumulate(all(__VA_ARGS__),0LL)
#define LL(...) long long __VA_ARGS__; input(__VA_ARGS__)
#define INT(...) int __VA_ARGS__; input(__VA_ARGS__)
#define ULL(...) unsigned long long __VA_ARGS__; input(__VA_ARGS__)
#define UINT(...) unsigned int __VA_ARGS__; input(__VA_ARGS__)
#define LD(...) long double __VA_ARGS__; input(__VA_ARGS__)
#define STR(...) std::string __VA_ARGS__; input(__VA_ARGS__)
#define vc(class, name, ...) std::vector<class> name(__VA_ARGS__)
#define VC(class, name, size) std::vector<class> name(size); input(name)
#define vv(class, name, H, ...) std::vector name(H, std::vector<class>(__VA_ARGS__))
#define VV(class, name, H, W) std::vector name(H, std::vector<class>(W)); input(name)
#define pq(class, name) std::priority_queue<class, std::vector<class>, std::greater<class>> name
#define Pq(class, name) std::priority_queue<class, std::vector<class>, std::less<class>> name
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
template<class T, class U> std::istream &operator>>(std::istream &_cin, std::pair<T, U> &v) { auto &&[__j, __k] = v; _cin >> __j >> __k; return _cin; }
template<class T> std::istream &operator>>(std::istream &_cin, std::vector<T> &v) { for(auto &&__j : v) _cin >> __j; return _cin; }
template<class T, class... U> void print(T &a, U &...b) { std::cout << a; (std::cout << ... << (std::cout << ' ', b)); std::cout << '\n'; }
template<class T> std::ostream &operator<<(std::ostream &_cout, std::vector<T> &v) { for(const auto &__j : v) _cout << __j << ' '; _cout << '\n'; return _cout; }
template<class T, class U> std::ostream &operator<<(std::ostream &_cout, std::pair<T, U> &v) { const auto &[__j, __k] = v; _cout << __j << ' ' << __k; return _cout; }
long long intpow(long long a, long long n) { long long res = 1; while(n) { if(a & 1) res *= a; a *= a; n >>= 1; } return res; }
long long modpow(long long a, long long n, int mod) { long long res = 1; while(n) { if(a & 1) (res *= a) %= mod; (a *= a) %= mod; n >>= 1; } return (res) %= mod; }
template<class... T> constexpr auto min(T... a) { return min({a...}); }
template<class... T> constexpr auto max(T... a) { return max({a...}); }
template<class T> auto min(const std::vector<T> &a) { return *min_element(a.begin(), a.end()); }
template<class T> auto max(const std::vector<T> &a) { return *max_element(a.begin(), a.end()); }
template<class T, class U> bool chmin(T &a, U b) { return a > (T)b ? a = (T)b, true : false; }
template<class T, class U> bool chmax(T &a, U b) { return a < (T)b ? a = (T)b, true : false; }
// clang-format on
// constexpr int mod = 1e9 + 7; // 998244353;
#pragma endregion

struct dsu {
  private:
    int n;
    vector<int> a;
    vector<long long> w;

  public:
    dsu(int n) :
        n(n),
        a(n + 1, -1),
        w(n + 1, 0) {}

    void init(int i, long long x) {
        w[i] += x;
    }

    int find(int x) {
        if(a[x] < 0) return x;
        return x = a[x];
    }

    bool merge(int x, int y) {
        if(size(x) > size(y)) swap(x, y);
        if(same(x, y)) return false;
        a[find(x)] += a[find(y)];
        a[y] = find(x);
        w[find(x)] += w[find(y)];
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool root(int x) {
        return x == find(x);
    }

    long long weight(int x) {
        return w[x];
    }

    int size(int x) {
        return abs(find(x));
    }
};

struct Solver {
    void solve() {
        LL(N, A, B);
        VC(i64, X, N);
        dsu d(N);
        rep(i, 1, N) if((X[i] - X[i - 1]) * A <= B) d.merge(i, i - 1);
        i64 cnt = 0;
        i64 ans = 0;
        rep(i, 1, N) {
            if(d.same(i, i - 1))
                ans += (X[i] - X[i - 1]) * A;
            else
                ans += B;
            debug(ans);
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