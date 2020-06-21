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

int main(){
  FAST_IO
  int N, cnt[10], diff = 0, extra = 0;
  memset(cnt, 0, sizeof cnt);
  cin >> N;
  for(int rep = 0, x; rep < N; ++rep){
    cin >> x;
    x /= 400;
    if(x > 7) extra++;
    else cnt[x]++;
  }

  for(int rep = 0; rep < 8; ++rep) if(cnt[rep] > 0) diff++;

  cout << (diff ? diff : 1) << " " << diff + extra << '\n';
  return 0;
}
