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

int testcases, N, a, b, c, memo[105][105][105];
char moves[105][105][105];
string in;

int res(char x, char y){
  if(x == 'R') return y == 'S';
  if(x == 'P') return y == 'R';
  if(x == 'S') return y == 'P';

  assert(false);
  return 0;
}

int dputil(int done, int r, int p){
  if(done == N) return 0;
  int &cnt = memo[done][r][p];
  if(cnt != -1) return cnt;

  int s = N - done - r - p;
  assert(s >= 0);
  char move = in[done];
  if(s > 0 && max_self(cnt, res('S', move) + dputil(done + 1, r, p))){
    moves[done][r][p] = 'S';
  }
  if(r > 0 && max_self(cnt, res('R', move) + dputil(done + 1, r - 1, p))){
    moves[done][r][p] = 'R';
  }
  if(p > 0 && max_self(cnt, res('P', move) + dputil(done + 1, r, p - 1))){
    moves[done][r][p] = 'P';
  }

  return cnt;
}

void recover(){
  int done = 0, r = a, p = b;
  char util;
  while(done < N){
    util = moves[done][r][p]; 
    cout << util;
    if(util == 'R') r--;
    else if(util == 'P') p--;

    done++;
  }

  cout << '\n';
  return;
}

void solve(){
  memset(memo, -1, sizeof memo);

  if(dputil(0, a, b) * 2 < N) cout << "No\n";
  else{
    cout << "Yes\n";
    recover();
  }
  return;
}


  

int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> N >> a >> b >> c >> in;
    solve();
  }
  return 0;
}

