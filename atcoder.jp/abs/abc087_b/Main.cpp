#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, x;
  long long count = 0;
  cin >> a >> b >> c >> x;
  for(int i = 0; i <= a; i++)
    if(x - 500 * i == 0)
      count++;
    else
      for(int j = 0; j <= b; j++)
        if(x - 500 * i - 100 * j == 0)
          count++;
        else
          for(int k = 0; k <= c; k++)
            if(x - 500 * i - 100 * j - 50 * k == 0)
              count++;
  cout << count << endl;
}