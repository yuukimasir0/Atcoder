#include <bits/stdc++.h>
using namespace std;

long long n;
long long t[100010], x[100010], y[100010];

int main(){
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> t[i] >> x[i] >> y[i];
  t[0] = 0; x[0] = 0; y[0] = 0;
  
  for(int i = 1; i <= n; i++){
    long long dr = abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
    long long dt = t[i] - t[i-1];
    if(dr > dt){
      cout << "No" << endl;
      return 0;
    }
    if(abs(dr - dt) % 2 == 1){
      cout << "No" << endl;
      return 0;
    }
  }
    cout << "Yes" << endl;
}