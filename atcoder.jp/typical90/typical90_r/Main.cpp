#include <bits/stdc++.h>
using namespace std;

long long t, l, x, y, q;
long long e[1010];

double r(long long l, long long x, long long y, long long t, long long e){
  const double pi = 3.14159265358979323846;
  return sqrt(x * x + (y + l*sin(e * 2 * pi / t) / 2) * (y + l*sin(e * 2 * pi / t) / 2));
}

double z(long long l, long long t, long long e){
  const double pi = 3.14159265358979323846;
  return l*(1 - cos(e * 2 * pi / t )) / 2; 
}



int main(){
  const double pi = 3.14159265358979323846;
  cin >> t >> l >> x >> y >> q;
  for(int i = 0; i < q; i++)
    cin >> e[i];
  for(int i = 0; i < q; i++){
    if(r(l, x, y, t, e[i]) != 0)
      cout << fixed << setprecision(12) << 180 * atan2(z(l, t, e[i]), r(l, x, y, t, e[i])) / pi  << endl;
    else
      cout << fixed << setprecision(12) << 0 << endl;
  }
}