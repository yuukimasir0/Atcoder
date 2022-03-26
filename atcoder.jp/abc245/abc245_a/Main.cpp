#include <bits/stdc++.h>
using namespace std;

long long a, b, c, d;

int main(){
  long long Takahashi = 0, Aoki = 1;
  cin >> a >> b >> c >> d;
  Takahashi += a * 3600;
  Takahashi += b * 60;
  Aoki += c * 3600;
  Aoki += d * 60;
  if(Takahashi < Aoki)
    cout << "Takahashi" << endl;
  else
    cout << "Aoki" << endl;
}