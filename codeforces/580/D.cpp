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

int N, M, k; 
LL ben[20], ext[20][20], opt[(1 << 18)][20], bst = 0;

int get(int mask){
  int cnt = 0;
  for(int idx = 0; idx < N; ++idx){
    if(mask & (1 << idx)) cnt++;
  }

  return cnt;
}

int main(){
  FAST_IO
  cin >> N >> M >> k;
  for(int idx = 0; idx < N; ++idx) cin >> ben[idx];
  for(int rep = 0, x, y; rep < k; ++rep){
    cin >> x >> y >> ext[y - 1][x - 1];
  }

  for(int idx = 0; idx < N; ++idx) opt[1 << idx][idx] = ben[idx];
  for(int mask = 0; mask < (1 << N); ++mask){
    for(int last = 0; last < N; ++last){
      if(mask & (1 << last)){
        for(int nxt = 0; nxt < N; ++nxt){
          if(mask & (1 << nxt)) continue;
          max_self(opt[mask | (1 << nxt)][nxt], opt[mask][last] + ben[nxt] + ext[nxt][last]);
        }
      }
    }
  }

  for(int mask = 0; mask < (1 << N); ++mask){
    if(get(mask) != M) continue;
    for(int last = 0; last < N; ++last){
      if(mask & (1 << last)) max_self(bst, opt[mask][last]);
    }
  }
  
  cout << bst << '\n';
  return 0;
}

