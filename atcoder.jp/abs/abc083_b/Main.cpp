#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, a, b;
  int count = 0;
  cin >> n >> a >> b;
  int n1[n], n2[n], n3[n], n4[n], n5[n];
  for(int i = 1; i <= n; i++){
    n1[i] = i % 10;
    n2[i] = (i / 10) % 10;
    n3[i] = (i / 100) % 10;
    n4[i] = (i / 1000) % 10;
    n5[i] = i / 10000;
    if(n1[i] + n2[i] + n3[i] + n4[i] + n5[i] >= a && n1[i] + n2[i] + n3[i] + n4[i] + n5[i] <= b)
      count += i;
  }
  cout << count << endl;
}