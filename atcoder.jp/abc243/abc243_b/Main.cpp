#include <bits/stdc++.h>
using namespace std;
 int main(){
 	int N, ans1 = 0, ans2 = 0;
 	cin >> N;
 	int A[N-1];
 	int B[N-1];
   for(int i = 0; i < N; i++){
     cin >> A[i];
   }
   for(int i = 0; i < N; i++){
     cin >> B[i];
   }
   for(int i = 0; i < N; i++){
     if(A[i] == B[i])
       ans1++;
   }
   for(int i = 0; i < N; i++){
     for(int j = 0; j < N; j++){
     	if(A[i] == B[j] && i != j)
       		ans2++;
     }
   }
   cout << ans1 << endl;
   cout << ans2 << endl;
 }