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
LL ben[20], ext[20][20], memo[(1 << 19)][20];

LL util(int mask, int last){
  int cnt = 0;
  for(int idx = 1; idx <= N; ++idx){
    if(mask & (1 << idx)) cnt++;
  }

  if(cnt == M) return 0LL;

  LL &opt = memo[mask][last];
  if(opt != -1) return opt;
  opt = 0;

  for(int choice = 1; choice <= N; ++choice){
    if(mask & (1 << choice)) continue;
  
    max_self(opt, util(mask | (1 << choice), choice) + ben[choice] + ext[choice][last]);
  }

  return opt;
}

int main(){
  FAST_IO
  cin >> N >> M >> k;
  memset(memo, -1, sizeof memo);
  for(int idx = 1; idx <= N; ++idx) cin >> ben[idx];
  for(int rep = 0, x, y; rep < k; ++rep){
    cin >> x >> y >> ext[y][x];
  }

  cout << util(0, 0);
  return 0;
}

