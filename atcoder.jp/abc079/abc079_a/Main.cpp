#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int a, b, c, d;
  a = N % 10;
  b = (N % 100 - a)/10;
  c = (N % 1000 - a - b * 10)/100;
  d = (N - a - b*10 - c*100)/1000;
  if(a == b && b == c){
    cout << "Yes" << endl;
  }else if(b == c && c == d){
     cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}