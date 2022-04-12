#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

int main(){
  cin >> n;
  switch(n){
    case 1 :
      cout << "Yes" << endl;
      return 0;
    case 2 :
    case 3 :
    case 4 :
      cout << "No" << endl;
      return 0;
    default :
      cout << "Yes" << endl;
      return 0;
  }
}