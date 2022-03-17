#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++)
    cin >> a[i];
  a[n] = 0;
  int sa = 0, sb = 0; //score alice, bob
  int j = 0;
  while(j < n){
    if(a[j] >= a[j+1]){
       j++;
    }else{
      swap(a[j],a[j+1]);
      if(j != 0)
        j--;
    }
  }
  for(int i = 0; i < n; i++){
    if(i % 2 == 0)
      sa += a[i];
    else
      sb += a[i];
  }
  cout << sa - sb << endl;
}