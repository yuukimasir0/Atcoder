#include <bits/stdc++.h>
using namespace std;

signed main(){
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++)
    cin >> a[i];
  int ans = 0;
  while(true){
    bool flag = false;
    for(int i = 0; i < n; i++) {
      if(a[i] % 2 == 1)
        flag = true;
      a[i] /= 2;
    }
    if(flag)
      break;
    ans++;
  }
  cout << ans << endl;
}