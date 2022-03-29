#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll a[200005];
ll b[200005];

int main(){
  cin >> n;
  for(ll i = 1; i <= n; i++)
    cin >> a[i];
  for(int i = 1; i <= n; i++)
    b[a[i]] = i;
  for(int i = 1; i <= n; i++)
    cout << b[i] << " ";
  cout << endl;
}