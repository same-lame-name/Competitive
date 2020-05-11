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

int N, M, target;
int key[(int)1e3 + 5], cost[(int)1e3 + 5], memo[(int)1e3 + 5][(int)(1 << 12)];

int util(int idx, int mask){
  if(idx < 0) return (mask == target ? 0 : INF);
    
  int &ret = memo[idx][mask];
  if(ret != -1) return ret;

  ret = INF;
  min_self(ret, util(idx - 1, mask));
  min_self(ret, util(idx - 1, mask | key[idx]) + cost[idx]);

  return ret;
}

int main(){
  FAST_IO  
  memset(memo, -1, sizeof memo);
  cin >> N >> M;
  target = (1 << N) - 1;

  for(int rep = 0, b; rep < M; ++rep){
    int mask = 0;
    cin >> cost[rep] >> b;
    for(int itr = 0, w; itr < b; ++itr){
      cin >> w;
      mask |= (1 << (w - 1));
    }

    key[rep] = mask;
  }

  cout << (util(M - 1, 0) == INF ? -1 : util(M - 1, 0)) << '\n';
  return 0;
}