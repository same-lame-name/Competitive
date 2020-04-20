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

  int grid[3][3];

  for(int r = 0; r < 3; ++r){
    for(int c = 0; c < 3; ++c){
      cin >> grid[r][c];
    }
  }

  auto checkRow = [&](){
    for(int r = 0; r < 2; ++r){
      int diff1 = grid[r][0] - grid[r + 1][0];
      int diff2 = grid[r][1] - grid[r + 1][1];
      int diff3 = grid[r][2] - grid[r + 1][2];
      if(diff1 != diff2 || diff2 != diff3) return false;
    }

    return true;
  };
  
  auto checkCol = [&](){
    for(int c = 0; c < 2; ++c){
      int diff1 = grid[0][c] - grid[0][c + 1];
      int diff2 = grid[1][c] - grid[1][c + 1];
      int diff3 = grid[2][c] - grid[2][c + 1];
      if(diff1 != diff2 || diff2 != diff3) return false;
    }

    return true;
  };

  if(checkRow() && checkCol()) cout << "Yes\n";
  else cout << "No\n";

  return 0;
}