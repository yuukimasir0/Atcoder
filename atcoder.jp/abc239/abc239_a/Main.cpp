#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 80000000000;
const ll prime1 = 1000000007;
const ll prime2 = 998244353;
const double pi = 3.141592653;

ll x;

int main(){
  cin >> x;
  cout<< setprecision(16) << pow(x * (12800000 + x), 0.5) << endl;
}