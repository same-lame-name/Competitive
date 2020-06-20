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

int N, M, opt[(int)1e4 + 5], cost[10] = {INF, 2, 5, 5, 4, 5, 6, 3, 7, 6};
vector<int> avail;

void solve(){
  opt[0] = 0; 
  for(int use = 1; use <= N; ++use) opt[use] = -INF;

  for(int use = 1; use <= N; ++use){
    for(int dig : avail){
      if(cost[dig] > use) continue;
      max_self(opt[use], 1 + opt[use - cost[dig]]);
    }
  }

  assert(opt[N] > 0);

  int use = N;
  while(use > 0){
    for(int dig : avail){
      if(cost[dig] > use) continue;
      if(opt[use] == opt[use - cost[dig]] + 1){
        cout << dig;
        use -= cost[dig];
        break;
      }
    }
  }
  
  return;
}
    
    



int main(){
  FAST_IO
  cin >> N >> M;
  avail.resize(M);
  for(int &ele : avail) cin >> ele;

  sort(ALLR(avail));

  solve();
  return 0;
}
