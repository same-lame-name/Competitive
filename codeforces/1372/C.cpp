#include "bits/stdc++.h"
#define PRECISION(x) cout << fixed << setprecision(x)
#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define ALLR(X) (X).rbegin(), (X).rend()
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define F first
#define S second

using namespace std;
 
template<class T> bool max_self(T & a, const T & b){ 
  return b > a ? a = b, true : false; 
}
template<class T> bool min_self(T & a, const T & b){ 
  return b < a ? a = b, true : false;    
}
typedef long long LL;
const int INF = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = (1e-9);

int testcases, N, num[(int)2e5 + 5];

void solve(){
  bool derangement = true;
  int left = 0, right = N - 1;
  while(left < N && num[left] == left + 1) left++;
  if(left == N){
    // Already sorted case.
    cout << "0\n";
    return;
  }

  while(num[right] == right + 1) right--;

  // There has to be atleast two elements in range [left, right].
  assert(left < right);

  for(int idx = left; idx <= right; ++idx) if(num[idx] == idx + 1) derangement = false;
  
  // variable 'derangement' tells us if the range from [left, right] is a derangement.
  if(derangement) cout << "1\n";
  else cout << "2\n";
  
  return;
}

int main(){
  FAST_IO

  cin >> testcases;
  while(testcases--){
    cin >> N;
    for(int idx = 0; idx < N; ++idx) cin >> num[idx];
    solve();
  }

  return 0;
}

