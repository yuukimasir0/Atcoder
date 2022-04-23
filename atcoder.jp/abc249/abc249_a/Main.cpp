#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c, d, e, f, x;

int main(){
  ll ans1 = 0, ans2 = 0;
  cin >> a >> b >> c >> d >> e >> f >> x;
  ll x1 = x, x2 = x;
  while(x1 > 0){
    if(x1 > a){
      ans1 += a * b;
      x1 -= a;
      x1 -= c;
    }else{
      ans1 += x1 * b;
      x1 = 0;
    }
  }
  while(x2 > 0){
    if(x2 > d){
      ans2 += d * e;
      x2 -= d;
      x2 -= f;
    }else{
      ans2 += x2 * e;
      x2 = 0;
    }
  }
  if(ans1 > ans2)
    cout << "Takahashi" << endl;
  else if(ans2 > ans1)
    cout << "Aoki" << endl;
  else
    cout << "Draw" << endl;
}