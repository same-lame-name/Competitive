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

LL N, minMax;

int main(){
  FAST_IO
  cin >> N;

  minMax = 15;
  string one, two;

  for(LL mul = 1, other; mul * mul <= N; ++mul){
    if(N % mul) continue;
    one = to_string(mul);
    two = to_string(N / mul);

    other = max(SZ(one), SZ(two));
    min_self(minMax, other);
  }
    
  cout << minMax << '\n';
  return 0;
}
