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

int testcases, N, k;
int grid[305][305];

int sq(int a){
  return a * a;
}

void solve(){
  int all = k / N, extra = k - all * N;
  int minc = INF, maxc = 0, minr = all, maxr = all + (extra > 0);
  deque<int> order;
  for(int c = 0; c < N; ++c) order.push_back(c);

  for(int r = 0; r < N; ++r){
    for(int c = 0; c < N; ++c) grid[r][c] = 0;
  }

  assert(SZ(order) == N);

  for(int r = 0, req; r < N; ++r){
    req = all;
    if(r < extra) req++;

    for(int rep = 0, c; rep < req; ++rep){
      c = order.front();
      grid[r][c] = 1;
      order.pop_front();
      order.push_back(c);
    }
  }

  for(int c = 0; c < N; ++c){
    int cnt = 0;
    for(int r = 0; r < N; ++r) cnt += grid[r][c];
    min_self(minc, cnt);
    max_self(maxc, cnt);
  }

  cout << sq(maxr - minr) + sq(maxc - minc) << '\n';
  for(int r = 0; r < N; ++r){
    for(int c = 0; c < N; ++c) cout << grid[r][c];
    cout << '\n';
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

