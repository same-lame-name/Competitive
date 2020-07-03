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

int N, k, testcases;
bool grid[305][305];

void solve(){
  memset(grid, false, sizeof grid);
  int all = k / N, extra = k - all * N, col = 0;

  for(int r = 0, req; r < N; ++r){
    req = all;
    if(r < extra) req++;

    for(int rep = 0; rep < req; ++rep){
      grid[r][col] = true;
      col = (col + 1) % N;
    }
  }

  if(k % N) cout << "2\n";
  else cout << "0\n";

  for(int r = 0; r < N; ++r, cout << '\n'){
    for(int c = 0; c < N; ++c) cout << (grid[r][c] ? 1 : 0);
  }

  return;
}

int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> N >> k;
    solve();
  }
  return 0;
}

