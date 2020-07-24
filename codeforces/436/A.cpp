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

class candy{
  public:
  int height, weight;
  bool used = false;

  candy(int a, int b) : height(a), weight(b){}

  bool operator<(const candy &other){
    return weight > other.weight;
  }
};

int N, x, opt = 0;
array<vector<candy>, 2> info, util;

void solve(){
  for(int start = 0, cnt, reach, move; start <= 1; ++start){
    util = info, cnt = 0, reach = x, move = start;

    again:
    for(candy &cur : util[move]){
      if(cur.used) continue;
      else if(cur.height <= reach){
        reach += cur.weight;
        move = !move;
        cur.used = true;
        cnt++;
        goto again;
      }
    }

    max_self(opt, cnt);
  }

  cout << opt << '\n';
  return;
}


    
int main(){
  FAST_IO
  cin >> N >> x;
  for(int rep = 0, t, h, m; rep < N; ++rep){
    cin >> t >> h >> m;
    info[t].EB(h, m);
  }

  for(auto &t : info) sort(ALL(t));

  solve();
  return 0;
}

