#pragma region header
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
constexpr int inf = 2e9;
constexpr ll llinf = 9e18;
#pragma endregion header

ll q;
string s;

int main()
{
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> q;
  set<ll> st;
  map<ll, ll> ans;
  while (q--)
  {
    int num;
    int x, c;
    cin >> num;
    if (num == 1)
    {
      cin >> x;
      st.insert(x);
      ans[x]++;
    }
    else if (num == 2)
    {
      cin >> x >> c;
      if (c >= ans[x])
      {
        ans[x] = 0;
        st.erase(x);
      }
      else
      {
        ans[x] -= c;
      }
    }
    else
    {
      cout << *st.rbegin() - *st.begin() << "\n";
    }
  }
}
