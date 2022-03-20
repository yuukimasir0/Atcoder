#include <bits/stdc++.h>
using namespace std;

int a, b, c, x;
double pro;

int main(){
  cin >> a >> b >> c >> x;
  if(x <= a){
    cout << 1 << endl;
  }else if(x <= b){
    pro = double(double(c) / (double(b) - double(a)));
    cout << pro << endl;
  }else
    cout << 0 << endl;
}