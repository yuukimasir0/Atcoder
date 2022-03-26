#include <bits/stdc++.h>
using namespace std;

int n;
int a[2009];
bool check[2009];

int main(){
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a+n);
  for(int i = 0; i < n; i++)
    check[a[i]] = true;
  for(int i =0; i <= n; i++)
    if(!check[i]){
      cout << i << endl;
      return 0;
    }
    
}