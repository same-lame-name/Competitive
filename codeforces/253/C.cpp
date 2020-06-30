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

int N, x, y, X, Y, lim[105];     
queue<pair<int, int>> BFS;
int visited[105][(int)1e5 + 5];

void put(int a, int b, int c, int d){
  if(visited[a][b] <= visited[c][d] + 1) return;
  visited[a][b] = visited[c][d] + 1;
  BFS.push(MP(a, b));

  return;
}

void solve(){
  visited[x][y] = 0;
  BFS.push(MP(x, y));

  while(!BFS.empty()){
    auto cur = BFS.front();
    BFS.pop();

    int a = cur.F, b = cur.S;
    if(a == X && b == Y) goto out;

    put(a - 1, min(b, lim[a - 1]), a, b);
    put(a + 1, min(b, lim[a + 1]), a, b);
    put(a, b - 1, a, b);
    put(a, b + 1, a, b);
    
  }

  out:

  cout << visited[X][Y] << '\n';
  return;
}
  

int main(){
  FAST_IO

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  cin >> N;
  for(int rep = 1; rep <= N; ++rep){
    cin >> lim[rep];
    lim[rep]++;
    for(int c = 1; c <= lim[rep]; ++c) visited[rep][c] = INF;
  }

  cin >> x >> y >> X >> Y;
  solve();
  return 0;
}

