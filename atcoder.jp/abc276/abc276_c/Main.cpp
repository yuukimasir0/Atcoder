#include<bits/extc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> P(N);
  for(int i = 0; i < N; i++) cin >> P[i];
  prev_permutation(P.begin(), P.end());
  for(int i = 0; i < N; i++) cout << P[i] << " ";
  cout << endl;
}