#include<bits/extc++.h>

signed main(void){
  long long N;
  std::cin >> N;
  int ans = 0;
  while(1LL << ans <= N) ans++;
  ans--;
  std::cout << ans << '\n';
}