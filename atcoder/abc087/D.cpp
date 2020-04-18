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


int main(){
  FAST_IO  
  
  int N, M; cin >> N >> M;
  vector<vector<pair<int, int>>> graph(N + 1);
  vector<int> tag(N + 1, -1);
  vector<bool> visited(N + 1, false);

  function<bool(int, int)> check;
  check = [&](int node, int name){
    if(!visited[node]) tag[node] = name;
    else if(tag[node] == name) return true;
    else return false;

    visited[node] = true;

    for(auto ele : graph[node]){
      int child = ele.F, cost = ele.S;
      if(!check(child, tag[node] + cost)) return false;
    }

    return true;
  };
    


//  auto print = [&](){
//    for(int idx = 1; idx <= N; ++idx) cout << tag[idx] << "   ";
//    cout << "\n\n";
//  };

  for(int rep = 0; rep < M; ++rep){
    int left, right, cost;
    cin >> left >> right >> cost;
    graph[left].EB(right, cost);
    graph[right].EB(left, -1 * cost);
  }

  for(int node = 1; node <= N; ++node){
    if(visited[node]) continue;
    if(!check(node, 0)){
      cout << "No\n";
      return 0;
    }
  }

  cout << "Yes\n";
  return 0;
}