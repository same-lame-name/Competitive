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

int testcases, N;
LL bst;

void solve(){
  bst = 0;
  bool positive = true;
  int maxP = 0, leastN = -INF;
  for(int rep = 0, x; rep < N; ++rep){
    cin >> x;
    if(x > 0 && positive){
      max_self(maxP, x);
    }else if(x < 0 && !positive){
      max_self(leastN, x);
    }else if(x > 0){
      bst += (LL)leastN;
      leastN = -INF;
      positive = true;
      maxP = x;
    }else if(x < 0){
      bst += (LL)maxP;
      maxP = 0;
      positive = false;
      leastN = x;
    }
  }

  if(positive) bst += (LL)maxP;
  else bst += (LL)leastN;

  cout << bst << '\n';
  return;      
}
int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> N;
    solve();
  }
  return 0;
}
