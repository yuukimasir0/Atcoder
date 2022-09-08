#include<bits/stdc++.h>

using namespace std;
int n,m;
//配列aは、どの電球がどのスイッチにつないでいるかを管理する用（電球iがスイッチjに
//つながれているときにa[i-1][j-1]=1とした。i-1とかj-1にするのは、配列の添え字を
//0からスタートにしているため
int a[12][12]={0};
int p[12]={0};
int cnt=0;

int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    for(int j=0;j<k;j++){
      int s;
      cin>>s;
      a[i][s-1]=1;
    }
  }
  for(int i=0;i<m;i++){
    cin>>p[i];
  }
  
  //bit全探索
  for(int bit=0;bit<(1<<n);bit++){
    bool t=true;
    for(int i=0;i<m;i++){
      int on =0;
      for(int j=0;j<n;j++){
        if(a[i][j]==1&&(bit & (1<<j))) on++;
      }
      if(on%2!=p[i]) {
        //1つでも一致しないものがあればアウト
        t =false;
        break;
      }
    }
    //すべてp[i]と一致すればt=trueでcntを1増やす。
    if(t){
      cnt++;
    }
  }
  cout<<cnt<<endl;
  return 0;
}