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

int K, dist[(int)1e5 + 5];
deque<int> BFS;

int main(){
  FAST_IO
  cin >> K;

  for(int rep = 0; rep < K; ++rep) dist[rep] = INF;
  dist[1] = 1;
  BFS.push_back(1);

  while(!BFS.empty()){
    int cur = BFS.front();
    BFS.pop_front();

    int nxt = (cur + 1) % K;
    if(dist[nxt] > dist[cur] + 1){
      dist[nxt] = dist[cur] + 1;
      BFS.push_back(nxt);
    }

    nxt = (cur * 10) % K;
    if(dist[nxt] > dist[cur]){
      dist[nxt] = dist[cur];
      BFS.push_front(nxt);
    }
  }

  cout << dist[0] << '\n';
  return 0;
}
