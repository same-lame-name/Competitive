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
 
template<class T> void max_self(T & a, const T & b) { if(a < b) a = b; }
template<class T> void min_self(T & a, const T & b) { if(a > b) a = b; }
typedef long long LL;
const int INF = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = (1e-9);

int N, m, n, valid, opt[50][500][500], a[50], b[50], c[50];

int main(){
  FAST_IO
  cin >> N >> m >> n;
  for(int rep = 1; rep <= N; ++rep) cin >> a[rep] >> b[rep] >> c[rep];

  for(int idx = 0; idx <= N; ++idx){
    for(int ca = 0; ca <= 400; ++ca){
      for(int cb = 0; cb <= 400; ++cb){
        opt[idx][ca][cb] = INF;
      }
    }
  }
  opt[0][0][0] = 0;

  for(int idx = 1; idx <= N; ++idx){
    for(int ca = 0; ca <= 400; ++ca){
      for(int cb = 0; cb <= 400; ++cb){
        int &util = opt[idx][ca][cb];
        util = opt[idx - 1][ca][cb];
        if(ca < a[idx] || cb < b[idx]) continue;
        min_self(util, opt[idx - 1][ca -a[idx]][cb - b[idx]] + c[idx]);
      }
    }
  }

  valid = INF;
  for(int ca = 1; ca <= 400; ++ca){
    for(int cb = 1; cb <= 400; ++cb){
      if(ca * n != cb * m) continue;
      min_self(valid, opt[N][ca][cb]);
    }
  }
      
  if(valid < INF) cout << valid << '\n';
  else cout << "-1\n";
  return 0;
}
