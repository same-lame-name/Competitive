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

int once[(int)1e5 + 5], testcases;
pair<int, int> infi[(int)1e5 + 5];
LL cur, opt, N, m;

void solve(){
  cur = opt = 0;

  sort(once, once + m, [](int x, int y){ return x > y; });
  sort(infi, infi + m, [](auto x, auto y){ return x.F > y.F; });

  for(int idx = 0, lft = 0, b, a; idx < m; ++idx){
    b = infi[idx].F, a = infi[idx].S;
    while(lft < min(N, m) && once[lft] > b){
      cur += once[lft];
      lft++;
    }

    if(N - lft > 0 && a > b) max_self(opt, cur + (N - lft) * b);
    else if(N - lft > 1) max_self(opt, cur + (N - lft - 1) * b + a);
  }
  
  if(N <= m){
    cur = 0;
    for(int idx = 0; idx < N; ++idx) cur += once[idx];
    max_self(opt, cur);
  }

  cout << opt << '\n';
  return;
}

int main(){
  FAST_IO
  cin >> testcases;
  while(testcases--){
    cin >> N >> m;
    for(int idx = 0, x, y; idx < m; ++idx){
      cin >> x >> y;
      once[idx] = x;
      infi[idx] = MP(y, x);
    }

    solve();
  }
  return 0;
}

