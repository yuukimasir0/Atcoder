#pragma region
using namespace std;
#include <bits/extc++.h>

#define overload3(_1, _2, _3, name, ...)     name
#define overload4(_1, _2, _3, _4, name, ...) name

#define all(x) (x).begin(), (x).end()
//#define all2(x, a)    (x).begin(), (x).begin() + a
//#define all3(x, a, b) (x).begin() + a, (x).begin() + b
//#define all(...)      overload3(__VA_ARGS_, all3, all2, all1)(__VA_ARGS_)

#define rall(x) (x).rbegin(), (x).rend()
//#define rall2(x, a)    (x).rbegin(), (x).rbegin() + a
//#define rall3(x, a, b) (x).rbegin() + a, (x).rbegin() + b
//#define rall(...)      overload3(__VA_ARGS_, rall3, rall2, rall1)(__VA_ARGS_)

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

#define LL(...)        \
long long __VA_ARGS__; \
input(__VA_ARGS__)

#define INT(...) \
int __VA_ARGS__; \
input(__VA_ARGS__)

#define ULL(...)                \
unsigned long long __VA_ARGS__; \
input(__VA_ARGS__)

#define UINT(...)         \
unsigned int __VA_ARGS__; \
input(__VA_ARGS__)

#define STR(...)    \
string __VA_ARGS__; \
input(__VA_ARGS__)

#define VC(class, name, size) \
vector<class> name(size);     \
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
template<class T> auto min(const vector<T> &a) { return *min_element(a.begin(), a.end()); }
template<class T> auto max(const vector<T> &a) { return *max_element(a.begin(), a.end()); }

template<class... T> void input(T &...a) { (cin >> ... >> a); }
template<class T> bool chmin(T &a, T b) { return a > b ? a = b, true : false; }
template<class T> bool chmax(T &a, T b) { return a < b ? a = b, true : false; }
template<class T, class U> bool chmin(T &a, U b) { return a > (T)b ? a = (T)b, true : false; }
template<class T, class U> bool chmax(T &a, U b) { return a < (T)b ? a = (T)b, true : false; }

template<class T> using vc = vector<T>;
template<class T> using pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> using PQ = priority_queue<T, vector<T>, less<T>>;
template<class T> using vv = vector<vector<T>>;

typedef long long ll;
typedef long long i64;
typedef int i32;
typedef long double ld;
// constexpr int mod = 1e9 + 7; // 998244353;
template<class T, class U> istream &operator>>(istream &i, pair<T, U> &v) {
    auto &&[j, k] = v;
    i >> j;
    i >> k;
    return i;
}
template<class T> istream &operator>>(istream &i, vector<T> &v) {
    for(auto &&j : v) i >> j;
    return i;
}
template<class T> ostream &operator<<(ostream &i, vector<T> &v) {
    for(const auto &j : v) cout << j << ' ';
    cout << '\n';
    return i;
}
#pragma endregion

struct Solver {
    void solve() {
        LL(N, M);
        vv<i64> g(N + 1);
        i64 ans = 0;
        rep(N + 1) g[i].push_back(i);
        rep(M) {
            LL(x, y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        //rep(N + 1)cout << g[i];
        rep(1 << N) {
            i64 now = 1;
            vc<i64> temp;
            auto bit = i;
            bool ext = true;
            while(bit) {
                if(bit & 1) temp.push_back(now);
                now++;
                bit >>= 1;
            }
            for(const auto &j : temp) {
                for(const auto &k : temp) {
                    auto n = g[j].size();
                    bool flag = false;
                    rep(l, n) {
                        if(g[j][l] == k) {
                            flag = true;
                            break;
                        }
                    }
                    if(flag == false) {
                        ext = false;
                        break;
                    }
                }
                if(ext == false) break;
            }
            if(ext) {
                chmax(ans, temp.size());
                //cout << temp;
            }
        }
        print(ans);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);
    Solver solver;
    rep(1) solver.solve();
}