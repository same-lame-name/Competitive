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

int N, M, num[(int)1e6 + 5];
bool opt[5][1005];

int main(){
  FAST_IO
  cin >> N >> M;
  memset(opt, false, sizeof opt);

  for(int rep = 1; rep <= N; ++rep){
    cin >> num[rep];
    num[rep] %= M;
  }

  opt[0][0] = true;

  for(int idx = 1, cur; idx <= N; ++idx){
    cur = idx & 1;
    for(int rep = 0; rep < M; ++rep) opt[cur][rep] = false;

    for(int p = 0, nxt; p < M; ++p){
      if(!opt[!cur][p]) continue;
      opt[cur][p] = true;
      nxt = p + num[idx];

      assert(nxt <= 2 * M - 2);
      if(nxt >= M) nxt -= M;

      if(nxt == 0){
        cout << "YES\n";
        return 0;
      }

      opt[cur][nxt] = true;
    }

  }

  cout << "NO\n";
  return 0;
}

