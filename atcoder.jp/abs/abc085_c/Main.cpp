#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, y;
  cin >> n >> y;
  for(int i = n; i >= 0; i--)
    if(10000 * i == y && i == n){
      cout << i << " " << 0 << " " << 0 << endl;
      return 0;
    }
    else
      for(int j = n - i; j >= 0; j--)
        if(10000 * i + 5000 * j == y && i + j == n){
          cout << i << " " << j << " " << 0 << endl;
          return 0;
        }
        else
            if(10000 * i + 5000 * j + 1000 * (n - i - j) == y){
              cout << i << " " << j << " " << n - i - j << endl;
              return 0;
            }
  cout << -1 << " " << -1 << " " << -1 << endl;
}