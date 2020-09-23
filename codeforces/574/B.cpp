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

int N, M, degree[4005], opt = INF;
bool know[4005][4005];
vector<pair<int, int>> edges;

int main(){
  FAST_IO
  memset(know, false, sizeof know);
  cin >> N >> M;
  for(int rep = 0, x, y; rep < M; ++rep){
    cin >> x >> y;
    know[y][x] = true;
    know[x][y] = true;
    degree[x]++;
    degree[y]++;
    edges.PB(MP(x, y));
  }

  for(pair<int, int> edge : edges){
    int x = edge.F, y = edge.S;
    for(int third = 1; third <= N; ++third){
      if(know[x][third] && know[y][third]){
        assert(degree[x] >= 2 && degree[y] >= 2 && degree[third] >= 2);
        min_self(opt, degree[x] + degree[y] + degree[third]);
      }
    }
  }

  if(opt == INF) cout << "-1\n";
  else cout << opt - 6 << '\n';
  return 0;
}

