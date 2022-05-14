#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

int main() {
  cin >> s;
  string ans = "";
  while(ans.length() != 6) {
    ans += s;
  }
  cout << ans << endl;
}