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

LL testcases, N, opt[(int)2e6 + 5];

int main(){
  FAST_IO
  
  for(int n = 3; n <= (int)2e6; ++n){
    opt[n] = opt[n - 1] + 2 * opt[n - 2];
    if(n % 3 == 0) opt[n] += 4;
    opt[n] %= INF;
  }

  cin >> testcases;
  while(testcases--){
    cin >> N;
    cout << opt[N] << '\n';
  }
  return 0;
}
