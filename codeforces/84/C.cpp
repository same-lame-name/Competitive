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

int N, M, cnt = 0;
vector<array<int, 3>> cir;
vector<int> shot;

bool check(int ok, int x, int y, int rep){
  int centre = cir[ok][0], radius = cir[ok][1], num = cir[ok][2];
  if(shot[num] != -1) return false;

  if(y * y + (centre - x) * (centre - x) <= radius * radius){
    shot[cir[ok][2]] = rep;
    return true;
  }

  return false;
}

void solve(){
  cin >> M;
  for(int rep = 1, x, y; rep <= M; ++rep){
    cin >> x >> y;

    // ok points to the circle to the immediate left of point (x, y)
    int left = 0, right = N - 1, ok = -1;
    while(left <= right){
      int mid = left + (right - left) / 2;
      if(x >= cir[mid][0]){
        ok = mid;
        left = mid + 1;
      }else right = mid - 1;
    }


    // check if the immediate left circle contains the point (x, y)
    if(ok >= 0) cnt += check(ok, x, y, rep);
    // check if the immediate right circle contains the point (x, y)
    if(ok + 1 < N) cnt += check(ok + 1, x , y, rep); 
  }

  cout << cnt << '\n';
  for(int idx = 0; idx < N; ++idx) cout << shot[idx] << " ";
  return;
}
  

int main(){
  FAST_IO
  cin >> N;
  shot.resize(N, - 1);
  for(int rep = 0, c, r; rep < N; ++rep){
    cin >> c >> r;
    cir.PB({c, r, rep});
  }

  sort(ALL(cir));

  solve();
  return 0;
}

