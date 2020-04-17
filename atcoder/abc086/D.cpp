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
  
  int N, k, best = 0; cin >> N >> k;
  vector<vector<int>> cell(2 * k, vector<int>(2 * k, 0));

  auto get = [&](int bx, int by, int tx, int ty){
    int cur = cell[tx][ty];
    if(bx > 0) cur -= cell[bx - 1][ty];
    if(by > 0) cur -= cell[tx][by - 1];
    if(bx > 0 && by > 0) cur += cell[bx - 1][by - 1];

    return cur;
  };

  for(int rep = 0; rep < N; ++rep){
    int x, y; cin >> x >> y;
    char c; cin >> c;
    if(c == 'W') x += k;
    x %= 2 * k;
    y %= 2 * k;
    cell[x][y]++;
  }
//
//  for(int r = -1; r < 2 * k; ++r){
//    for(int c = -1; c < 2 * k; ++c){
//      cout << cell[r][c] << " ";
//    }
//    cout << "\n";
//  }
//

//  cout << "\n\n";

  for(int r = 0; r < 2 * k; ++r){
    for(int c = 0; c < 2 * k; ++c){
      cell[r][c] += (r > 0 ? cell[r - 1][c] : 0)
                  + (c > 0 ? cell[r][c - 1] : 0)
                  - (r * c > 0 ? cell[r - 1][c - 1] : 0);
    }
  }
  
//  for(int r = 0; r < 2 * k; ++r){
//    for(int c = 0; c < 2 * k; ++c){
//      cout << cell[r][c] << " ";
//    }
//    cout << "\n";
//  }
//
  for(int r = 0; r < k; ++r){
    for(int c = 0; c < k; ++c){
      int cur = 0;
      cur += get(0, 0, r, c)
           + get(r + 1, c + 1, r + k, c + k)
           + get(r + k + 1, c + k + 1, 2 * k - 1, 2 * k - 1)
           + get(r + k + 1, 0, 2 * k - 1, c)
           + get(0, c + k + 1, r, 2 * k - 1);
      best = max({best, cur, N - cur});
    }
  }

  cout << best << "\n";
  return 0;
}