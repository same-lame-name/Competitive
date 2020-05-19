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

pair<int, int> pos[55], check[55];

int main(){
  FAST_IO
  int N, M;
  cin >> N >> M;

  for(int rep = 0, x, y; rep < N; ++rep){
    cin >> x >> y;
    pos[rep] = MP(x, y);
  }

  for(int rep = 1, x, y; rep <= M; ++rep){ 
    cin >> x >> y;
    check[rep] = MP(x, y);
  }

  for(int rep = 0, dis, idx, X, Y; rep < N; ++rep){
    dis = idx = INF;
    X = pos[rep].F, Y = pos[rep].S;

    for(int ck = 1, x, y; ck <= M; ++ck){
      x = check[ck].F, y = check[ck].S;
      if(abs(X - x) + abs(Y - y) < dis){
        dis = abs(X - x) + abs(Y - y);
        idx = ck;
      }
    }

    cout << idx << '\n';
  }
      
  return 0;
}
