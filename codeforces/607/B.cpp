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

int N, num[505], opt[505][505];

int main(){
  FAST_IO
  cin >> N;
  for(int rep = 1; rep <= N; ++rep) cin >> num[rep];

  for(int f = N; f >= 1; --f){
    for(int t = f; t <= N; ++t){
      int &util = opt[f][t] = INF;
      for(int d = f, merge; d <= t; ++d){
        if(num[f] != num[d]) continue;
        merge = (f + 1 > d - 1);
        min_self(util, merge + opt[f + 1][d - 1] + opt[d + 1][t]);
      }
    }
  }
      
  cout << opt[1][N] << '\n';
  return 0;
}
