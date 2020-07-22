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

int testcases;
LL m, r, L, R;

void solve(){

  // Now we are trying to satisfy the integer equation m = n * t + r
  for(LL t = L; t <= R; ++t){
    r = m % t;
    if(L - R <= r - t){
      // Here I try : m = (n + 1) * t + (r - t).
      cout << t << " " << L << " " << L + t - r << '\n';
      return;
    }else if(r <= R - L){
      // Here I try : m = n * t + r.
      cout << t << " " << L + r << " " << L << '\n';
      return;
    }

    assert(t < m);
  }

  assert(false);
  return;
}

int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> L >> R >> m;
    solve();
  }
  return 0;
}

