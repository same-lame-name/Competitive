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

int N, k, total[(int)1e5 + 5], minIdx = 0;

int main(){
  FAST_IO
  cin >> N >> k;
  for(int rep = 0, x; rep < N; ++rep){
    cin >> x;
    total[rep % k] += x;
  }

  for(int idx = 0; idx < k; ++idx){
    if(total[idx] < total[minIdx]) minIdx = idx;
  }

  cout << minIdx + 1 << '\n';
  return 0;
}

