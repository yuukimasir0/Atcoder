#include <bits/stdc++.h>
using namespace std;

int n;
bool a[2100];
int temp;

int main(){
  cin >> n;
  cout << 1 << endl;
  int i = 1;
  while(i <= 2*n+1){
    cin >> temp;
    if(temp == 0)
      return 0;
    a[temp] = true;
    for(int j = 2; j <= 2*n + 1; j++)
      if(!a[j]){
        cout << j << endl;
        a[j] = true;
        i++;
        break;
      }
  }
}