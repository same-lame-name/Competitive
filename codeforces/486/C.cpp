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

int N, p, x, y, cost = 0, M;
string in, a, b, A, B;

int main(){
  FAST_IO
  cin >> N >> p >> in;

  a = in.substr(0, N / 2);
  b = in.substr((N + 1) / 2);
  
  M = SZ(a);
  assert(M == SZ(b));

  if(p > M) p = N - p + 1;
  x = p - 1, y = max(M - p, 0);
  assert(x >= 0 && y >= 0);

  reverse(ALL(b));

  for(int idx = 0; idx < p - 1; ++idx){
    if(a[idx] != b[idx]) break;
    x--;
  }

  for(int idx = M - 1; idx >= p; --idx){
    if(a[idx] != b[idx]) break;
    y--;
  }

  for(int idx = 0; idx < M; ++idx){
    cost += min(abs(a[idx] - b[idx]), 26 - abs(a[idx] - b[idx]));
  }

  cout << cost + min(2 * x + y, 2 * y + x);
  return 0;
}
