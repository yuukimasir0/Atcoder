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
typedef long long ll;
typedef long long i64;
typedef int i32;

template <typename T, typename U>
istream &operator>>(istream &i, vc<pair<T, U>> &v)
{
    for (auto &&[j, k] : v)
    {
        i >> j;
        i >> k;
    }
    return i;
}

template <typename T>
istream &operator>>(istream &i, vc<T> &v)
{
    for (auto &&j : v)
        i >> j;
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
    inline void solve()
    {
        i32 n = in();
        i32 a = in(), b = in();
        vc<i32> A(n);
        cin >> A;
        multiset<i32> st;
        for (auto &&i : A)
            st.insert(i);
        while (true)
        {
            auto itrm = st.begin();
            auto itrM = st.end();
            itrM--;
            i32 m = *itrm;
            i32 M = *itrM;
            if (itrm == itrM)
            {
                cout << m << "\n";
                return;
            }
            st.erase(itrm);
            st.erase(itrM);
            if (M - b > m)
            {
                st.insert(M - b);
                st.insert(m + a);
            }
            else
            {
                cout << m << "\n";
                return;
            }
        }
    }

    inline void solve2()
    {
        i32 n = in();
        i32 a = in(), b = in();
        vc<i32> A(n);
        cin >> A;
        sort(all(A));
        i32 ok = 0;
        i32 ng = *A.rbegin() + 1;
        auto check = [&](i32 x)
        {
            i64 t = 0;
            for (i32 i = 0; i < n; i++)
                if (x > A[i] && (x - A[i]) % a != 0)
                    t += (x - A[i]) / a + 1;
                else if (x - A[i] > 0)
                    t += (x - A[i]) / a;
                else
                    t += (x - A[i]) / b;
            return (t <= 0);
        };

        while (ng - ok > 1)
        {
            auto mid = ok + (ng - ok) / 2;
            if (check(mid))
                ok = mid;
            else
                ng = mid;
        }
        cout << ok << '\n';
    }
}
;

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);
    Solver solver;
    solver.solve2();
}
