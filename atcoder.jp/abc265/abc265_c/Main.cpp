#pragma region
using namespace std;
#include <bits/extc++.h>

#define overload3(_1, _2, _3, name, ...)     name
#define overload4(_1, _2, _3, _4, name, ...) name

#define all1(x)       (x).begin(), (x).end()
#define all2(x, a)    (x).begin(), (x).begin() + a
#define all3(x, a, b) (x).begin() + a, (x).begin() + b
#define all(...)      overload3(__VA_ARGS__, all3, all2, all1)(__VA_ARGS__)

#define rall1(x)       (x).rbegin(), (x).rend()
#define rall2(x, a)    (x).rbegin(), (x).rbegin() + a
#define rall3(x, a, b) (x).rbegin() + a, (x).rbegin() + b
#define rall(...)      overload3(__VA_ARGS__, rall3, rall2, rall1)(__VA_ARGS__)

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

#define LD(...)          \
long double __VA_ARGS__; \
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
#define debugvc(a) cout << a
#else
#define debug(...)
#define debugvc(a)
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
    for(auto &&j : v) cout << j << ' ';
    cout << '\n';
    return i;
}
#pragma endregion

struct Solver {
    void solve() {
        LL(H, W);
        vv<char> G(H + 1, vc<char>(W + 1));
        rep(i, 1, H + 1) rep(j, 1, W + 1) input(G[i][j]);
        map<pair<i32, i32>, bool> mp;
        mp[{1, 1}] = true;
        pair<i32, i32> now = {1, 1};
        while(true) {
            auto &&[i, j] = now;
            if(G[i][j] == 'U' && i != 1) {
                i -= 1;
            } else if(G[i][j] == 'D' && i != H) {
                i += 1;
            } else if(G[i][j] == 'L' && j != 1) {
                j -= 1;
            } else if(G[i][j] == 'R' && j != W) {
                j += 1;
            } else {
                print(i, j);
                return;
            }
            debug(i, j);
            if(mp[now]) {
                print("-1");
                return;
            }
            mp[now] = true;
        }
    }

    void solve2() {
        LL(H, W);
        vv<char> G(H + 1, vc<char>(W + 1));
        rep(i, 1, H + 1) rep(j, 1, W + 1) input(G[i][j]);
        unordered_map<i32, bool> mp;
        mp[1] = true;
        pair<i32, i32> now = {1, 1};
        while(true) {
            auto &&[i, j] = now;
            if(G[i][j] == 'U' && i != 1) i -= 1;
            else if(G[i][j] == 'D' && i != H) i += 1;
            else if(G[i][j] == 'L' && j != 1) j -= 1;
            else if(G[i][j] == 'R' && j != W) j += 1;
            else {
                print(i, j);
                return;
            }
            debug(i, j);
            if(mp[i * H + j]) {
                print("-1");
                return;
            }
            mp[i * H + j] = true;
        }
    }
};

signed main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);
    Solver solver;
    rep(1) solver.solve2();
}