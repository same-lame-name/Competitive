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

int N, M, k, val[1005][1005], row[1005], col[1005];

int main(){
  FAST_IO
  cin >> N >> M >> k;
  for(int r = 1; r <= N; ++r){
    for(int c = 1; c <= M; ++c){
      cin >> val[r][c];
    }
  }

  for(int r = 1; r <= N; ++r) row[r] = r;
  for(int c = 1; c <= M; ++c) col[c] = c;

  for(int rep = 0, x, y; rep < k; ++rep){
    char op;
    cin >> op >> x >> y;
    if(op == 'g') cout << val[row[x]][col[y]] << '\n';
    else if(op == 'r') swap(row[x], row[y]);
    else swap(col[x], col[y]);
  }

  return 0;
}
