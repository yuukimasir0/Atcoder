#pragma region template
// clang-format off
#ifdef _MASIR0
#define _GLIBUXX_DEBUG
#define debug(...) __dbg_print(__VA_ARGS__)
#define debugvc(...) __dbg_vc_print(__VA_ARGS__)
#define LOCAL__INIT__ std::chrono::system_clock::time_point start = std::chrono::system_clock::now()
#define EXECUTION__TIME__ std::chrono::system_clock::time_point end = std::chrono::system_clock::now(); int64_t time = std::chrono::duration_cast<std::chrono::seconds>(end - start).count(); print("Execution Time: ", time, "ms")
#define __LOCAL_TEST__ solver.test()
#else
#define debug(...) void(0)
#define debugvc(...) void(0)
#define LOCAL__INIT__ void(0)
#define EXECUTION__TIME__ void(0)
#define __LOCAL_TEST__ void(0)
#endif
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma once
#include <bits/extc++.h>
#include <atcoder/all>
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
typedef vector<vector<int>> graph;
typedef atcoder::static_modint<1000000007> Modint;
template<class T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class U> using hash_map = gp_hash_table<T, U>;
#define overload3(_1, _2, _3, name, ...) name
#define overload4(_1, _2, _3, _4, name, ...) name
#define overload5(_1, _2, _3, _4, _5, name, ...) name
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
#define rep3(i, a, b) for(decltype(b) i = a; i < b; i++)
#define rep4(i, a, b, c) for(decltype(b) i = a; i < b; i += c)
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep1(n) for(decltype(n) i = (n - 1); i >= 0; i--)
#define rrep2(i, n) for(decltype(n) i = (n - 1); i >= 0; i--)
#define rrep3(i, a, b) for(decltype(a) i = (b - 1); i >= (a); i--)
#define rrep4(i, a, b, c) for(decltype(a) i = (b - 1); i >= (a); i -= (c))
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define each1(a, v) for(auto &&a : v)
#define each2(a, b, v) for(auto &&[a, b] : v)
#define each3(a, b, c, v) for(auto &&[a, b, c] : v)
#define each(...) overload4(__VA_ARGS__, each3, each2, each1)(__VA_ARGS__)
#define LL(...) long long __VA_ARGS__; input(__VA_ARGS__)
#define INT(...) int __VA_ARGS__; input(__VA_ARGS__)
#define ULL(...) unsigned long long __VA_ARGS__; input(__VA_ARGS__)
#define UINT(...) unsigned int __VA_ARGS__; input(__VA_ARGS__)
#define LD(...) long double __VA_ARGS__; input(__VA_ARGS__)
#define STR(...) std::string __VA_ARGS__; input(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__; input(__VA_ARGS__)
#define vc1(class, name) std::vector<class> name
#define vc2(class, name, ...) std::vector<class> name(__VA_ARGS__)
#define vc(...) overload4(__VA_ARGS__, vc2, vc2, vc1 )(__VA_ARGS__) 
#define VC(class, name, size) std::vector<class> name(size); input(name)
#define vv(class, name, H, ...) std::vector name(H, std::vector<class>(__VA_ARGS__))
#define VV(class, name, H, W) std::vector name(H, std::vector<class>(W)); input(name)
#define vvv(class, naame, H, W, ...) vector name(H, vector<vector<class>>(W, vector<class>(__VA_ARGS__)));
#define pq(class, name) std::priority_queue<class, std::vector<class>, std::greater<class>> name
#define Pq(class, name) std::priority_queue<class, std::vector<class>, std::less<class>> name
#define END(...) do{ print(__VA_ARGS__); return; }while(0)
#define printif(bool, a, b) do{ if(bool) print(a); else print(b); } while(0)
template<class... T> void input(T &...a) { (std::cin >> ... >> a); }
template<class T, class U> std::istream &operator>>(std::istream &_cin, std::pair<T, U> &v) { auto &&[__j, __k] = v; _cin >> __j >> __k; return _cin; }
template<class T> std::istream &operator>>(std::istream &_cin, std::vector<T> &v) { for(auto &&__j : v) _cin >> __j; return _cin; }
template<class T, class... U> void print(const T &a, const U &...b) { std::cout << a; (std::cout << ... << (std::cout << ' ', b)); std::cout << '\n'; }
template<class T, class... U> void __dbg_print(T &a, U &...b) { std::cout << a; (std::cout << ... << (std::cout << ' ', b)); }
template<class T, class... U> void __dbg_vc_print(T &a, U &...b) { std::cout << a; (std::cout << ... << (std::cout << '\n', b)); }
template<class T> std::ostream &operator<<(std::ostream &_cout, const std::vector<T> &v) { auto vector_it = v.begin(); for(;;) {cout << *vector_it++ << (vector_it == v.end() ? '\n' : ' '); if(vector_it == v.end()) break;} return _cout;}
template<class T> std::ostream &operator<<(std::ostream &_cout, const std::vector<vector<T>> &v) { auto vector_it = v.begin(); for(;;) {cout << *vector_it++; if(vector_it == v.end()) break;} return _cout;}
template<class T, class U> std::ostream &operator<<(std::ostream &_cout, const std::pair<T, U> &v) { const auto &[__j, __k] = v; _cout << __j << ' ' << __k; return _cout; }
long long intpow(long long a, long long n) { long long res = 1; while(n) { if(n & 1) res *= a; a *= a; n >>= 1; } return res; }
long long modpow(long long a, long long n, int mod) { long long res = 1; while(n) { if(n & 1) res = res * a % mod; a = a * a % mod; n >>= 1; } return res; }
template<class... T> constexpr auto min(T... a) { return min(initializer_list<common_type_t<T...>>{a...}); }
template<class... T> constexpr auto max(T... a) { return max(initializer_list<common_type_t<T...>>{a...}); }
template<class T> auto min(const std::vector<T> &a) { return *min_element(a.begin(), a.end()); }
template<class T> auto max(const std::vector<T> &a) { return *max_element(a.begin(), a.end()); }
template<class T, class U> bool chmin(T &a, U b) { return a > (T)b ? a = (T)b, true : false; }
template<class T, class U> bool chmax(T &a, U b) { return a < (T)b ? a = (T)b, true : false; }
// clang-format on
constexpr long long LL_INF = 0x7fffffff00000000LL;
constexpr int mod = 1e9 + 7; // 998244353;

template<class T, T (*op)(T, T), T (*e)()> struct segtree {
  public:
    segtree() :
        segtree(0) {}
    segtree(int n) :
        segtree(std::vector<T>(n, e())) {}
    segtree(const std::vector<T> &v) :
        _n(int(v.size())) {
        log = 1;
        while(_n > 1 << log) log++;
        size = 1 << log;
        d = std::vector<T>(2 * size, e());
        for(int i = 0; i < _n; i++) d[size + i] = v[i];
        for(int i = size - 1; i > 0; i--) {
            update(i);
        }
    }

    void set(int p, int x) {
        p += size;
        d[p] = x;
        for(int i = 1; i <= log; i++) update(p >> i);
    }

    T get(int p) {
        return d[p + size];
    }

    T prod(int l, int r) {
        if(l == 0 && r == _n) return d[1];
        T sml = e(), smr = e();
        l += size;
        r += size;

        while(l < r) {
            if(l & 1) sml = op(sml, d[l++]);
            if(r & 1) smr = op(smr, d[--r]);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }
    T all_prod() { return d[1]; }

  private:
    int _n, size, log;
    std::vector<T> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};
#pragma endregion template

struct Solver {
    void solve() {
        INT(N, M);
        VC(string, S, N);
        sort(all(S));
        do {
            rep(N - 1) {
                int count = 0;
                rep(j, M) {
                    if(S[i][j] != S[i + 1][j]) count++;
                    if(count > 1) goto L1;
                }
                if(count == 0) goto L1;
            }
            END("Yes");
        L1:;
        } while(next_permutation(all(S)));
        print("No");
    }

    void test() {}
};

signed main() {
    LOCAL__INIT__;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(15);
    Solver solver;
    int _task = 1;
    // cin >> _task;
    rep(_task) solver.solve();
    __LOCAL_TEST__;
    EXECUTION__TIME__;
    return 0;
}