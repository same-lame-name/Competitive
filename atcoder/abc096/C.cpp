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

int H, W;
string grid[55];

inline bool check(int h, int w){
  int cnt = 0;
  if(h + 1 == H || grid[h + 1][w] == '.') cnt++;
  if(h - 1 < 0 || grid[h - 1][w] == '.') cnt++;
  if(w + 1 == W || grid[h][w + 1] == '.') cnt++;
  if(w - 1 < 0 || grid[h][w - 1] == '.') cnt++;

  if(cnt == 4) return false;
  return true;
}


int main(){
  FAST_IO

  cin >> H >> W;

  for(int rep = 0; rep < H; ++rep) cin >> grid[rep];

  for(int h = 0; h < H; ++h){
    for(int w = 0; w < W; ++w){
      if(grid[h][w] == '.') continue;

      if(!check(h, w)){
        cout << "No\n";
        return 0;
      }

    }
  }

  cout << "Yes\n";
  return 0;
}
