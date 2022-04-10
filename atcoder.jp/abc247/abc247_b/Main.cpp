#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 80000000000;
const ll prime1 = 1000000007;
const ll prime2 = 998244353;
const double pi = 3.141592653;

ll n;
string s[109], t[109];
bool check[109][2];

int main(){
  cin >> n;
  for(ll i = 0; i < n; i++)
    cin >> s[i] >> t[i];
  for(ll i = 0; i < n; i++)
    for(ll j = 0; j < n; j++)
      if(i != j){
        if(s[i] == s[j]){
          check[i][0] = true;
          check[j][0] = true;
        }
        if(s[i] == t[j]){
          check[i][0] = true;
          check[j][1] = true;
        }
      }
    for(ll i = 0; i < n; i++)
      for(ll j = 0; j < n; j++)
        if(i != j)
          if(t[i] == t[j]){
            check[i][1] = true;
        }
  for(ll i = 0; i < n; i++)
    if(check[i][0] && check[i][1]){
      cout << "No" << endl;
      return 0;
    }
  cout << "Yes" << endl;
}