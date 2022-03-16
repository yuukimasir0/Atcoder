#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, count;
    cin >> a;
    if(a >= 100)
    count++;
    if(a % 100 >= 10)
    count++;
    if((a % 100) % 10 >= 1)
    count++;
    cout << count << endl;
}