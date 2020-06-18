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

int N, q, sum = 0;

int main(){
  FAST_IO
  cin >> N;

  for(int r = 0; r < N; ++r){
    for(int c = 0, x; c < N; ++c){
      cin >> x;
      if(r == c && x) sum = 1 - sum;
    }
  }

  cin >> q;
  for(int rep = 0, x, y; rep < q; ++rep){
    cin >> x;
    if(x == 3){
      cout << sum;
      continue;
    }

    cin >> y;
    sum = 1 - sum;
  }

  return 0;
}
