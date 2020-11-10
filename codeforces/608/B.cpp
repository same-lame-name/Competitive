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

string a, b;
int pref[(int)2e5 + 5], N, M;
LL cnt = 0;

int get(int f, int t){
  assert(f <= t);
  return pref[t] - (f ? pref[f - 1] : 0);
}

int main(){
  FAST_IO
  cin >> a >> b;
  N = SZ(a), M = SZ(b);
  for(int idx = 0; idx < N; ++idx){
    pref[idx] = a[idx] - '0';
    if(idx) pref[idx] += pref[idx - 1];
  }

  for(int idx = 0, f, t, ones, zeros; idx < M; ++idx){
    t = min(N - 1, idx);
    f = max(0, N - M + idx);
    ones = get(f, t);
    zeros = t - f + 1 - ones;
    if(b[idx] == '0') cnt += ones;
    else cnt += zeros;
  }

  cout << cnt << '\n';
}

