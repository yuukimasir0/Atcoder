#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
constexpr ll check = (1LL << 31);

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> n;
  if(n >= -check && n < check ) {
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";
}