#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M, K;
ll const MOD = 998244353;
ll dp[55][2505];

int main(){
  cin >> N >> M >> K;
  dp[0][0] = 1;
  for(ll i = 0; i < N; i++)
    for(ll j = 0; j < K; j++)
      for(ll k = 1; k <= M; k++) {
        if(j + k <= K) {
          dp[i+1][j+k] += dp[i][j];
          dp[i+1][j+k] %= MOD;
        }
      }
  ll ans = 0;
  for(ll i = 1; i <= K; i++) {
    ans += dp[N][i];
    ans %= MOD;
  }
  cout << ans << endl;
}