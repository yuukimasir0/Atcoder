#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> s;
  ll n = s.size();
  ll back = 0;
  ll front = 0;
  
  for(ll i = n-1; i >= 0; i--) {
    if(s[i] != 'a')
      break;
    back++;
  }
  
  for(ll i = 0; i < n; i++) {
    if(s[i] != 'a')
      break;
    front++;
  }
  
  if(front == n) {
    cout << "Yes\n";
    return 0;
  }
  
  if(front > back) {
    cout << "No\n";
    return 0;
  }
  
  for(ll i = front; i < n-back && n-back-1-i >= 0; i++)
    if(s[i] != s[ n + front - back - 1 - i]) {
      cout << "No\n";
      return 0;
    }
    cout << "Yes\n";
}