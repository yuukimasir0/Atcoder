#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll h, w;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> h >> w;
  vector<vector<ll>> a(h, vector<ll>(w));
  
  for(ll i = 0; i < h; i++)
    for(ll j = 0; j < w; j++)
      cin >> a[i][j];
  
  for(ll i = 0; i < w; i++) {
    for(ll j = 0; j < h; j++)
      cout << a[j][i] << " ";
    cout << "\n";
  }
}