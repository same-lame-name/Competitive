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

int N, h, l, r, opt[2005][2005], sl[2005];

int util(int t, int idx){
  if(idx == N) return 0;

  if(opt[t][idx] != -1) return opt[t][idx];
  int &cnt = opt[t][idx];

  int nxt = (t + sl[idx]) % h;
  int one = util(nxt, idx + 1) + (l <= nxt && nxt <= r);

  nxt = (t + sl[idx] - 1) % h;
  int two = util(nxt, idx + 1) + (l <= nxt && nxt <= r);

  return cnt = max(one, two);
}

int main(){
  FAST_IO
  cin >> N >> h >> l >> r;
  for(int idx = 0; idx < N; ++idx) cin >> sl[idx];
  memset(opt, -1, sizeof opt);

  cout << util(0, 0);
  return 0;
}

