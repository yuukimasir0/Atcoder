#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, q;
ll x[200009];
ll a[200009];
ll ainv[200009];

int main(){
  cin >> n >> q;
  for(ll i = 1; i <= q; i++)
    cin >> x[i];
  for(ll i = 1; i <= n; i++){
    a[i] = i;
    ainv[i] = i;
  }
  
  
  
  for(ll i = 1; i <= q; i++){
    if(ainv[x[i]] != n){
      swap(a[ainv[x[i]]], a[ainv[x[i]]+1]);
      swap(ainv[a[ainv[x[i]]]], ainv[a[ainv[x[i]]+1]]);
    }else{
      swap(a[ainv[x[i]]], a[ainv[x[i]]-1]);
      swap(ainv[a[ainv[x[i]]]], ainv[a[ainv[x[i]]-1]]);
    }
  }
  
  
  for(ll i = 1; i <= n; i++)
    cout << a[i] << " " << endl;
}