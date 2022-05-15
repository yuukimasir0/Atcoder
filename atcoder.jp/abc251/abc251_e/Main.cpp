#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll a[300009];
ll dp[300009][2];
ll const inf = 1e18;

int main() {
  cin >> n;
  for(ll i = 0; i < n; i++)
    cin >> a[i];
  dp[0][0] = 0;
  dp[0][1] = inf;
  ll ans = inf;
  for(ll i = 1; i < n; i++) {
    dp[i][0] = dp[i-1][1];
	dp[i][1] = min(dp[i-1][1] + a[i], dp[i-1][0] + a[i]);
  }
  ans = min(ans, dp[n-1][1]);
  dp[0][0] = inf;
  dp[0][1] = a[0];
  for(ll i = 1; i < n; i++) {
    dp[i][0] = dp[i-1][1];
	dp[i][1] = min(dp[i-1][1] + a[i], dp[i-1][0] + a[i]);
  }
  ans = min(ans, min(dp[n-1][1], dp[n-1][0]));
  cout << ans << endl;
}