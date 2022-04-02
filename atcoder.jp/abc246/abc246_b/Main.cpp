#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b;

int main(){
double theta;
  cin >> a >> b;
  theta = atan2(b, a);
  cout << setprecision(12) << cos(theta) << " " << sin(theta) << endl;
}