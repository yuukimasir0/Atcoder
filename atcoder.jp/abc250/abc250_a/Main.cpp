#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll h, w, r, c;

int main(){
  ll count = 0;
  cin >> h >> w >> r >> c;
  for(ll i = 1; i <= h; i++)
    for(ll j = 1; j <= w; j++)
      if(abs(r - i) + abs(c - j) == 1)
        count++;
  cout << count << endl;
}