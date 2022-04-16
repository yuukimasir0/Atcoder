 #include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, k;
int main(){
cin >> a >> b >> k;
if(a > b){
cout << 0 << endl;
return 0;
}
for(ll i = 0; i < 100000; i++)
if(a * pow(k, i) >= b){
cout << i << endl;
return 0;
}
}
