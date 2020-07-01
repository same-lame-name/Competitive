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

int N, M;
bool ok[1005];

int main(){
  FAST_IO
  memset(ok, true, sizeof ok);
  cin >> N >> M;
  for(int rep = 0, x, y; rep < M; ++rep){
    cin >> x >> y;
    ok[x] = ok[y] = false;
  }

  int star = 1;
  while(!ok[star]) star++;
  assert(star <= N);

  cout << N - 1 << '\n';
  for(int node = 1; node <= N; ++node){
    if(node == star) continue;
    cout << star << " " << node << '\n';
  }
  return 0;
}

