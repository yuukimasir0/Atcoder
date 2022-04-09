#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b;

int main(){
  cin >> a >> b;
  if(a == 1 && b == 10){
    cout << "Yes" << endl;
    return 0;
  }
  if(b == 1 && a == 10){
    cout << "Yes" << endl;
    return 0;
  }
  if(abs(a - b) == 1){
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  
  
}
