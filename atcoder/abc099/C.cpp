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

int N, opt[(int)1e6 + 5];

int main(){
  FAST_IO

  cin >> N;
  opt[0] = 0;

  for(int t = 1; t <= N; ++t) opt[t] = t;
  
  for(int coin : {6, 9}){
    for(int exp = 1; pow(coin, exp) <= N; ++exp){
      int deno = pow(coin, exp);
      for(int t = deno; t <= N; ++t){
        min_self(opt[t], opt[t - deno] + 1);
      }
    }
  }

  cout << opt[N] << '\n';
  return 0;
}