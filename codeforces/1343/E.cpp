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
//const int INF = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = (1e-9);

const LL INF = 1e18 + 7;


int testcases, N, M, a, b, c, dis[(int)2e5 + 7][5];
vector<vector<int>> adj;
LL opt, cost[(int)2e5 + 7];
queue<int> util, mt;

void BFS(int n, int id){
  vector<bool> visited(N + 1, false);
  dis[n][id] = 0;
  visited[n] = true;
  util = mt;

  util.push(n);
  while(!util.empty()){
    int cur = util.front();
    util.pop();
    
    for(int ele : adj[cur]){
      if(visited[ele]) continue;
      visited[ele] = true;
      dis[ele][id] = dis[cur][id] + 1;
      util.push(ele);
    }

  }

  return;
}



void solve(){
  opt = INF;

  BFS(a, 0);
  BFS(b, 1);
  BFS(c, 2);

  for(int n = 1, da, db, dc; n <= N; ++n){
    da = dis[n][0], db = dis[n][1], dc = dis[n][2];
    if(da + db + dc > M) continue;

    min_self(opt, cost[db] + cost[da + db + dc]);
  }
 
  cout << opt << '\n';
  return;
}

int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> N >> M >> a >> b >> c;
    adj.clear();
    adj.resize(N + 1);
    for(int rep = 1; rep <= M; ++rep) cin >> cost[rep];
    memset(dis, 0, sizeof dis);

    for(int rep = 0, x, y; rep < M; ++rep){
      cin >> x >> y;
      adj[x].PB(y);
      adj[y].PB(x);
    }

    sort(cost + 1, cost + M + 1);
    for(int rep = 1; rep <= M; ++rep){
      cost[rep] += cost[rep - 1];
    }

    solve();
  }

  return 0;
}
