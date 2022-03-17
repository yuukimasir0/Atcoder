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
  int j = 0, count = 0;
  while(j < n - count){
    if(a[j] > a[j+1]){
       j++;
    }else if(a[j] == a[j+1]){
      a[j+1] = 0;
      swap(a[j+1], a[n-count]);
      count++;
      j--;
    }else{
      swap(a[j],a[j+1]);
      if(j != 0)
        j--;
    }
  }
//  for(int i = 0; i < n; i++)
//    cout << a[i] << endl;
  cout << n - count << endl;
}