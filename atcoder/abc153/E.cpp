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

int N, H, val[1005], cst[1005], memo[10005][1005];

int util(int h, int idx){
  if(h <= 0) return 0;
  if(idx < 0) return INF;

  int &cost = memo[h][idx];
  if(cost != -1) return cost;

  cost = util(h, idx - 1);
  min_self(cost, util(h - val[idx], idx) + cst[idx]);

  return cost;
}

int main(){
  FAST_IO
  cin >> H >> N;
  for(int rep = 0; rep < N; ++rep) cin >> val[rep] >> cst[rep];
  memset(memo, -1, sizeof memo);

  cout << util(H, N - 1) << '\n';
  return 0;
}
