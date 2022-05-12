#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll const check = 1000000;

int main(){
  cin >> n;
  ll i = 0;
  ll j = check;
  ll ans = 8e18;
  if(n == 0) {
    cout << 0 << endl;
    return 0;
  }
  for(ll i = 1; i <= check; i++) {
    if(n == (i * i * i)) {
      cout << n << endl;
      return 0;
    }else if(n < (i * i * i)) {
      break;
    }
  }
  while(i <= j) {
    ll temp = i * i * i + i * i * j + i * j * j + j * j * j;
    if(temp >= n) {
      ans = min(ans, temp);
      j--;
    } else {
      i++;
    }
  }
  cout << ans << endl;
}