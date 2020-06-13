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

int N, M, k, req, s;
string grid[505];

void dfs(int r, int c){
  if(req == 0) return;
  if(r < 0 || r >= N || c < 0 || c >= M) return;
  if(grid[r][c] != '.') return;
  grid[r][c] = '-';
  req--;

  if(req) dfs(r + 1, c);
  if(req) dfs(r, c + 1);
  if(req) dfs(r, c - 1);
  if(req) dfs(r - 1, c);

  return;
}


void solve(){
  for(int r = 0; r < N; ++r){
    for(int c = 0; c < M; ++c){
      if(grid[r][c] != '.') continue;
      dfs(r, c);
      goto stop;
    }
  }

  stop:

  for(int r = 0; r < N; ++r, cout << '\n'){
    for(int c = 0; c < M; ++c){
      if(grid[r][c] == '#') cout << '#';
      else if(grid[r][c] == '.') cout << 'X';
      else cout << '.';
    }
  }

  return;
}

int main(){
  FAST_IO
  cin >> N >> M >> k;
  s = 0;
  for(int rep = 0; rep < N; ++rep){
    cin >> grid[rep];
    for(char c : grid[rep]) s += (c == '.');
  }
  req = s - k;

  solve();
  return 0;
}
