#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[15];
ll temp;

int main(){
  const ll n = 10;
  for(ll i = 0; i < n; i++)
    cin >> a[i];
  temp = a[0];
  temp = a[temp];
  cout << a[temp] << endl;
}