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

int N, M, total = 0;
bool del[105], okay[105];
string grid[105];

int main(){
  FAST_IO
  cin >> N >> M;
  memset(del, false, sizeof del);
  memset(okay, false, sizeof okay);
  for(int r = 0; r < N; ++r) cin >> grid[r];

  for(int c = 0; c < M; ++c){
    vector<int> util;
    for(int r = 1; r < N; ++r){
      if(okay[r]) continue;

      if(grid[r][c] < grid[r - 1][c]){
        del[c] = true;
      }else if(grid[r][c] > grid[r - 1][c]){
        util.PB(r);
      }
    }

    if(!del[c]){
      for(int ele : util) okay[ele] = true;
    }
  }

  for(int c = 0; c < M; ++c) total += del[c];
  cout << total << '\n';
  return 0;
}
