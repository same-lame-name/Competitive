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


int main(){
  FAST_IO  

  int H, W, white = 0, minPath = 0, round = 0; cin >> H >> W;
  vector<vector<char>> grid(H, vector<char>(W));
  queue<pair<int, int>> BFS;

  pair<int, int> directions[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  for(int r = 0; r < H; ++r){
    for(int c = 0; c < W; ++c){
      char color; cin >> color;
      if(color == '.') white++;
      grid[r][c] = color;
    }
  }

  BFS.push({0, 0});
  grid[0][0] = '#';

  auto valid = [&](int r, int c){
    if(r < 0 || r >= H || c < 0 || c >= W) return false;
    if(grid[r][c] == '#') return false;
    return true;
  };

  while(!BFS.empty()){
    int size = BFS.size();
    for(int rep = 0; rep < size; ++rep){
      auto cur = BFS.front();
      BFS.pop();
      int row = cur.F, col = cur.S;
      if(row == H - 1 && col == W - 1){
        minPath = round;
        break;
      }

      for(auto dir : directions){
        int nxtR = row + dir.F, nxtC = col + dir.S;
        if(!valid(nxtR, nxtC)) continue;
        grid[nxtR][nxtC] = '#';
        BFS.push({nxtR, nxtC});
      }
    }
    round++;
  }

  if(grid[H - 1][W - 1] == '.') cout << "-1\n";
  else cout << white - minPath - 1 << "\n";



  return 0;
}