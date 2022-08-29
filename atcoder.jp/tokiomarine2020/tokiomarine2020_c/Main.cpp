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
#define all2(x, a) std::begin(x) + a, std::end(x)
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
#define vc(class, name, ...) std::vector<class> name(__VA_ARGS__)
#define VC(class, name, size) std::vector<class> name(size); input(name)
#define vv(class, name, H, ...) std::vector name(H, std::vector<class>(__VA_ARGS__))
#define VV(class, name, H, W) std::vector name(H, std::vector<class>(W)); input(name)
#define pq(class, name) std::priority_queue<class, std::vector<class>, std::greater<class>> name
#define Pq(class, name) std::priority_queue<class, std::vector<class>, std::less<class>> name
#define println(...) { print(__VA_ARGS__); return; }
#define printif(bool, a, b) { if(bool) print(a); else print(b); }
#ifdef _MASIR0
#define debug(...) __dbg_print(__VA_ARGS__)
#define debugvc(...) __dbg_vc_print(__VA_ARGS__)
#else
#define debug(...) void(0)
#define debugvc(...) void(0)
#endif
template<class... T> void input(T &...a) { (std::cin >> ... >> a); }
template<class T, class U> std::istream &operator>>(std::istream &_cin, std::pair<T, U> &v) { auto &&[__j, __k] = v; _cin >> __j >> __k; return _cin; }
template<class T> std::istream &operator>>(std::istream &_cin, std::vector<T> &v) { for(auto &&__j : v) _cin >> __j; return _cin; }
template<class T, class... U> void print(const T &a, const U &...b) { std::cout << a; (std::cout << ... << (std::cout << ' ', b)); std::cout << '\n'; }
template<class T, class... U> void __dbg_print(T &a, U &...b) { std::cout << a; (std::cout << ... << (std::cout << ' ', b)); }
template<class T, class... U> void __dbg_vc_print(T &a, U &...b) { std::cout << a; (std::cout << ... << (std::cout << '\n', b));}
template<class T> std::ostream &operator<<(std::ostream &_cout, const std::vector<T> &v) { for(const auto &__j : v) _cout << __j << ' '; return _cout; }
template<class T, class U> std::ostream &operator<<(std::ostream &_cout, const std::pair<T, U> &v) { const auto &[__j, __k] = v; _cout << __j << ' ' << __k; return _cout; }
long long intpow(long long a, long long n) { long long res = 1; while(n) { if(n & 1) res *= a; a *= a; n >>= 1; } return res; }
long long modpow(long long a, long long n, int mod) { long long res = 1; while(n) { if(n & 1) (res *= a) %= mod; (a *= a) %= mod; n >>= 1; } res %= mod; return res; }
template<class... T> constexpr auto min(T... a) { return min({a...}); }
template<class... T> constexpr auto max(T... a) { return max({a...}); }
template<class T> auto min(const std::vector<T> &a) { return *min_element(a.begin(), a.end()); }
template<class T> auto max(const std::vector<T> &a) { return *max_element(a.begin(), a.end()); }
template<class T, class U> bool chmin(T &a, U b) { return a > (T)b ? a = (T)b, true : false; }
template<class T, class U> bool chmax(T &a, U b) { return a < (T)b ? a = (T)b, true : false; }
// clang-format on
// constexpr int mod = 1e9 + 7; // 998244353;
#pragma endregion

template<class T>
struct BIT {
  public:
    int n;
    std::vector<T> B1;
    std::vector<T> B2;
    BIT(int _n) :
        n(_n),
        B1(_n + 1, 0),
        B2(_n + 1, 0) {}
    void add(int i, T x) {
        i++;
        if(x == 0) return;
        for(int j = i; j <= n; j += (j & (-j))) B1[j] += x;
    }

    void range_add(int left, int right, T x) {
        if(x == 0) return;
        left++;
        right += 2;
        for(int j = left; j <= n; j += (j & (-j))) B1[j] -= x * (left - 1);
        for(int j = left; j <= n; j += (j & (-j))) B2[j] += x;
        for(int j = right; j <= n; j += (j & (-j))) B1[j] += x * (right - 1);
        for(int j = right; j <= n; j += (j & (-j))) B2[j] -= x;
    }

    T sum(int i) {
        i++;
        T res = 0;
        for(int j = i; j > 0; j -= (j & (-j))) res += B1[j];
        for(int j = i; j > 0; j -= (j & (-j))) res += B2[j] * i;
        return res;
    }

    T sum(int left, int right) {
        right++;
        T res = 0;
        for(int j = right; j > 0; j -= (j & (-j))) res += B1[j];
        for(int j = right; j > 0; j -= (j & (-j))) res += B2[j] * right;
        for(int j = left; j > 0; j -= (j & (-j))) res -= B1[j];
        for(int j = left; j > 0; j -= (j & (-j))) res -= B2[j] * left;
        return res;
    }

    // --ATTENTION-- ここより下の関数は区間更新を一度もしていない場合にのみ正しく機能します. (8/27 時点)

    int lower_bound(T x) {
        if(x <= 0) return 0;
        T left = 0;
        T right = 1;
        while(right < n) right <<= 1;
        for(int i = right; i > 0; i >>= 1) {
            if(left + i < n && B1[left + i] < x) {
                x -= B1[left + i];
                left += i;
            }
        }
        return left;
    }

    int upper_bound(T x) {
        if(x <= 0) return 0;
        T left = 0;
        T right = 1;
        while(right < n) right <<= 1;
        for(int i = right; i > 0; i >>= 1) {
            if(left + i < n && B1[left + i] <= x) {
                x -= B1[left + i];
                left += i;
            }
        }
        return left;
    }

    bool find(T x) {
        auto key = lower_bound(x);
        return x == sum(0, key);
    }
};

struct Solver {
    void solve() {
        LL(N, K);
        BIT<i64> b(N + 1);
        vc(i64, A, N + 1);
        rep(i, 1, N + 1) {
            input(A[i]);
            b.range_add(max(0LL, i - A[i]), min(N, i + A[i]), 1);
        }
        K--;
        rep(_i, K) {
            i64 cnt = 0;
            vc(i64, a, N + 1);
            rep(N + 1) a[i] = b.sum(i, i);
            rep(i, 1, N + 1) b.range_add(max(0LL, i - A[i]), min(N, i + A[i]), -1);
            rep(i, 1, N + 1) b.range_add(max(0LL, i - a[i]), min(N, i + a[i]), 1);
            if(A == a) break;
            A = a;
        }
        rep(i, 1, N + 1) cout << b.sum(i, i) << ' ';
        cout << '\n';
    }
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(15);
    Solver solver;
    rep(1) solver.solve();
}