#include <bits/stdc++.h>
using namespace std;
 int main(){
 int V, A, B, C;
   cin >> V >> A >> B >> C;
   do{
   		V -= A;
     if(V < 0){
     cout << "F" << endl;
     	}
     if(V >= 0){
     	V -= B;
     if(V < 0){
     cout << "M" << endl;
     	}
     }
     if(V >= 0){
     	V -= C;
     if(V < 0){
       cout << "T" <<endl;
     	}
     }
 	}while(V >= 0);
 }