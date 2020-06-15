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

int N, t[1005], memo[1005][1005];
vector<int> trace[1005][1005];

int util(int l, int r){
  assert(l < r);
  if(r > N){
    if(l <= N) return t[l];
    return 0;
  }

  int &wait = memo[l][r], x;
  
  if(wait != -1) return wait;
  wait = INF;


  auto &p = trace[l][r];
  p.resize(4);

  x = max(t[l], t[r]) + util(r + 1, r + 2);
  if(wait > x){
    wait = x; 
    p = {l, r, r + 1, r + 2};
  }
  
  if(r + 1 <= N){
    x = max(t[l], t[r + 1]) + util(r, r + 2);
    if(wait > x){
      wait = x;
      p = {l, r + 1, r, r + 2};
    }

    x = max(t[r], t[r + 1]) + util(l, r + 2);
    if(wait > x){
      wait = x;
      p = {r, r + 1, l, r + 2};
    }
  }

  return wait;
}


int main(){
  FAST_IO
  memset(memo, -1, sizeof memo);
  cin >> N;
  for(int rep = 1; rep <= N; ++rep) cin >> t[rep];
  
  cout << util(1, 2) << '\n';

  int l = 1, r = 2;
  vector<int> x;
  while(r <= N){
    x = trace[l][r];

    cout << x[0] << " " << x[1] << '\n';
    l = x[2], r = x[3];
  }

  if(l <= N) cout << l << '\n';

  return 0;
}
