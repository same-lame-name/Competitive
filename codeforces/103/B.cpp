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

int N, M, components, parent[105];

int find(int x){
  if(parent[x] == x) return x;
  return parent[x] = find(parent[x]);
}

int main(){
  FAST_IO
  cin >> N >> M;
  components = N;

  for(int idx = 1; idx <= N; ++idx) parent[idx] = idx;

  for(int rep = 0, x, y; rep < M; ++rep){
    cin >> x >> y;
    x = find(x), y = find(y);
    if(x == y) continue;
    parent[y] = x;
    components--;
  }

  if(N >= 3 && N == M && components == 1) cout << "FHTAGN!\n";
  else cout << "NO\n";
  return 0;
}

