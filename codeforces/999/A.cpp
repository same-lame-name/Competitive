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

int N, k, l, r, diff[105];

int main(){
  FAST_IO
  cin >> N >> k;
  for(int rep = 0; rep < N; ++rep) cin >> diff[rep];
  l = 0, r = N - 1; 
  while(l < N && diff[l] <= k) l++;
  while(r >= 0 && diff[r] <= k) r--;

  if(l <= r){
    cout << l + (N - r - 1) << '\n';
  }else cout << N << '\n';
  
  return 0;
}