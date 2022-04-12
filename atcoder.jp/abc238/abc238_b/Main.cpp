#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll a[400];

int main(){
  ll max = 0;
  cin >> n;
  a[0] = 0;
  for(ll i = 1; i <= n; i++){
    cin >> a[i];
    a[i] += a[i-1];
  }
  for(ll i = 0; i <= n; i++)
    a[i] %= 360;
  sort(a, a+n+1);
  for(ll i = 1; i <= n; i++)
    if(a[i] - a[i-1] > max)
      max = a[i] - a[i-1];
  if(360 - a[n] > max)
    max =360 - a[n];
  cout << max << endl;
}