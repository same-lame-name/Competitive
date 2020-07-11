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

int N, cnt = 0, val[(int)1e5 + 5];
LL t = 0;

int main(){
  FAST_IO
  cin >> N;
  for(int rep = 0; rep < N; ++rep) cin >> val[rep];
  sort(val, val + N);

  for(int idx = 0; idx < N; ++idx){
    if((LL)val[idx] >= t){
      cnt++;
      t += val[idx];
    }
  }

  cout << cnt << '\n';
  return 0;
}

