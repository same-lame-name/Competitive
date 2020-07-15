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
  int left = 1, right = N;
  while(left <= N && num[left] == left) left++;

  if(left > N){
    // Already sorted case.
    cout << "0\n";
    return;
  }

  while(num[right] == right) right--;

  for(int idx = left; idx <= right; ++idx){
    if(num[idx] == idx){
      cout << "2\n";
      return;
    }
  }
  
  cout << "1\n"; 
  return;
}

int main(){
  FAST_IO

  cin >> testcases;
  while(testcases--){
    cin >> N;
    for(int idx = 1; idx <= N; ++idx) cin >> num[idx];
    solve();
  }

  return 0;
}

