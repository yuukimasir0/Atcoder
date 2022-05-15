 #include <bits/stdc++.h>
//#pragma GCC target("avx2")
//コンパイラの自動ベクター化遅くなる場合あり

#pragma GCC optimize("03")
//最適化

//#pragma GCC optimize("unroll-loops")
//loop処理の変更遅くなる場合あり

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//浮動小数点使うとき



using namespace std;
typedef long long ll;

ll n;
string s[1009];

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> n;
  for(ll i = 0; i < n; i++)
      cin >> s[i];
  for(ll i = 0; i < n; i++)
    for(ll j = 0; j < n-5; j ++) {
      ll temp = 0;
      if(s[i][j] == '#')
      temp++;
      if(s[i][j+1] == '#')
      temp++;
      if(s[i][j+2] == '#')
      temp++;
      if(s[i][j+3] == '#')
      temp++;
      if(s[i][j+4] == '#')
      temp++;
      if(s[i][j+5] == '#')
      temp++;
      if(temp >= 4) {
        cout << "Yes\n";
        return 0;
      }
    }
  for(ll i = 0; i < n; i++)
    for(ll j = 0; j < n-5; j ++) {
      ll temp = 0;
      if(s[j][i] == '#')
      temp++;
      if(s[j+1][i] == '#')
      temp++;
      if(s[j+2][i] == '#')
      temp++;
      if(s[j+3][i] == '#')
      temp++;
      if(s[j+4][i] == '#')
      temp++;
      if(s[j+5][i] == '#')
      temp++;
      if(temp >= 4) {
        cout << "Yes\n";
        return 0;
      }
    }
  for(ll i = 0; i < n-5; i++)
    for(ll j = 0; j < n-5; j ++) {
      ll temp = 0;
      if(s[i][j] == '#')
      temp++;
      if(s[i+1][j+1] == '#')
      temp++;
      if(s[i+2][j+2] == '#')
      temp++;
      if(s[i+3][j+3] == '#')
      temp++;
      if(s[i+4][j+4] == '#')
      temp++;
      if(s[i+5][j+5] == '#')
      temp++;
      if(temp >= 4) {
        cout << "Yes\n";
        return 0;
      }
    }
  for(ll i = 0; i < n-5; i++)
    for(ll j = 5; j < n; j ++) {
      ll temp = 0;
      if(s[i][j] == '#')
      temp++;
      if(s[i+1][j-1] == '#')
      temp++;
      if(s[i+2][j-2] == '#')
      temp++;
      if(s[i+3][j-3] == '#')
      temp++;
      if(s[i+4][j-4] == '#')
      temp++;
      if(s[i+5][j-5] == '#')
      temp++;
      if(temp >= 4) {
        cout << "Yes\n";
        return 0;
      }
    }
  cout << "No\n";
}
