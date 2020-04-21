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
  
  int h, w, d; cin >> h >> w >> d;

  pair<int, int> pts[90001];
  int prefS[90001];

  memset(prefS, 0, sizeof prefS);
  for(int row = 1; row <= h; ++row){
    for(int col = 1; col <= w; ++col){
      int x; cin >> x;
      pts[x] = MP(row, col);
    }
  }

  for(int start = d + 1; start <= h * w; ++start){
    prefS[start] = prefS[start - d] + abs(pts[start - d].F - pts[start].F)
                 + abs(pts[start - d].S - pts[start].S);
  }

  int Q; cin >> Q;
  while(Q--){
    int left, right; cin >> left >> right;
    cout << prefS[right] - prefS[left] << "\n";
  }

  return 0;
}