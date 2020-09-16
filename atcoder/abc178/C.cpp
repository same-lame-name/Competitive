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

LL modExp(LL base, LL N){
  LL value = 1;
  while(N){
    if(N & 1) value = (base * value) % INF;
    base = (base * base) % INF;
    N >>= 1;
  }

  return value;
}

int main(){
  FAST_IO
  int N; cin >> N;
  if(N < 2) cout << 0 << '\n';
  else{
    LL result = modExp(10, N) + modExp(8, N);
    result %= INF;
    result -= modExp(9, N);
    result %= INF;
    result -= modExp(9, N);
    result %= INF;
    if(result < 0) result += INF;
    cout << result;
  }
  return 0;
}

